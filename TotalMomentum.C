  ////////////// ITEM 1: Calcular el momento total de cada particula (H1,2,3: particula 1,2,3). PX, PY, PZ representa el momentum y agregar esos valores a un .txt /////////////

#include <iomanip>

void TotalMomentum(){

    //Agregando el Tree
    //Función TChain para abrir una Tree y poder concatenar (sumar) varios de ellos. Note que para que esto sea posible, se debe tener el mismo nombre.
    TChain *Tree_Data = new TChain("PhaseSpaceTree", "");
    Tree_Data->Add("~/topicos_avanzados_computacion/git/respaldo/PhaseSpaceSimulation.root");//Tree_Data puntero en la memoria del tree

    //Crear un archivo root para guardar objetos
    //TString filename = "./Histogramas_Trees.root";
    TFile *Histogramas_Trees = new TFile("Histogramas_Trees.root", "RECREATE"); //"RECREATE" cada vez que se corra el programa se actualiza
    Histogramas_Trees->cd();


    //Proyectar datos en un histograma a partir de datos de la Tree
    //1.1 Proyectando directamente
    //Creando los Histogramas donde el momento lineal de una particula H1_PX_n son variables de la tree
    TH1F *H1_PX_1 = new TH1F("H1_PX_1","", 100, -150000,150000);
    TH1F *H1_PX_2 = new TH1F("H1_PX_2","", 100, -150000,150000);

    Tree_Data->Draw("H1_PX>>H1_PX_1");//>>proyectar H1_PX(dato del tree) en el histograma H1_PX_1

    //1.2 Proyectar a partir del ciclo for
    //las variables Hn_PX, Hn_PY, Hn_PZ apuntan en memoria a los variables respectivas del TREE
    Double_t H1_PX;
    Tree_Data->SetBranchAddress("H1_PX", &H1_PX);
    Double_t H1_PY;
    Tree_Data->SetBranchAddress("H1_PY", &H1_PY);
    Double_t H1_PZ;
    Tree_Data->SetBranchAddress("H1_PZ", &H1_PZ);

    Double_t H2_PX;
    Tree_Data->SetBranchAddress("H2_PX", &H2_PX);
    Double_t H2_PY;
    Tree_Data->SetBranchAddress("H2_PY", &H2_PY);
    Double_t H2_PZ;
    Tree_Data->SetBranchAddress("H2_PZ", &H2_PZ);

    Double_t H3_PX;
    Tree_Data->SetBranchAddress("H3_PX", &H3_PX);
    Double_t H3_PY;
    Tree_Data->SetBranchAddress("H3_PY", &H3_PY);
    Double_t H3_PZ;
    Tree_Data->SetBranchAddress("H3_PZ", &H3_PZ);



    Double_t nEntries = Tree_Data->GetEntries();//obtener el numero de datos totales en el tree

    for (Long64_t jentry = 0; jentry < nEntries; jentry++){
        Tree_Data->GetEntry(jentry);
        H1_PX_2->Fill(H1_PX);//Llenar el histograma H1_PX_2 con los valore de momento H1_PX del Tree

    }



    //Verificar el total de eventos guardado en cada histograma
    Double_t TotalEvents_Histo1 = H1_PX_1->Integral();
    Double_t TotalEvents_Histo2 = H1_PX_2->Integral();

    cout << "El número total de eventos en el Histograma 1 es " << TotalEvents_Histo1 << endl;
    cout << "El número total de eventos en el Histograma 2 es " << TotalEvents_Histo2 << endl;

    Histogramas_Trees->Write();
    Histogramas_Trees->Close();


    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                        ITEM 1: Calcular el momento total de cada particula (H1,2,3: particula 1,2,3)
                                                        PX, PY, PZ representa el momentum y agregar esos valores a un .txt
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/



    ofstream myfile;//inicializar el .txt con datos tageados con su respectivo Hj_Pi
    ofstream dm; //.txt listo para hacer un ifstream, ver los tags en myfile
    myfile.open("datos_de_momento");
    dm.open("datos_de_momento_ifstream");
    float tm[3][50000];//total momentum array: la fila 1 tendra los valores de momento para la particula 1...etc


    /*inicio de los loop donde se calculan los momentos de los primeros 15 eventos para las tres particulas
    los primeros tres ciclos for son solo para el archivo datos_de_momento que contiene solo los primeros
    15 elementos. Para crear el nuevo TREE con los n elementos solo es necesario el 4 ciclo for*/


    //Particula 1
    myfile << "H1_PX" << setw(20) << "H1_PY" << setw(20)<< "H1_PZ" << setw(20) << "Momento Total" << endl;
    for ( int i=0 ; i<=15 ; i++ ){
      Tree_Data->GetEntry(i);//buscar la entrada iesima en el TREE
      tm[0][i]=sqrt(H1_PX*H1_PX+H1_PY*H1_PY+H1_PZ*H1_PZ);//calcular el momento total de la iesima entrada para las tres particulas y agregarlo al array que contiene los valores de los momentos totales
      cout << "El momento total de la particula 1 en la entrada " << i << " es " << tm[0][i] << endl;
      myfile << H1_PX << setw(18) << H1_PY << setw(18) << H1_PZ <<setw(12) << tm[0][i] << endl;
    }

    //Particula 2
    myfile << "\n" << "\n" << "H2_PX" << setw(20) << "H2_PY" << setw(20)<< "H2_PZ" << setw(20) << "Momento Total" << endl;
    for ( int i=0 ; i<=15 ; i++ ){
      Tree_Data->GetEntry(i);
      tm[1][i]=sqrt(H2_PX*H2_PX+H2_PY*H2_PY+H2_PZ*H2_PZ);
      cout << "El momento total de la particula 2 en la entrada " << i << " es " << tm[1][i] << endl;
      myfile << H2_PX << setw(20) << H2_PY << setw(20) << H2_PZ <<setw(18) << tm[1][i] << endl;
    }

    //Particula 3
    myfile << "\n" << "\n"  "H3_PX" << setw(20) << "H3_PY" << setw(20)<< "H3_PZ" << setw(20) << "Momento Total" << endl;
    for ( int i=0 ; i<=15 ; i++ ){
      Tree_Data->GetEntry(i);
      tm[2][i]=sqrt(H3_PX*H3_PX+H3_PY*H3_PY+H3_PZ*H3_PZ);
      cout << "El momento total de la particula 3 en la entrada " << i << " es " << tm[2][i] << endl;
      myfile << H3_PX << setw(20) << H3_PY << setw(20) << H3_PZ <<setw(18) << tm[2][i] <<endl;
    }



    //Las tres particulas de un solo, para tener un archivo listo para el ifstream
    for ( int i=0 ; i<50000 ; i++ ){
      Tree_Data->GetEntry(i);
      tm[0][i]=sqrt(H1_PX*H1_PX+H1_PY*H1_PY+H1_PZ*H1_PZ);
      tm[1][i]=sqrt(H2_PX*H2_PX+H2_PY*H2_PY+H2_PZ*H2_PZ);
      tm[2][i]=sqrt(H3_PX*H3_PX+H3_PY*H3_PY+H3_PZ*H3_PZ);
      dm << H1_PX << " " << H1_PY << " " << H1_PZ << " " << tm[0][i] << " " << H2_PX << " " << H2_PY << " " << H2_PZ << " " << tm[1][i] << " " << H3_PX << " " << H3_PY << " " << H3_PZ << " " << tm[2][i] << endl;
    }

  myfile.close();




}

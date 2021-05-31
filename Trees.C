

void Trees(){

    //Agregando el Tree
    //Función TChain para abrir una Tree y poder concatenar (sumar) varios de ellos. Note que para que esto sea posible, se debe tener el mismo nombre.
    TChain *Tree_Data = new TChain("PhaseSpaceTree", "");
    Tree_Data->Add("~/topicos_avanzados_computacion/git/respaldo/PhaseSpaceSimulation2.root");//Tree_Data puntero en la memoria del tree

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
    Tree_Data->SetBranchAddress("H1_PX", &H3_PX);
    Double_t H3_PY;
    Tree_Data->SetBranchAddress("H1_PY", &H3_PY);
    Double_t H3_PZ;
    Tree_Data->SetBranchAddress("H1_PZ", &H3_PZ);





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



    //Calcular el momento total de cada particula (H1,2,3: particula 1,2,3). PX, PY, PZ representa el momentum y agregar esos valores a un .txt
    ofstream myfile;//inicializar el .txt
    myfile.open("datos_de_momento.txt");
    float r; //la variable que contendra el valor del momento total para el ciclo i
    int tm[550]; // array de 16 elementos que contendra los elementos del momento total del elemento i, para la tarea se piden los primeros 15 datos

    //inicio del for
    for ( int i=0 ; i<=500 ; i++ ){
      Tree_Data->GetEntry(i);//buscar la entrada iesima en el TREE
      r = sqrt(H1_PX*H1_PX+H1_PY*H1_PY+H1_PZ*H1_PZ);//calculara el momento total de la iesima entrada
      tm[i]=r;//llenar el array con dicha entrada
      cout << "El momento para la particula" << i << " es " << tm[i] << endl;
      myfile << "H1_PX" << setw(20) << "H1_PY" << setw(20)<< "H1_PZ" << setw(20) << "Momento Total" << endl;
      myfile << H1_PX << setw(20) << H1_PY << setw(20) << H1_PZ <<setw(15) << tm[i] << endl;
  }

  myfile.close();

    //Crear una nueva Tree con las variables de momento total que se acaban de crear
    TFile *f0 =new TFile("datos_de_momento.txt","RECREATE");
    TTree *t0 = new TTree("MT", "Lista con los valores de momento de los primeros 15 elementos de Tree_Data");
    Double_t nv;






    //Trabajo
    //Calcular el momento total de cada particula (H1,2,3: particula 1,2,3). PX, PY, PZ representa el momentum
    //Imprimir en la terminal, para cada particula, el valor de PX,PY,PZ y el total para los primero 15 eventos
    //Imprimir estos valores en un archivo txt, colocando nombre a cada columna y la otra tarea del chat
    //SCRIPT NUEVO QUE CREE UN HISTOGRAMA EN 3D EN FUNCION DE PX,PY,PZ CON LA NUEVA TREE guardar en .ROOT hacer un loop y ver que contenido tiene cada elemento

    //Guardar y Graficar las tres variable de momentum en un histograma en 3 dimensiones (ej. H1_PX. H1_PY, H1_PZ)
    //Hacer un loop for y accesar al binContent del histograma 3D e imprimirlo en la terminal
    //Ej. cout << "El contenido del bin" << << "es " << endl;
    //Comando útiles
    //Int_t NbinsX = Histo->GetNbinsX();, lo mismo para Y, Z
    // Int_t bin = Histo3D->GetBin(i,j,k); i,j,k son indices dummy para hacer loops en el total del bins.
    //Double_t d1_val_data = Histo->GetBinContent(bin);
    //Double_t d1_val_MC = d1_hhh_MC->GetBinError(bin);
    //Grafique el valor obtenido en cada bin en un histograma 1D

    //SCRIPT NUEVO QUE CREE UN HISTOGRAMA EN 3D EN FUNCION DE PX,PY,PZ CON LA NUEVA TREE

}

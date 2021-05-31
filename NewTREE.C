/*ITEM 2:generar un nuevo TREE con los 15 items del .txt generado del Tree_Data...
era con los 50k XD*/

/*Al menos sirve para generar un nuevo TREE de un .txt*/



    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                        ITEM 2: Crear una nueva TREE
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

void NewTREE(){

  /*DOS MANERAS PARA CREAR EL NUEVO TREE(QUE SOLO TENGA LOS DATOS NECESARIOS COMO MOMENTO TOTAL, PX,PY,PZ)
  1.0 A PARTIR DEL .TXT creado EN EL SCRIPT TotalMomentum.C
  1.1 CREANDO OTRO TREE DE UN SOLO DESDE EL TREE ORIGINAL Tree_Data*/



  //1.0 A PARTIR DEL .TXT creado EN EL SCRIPT TotalMomentum.C

  //leyendo el archivo que contiene los datos limpios de momento
  ifstream dm;
  dm.open("datos_de_momento_ifstream");
  Double_t H1_PX,H2_PX,H3_PX,H1_PY,H2_PY,H3_PY,H1_PZ,H2_PZ,H3_PZ,TM1,TM2,TM3;//variables que contienen los momentos y momentos totales para las tres particulas

  //creando el archivo.root necesario para crear el nuevo TREE
  TFile *f0 =new TFile("datos_de_momento.root","RECREATE");
  //abrir en root asi: root datos_de_momento.root y luego generar un new TBrowser

  //creando el tree que tiene la informacion a utilizar, cada variable del archivo de datos_de_momento.root puede ser un branch del tree
  TTree *t0 = new TTree("TotalMomentum", "Lista con los valores de momento necesarios obtenidos de Tree_Data");
  t0->Branch("H1_PX", &H1_PX);
  t0->Branch("H1_PY", &H1_PY);
  t0->Branch("H1_PZ", &H1_PZ);
  t0->Branch("TM1", &TM1);
  t0->Branch("H2_PX", &H2_PX);
  t0->Branch("H2_PY", &H2_PY);
  t0->Branch("H2_PZ", &H2_PZ);
  t0->Branch("TM2", &TM2);
  t0->Branch("H3_PX", &H3_PX);
  t0->Branch("H3_PY", &H3_PY);
  t0->Branch("H3_PZ", &H3_PZ);
  t0->Branch("TM3", &TM3);





  //como ya conozco el orden de datos_de_momento_ifstream, puedo leer los datos y agregarlos a sus respectivas variables del nuevo TREE
  for(int i=0;i<50000;i++){
    dm >> H1_PX >> H1_PY >> H1_PZ >> TM1 >> H2_PX >> H2_PY >> H2_PZ >> TM2 >> H3_PX >> H3_PY >> H3_PZ >> TM3;//agregar los valores de datos_de_momento_ifstream en cada variable
    cout << H1_PX << " " << H1_PY << " " << H1_PZ << " " << TM1 << " " << H2_PX << " " << H2_PY << " " << H2_PZ << " " << TM2 << " " << H3_PX << " " << H3_PY << " " << H3_PZ << " " << TM3 <<endl;
    t0->Fill();//llenar las branch del TREE t0 con los datos del .txt
  }

    t0->Print();
    f0->Write(); //para que los datos del loop se agreguen en cada branch del datos_de_momento.root y usar el TTREE
    f0->Close();
    dm.close();


    /*

    /1.1 CREANDO OTRO TREE DE UN SOLO DESDE EL TREE ORIGINAL Tree_Data/
    //ot == Tree_Data ; nt == el nuevo tree
    TChain *ot = new TChain("PhaseSpaceTre","");
    ot->Add("~/topicos_avanzados_computacion/git/respaldo/PhaseSpaceSimulation.root");
    TFile *f1 =new TFile("newt.root","RECREATE");
    TTree *nt = new TTree("nt", "Lista con los valores de momento necesarios obtenidos de Tree_Data");

    //Creando las branch del nuevo tree
    Double_t TM1,TM2,TM3;
    nt->Branch("TM1", &TM1);
    nt->Branch("TM2", &TM2);
    nt->Branch("TM3", &TM3);



    //Generando el loop para llenar las branch del nuevo tree
    int n = ot->GetEntries();//obtener el numero de entradas en el tree

    for ( int i=0 ; i<n ; i++ ){
      ot->GetEntry(i);
      TM1=sqrt(H1_PX*H1_PX+H1_PY*H1_PY+H1_PZ*H1_PZ);
      TM2=sqrt(H2_PX*H2_PX+H2_PY*H2_PY+H2_PZ*H2_PZ);
      TM3=sqrt(H3_PX*H3_PX+H3_PY*H3_PY+H3_PZ*H3_PZ);
    }

    nt->Print();
    f1->Write();
    f1->Close();

    */

}

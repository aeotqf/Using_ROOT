
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                    ITEM 3: Hacer un histograma en 2d con los valores de momento total
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/


void NewHisto2D(){

  //Agregando el Tree a usar para el Histo3D
  TChain *t1 = new TChain("TotalMomentum","");
  t1->Add("~/topicos_avanzados_computacion/git/respaldo/datos_de_momento.root");
  TFile *f1 =new TFile("histo2d.root","RECREATE");

  //Canvas para el Histograma 2D
  TCanvas *c0 = new TCanvas("c0","MOMENTOS TOTALES",600,800);
  //TH3F *h0 = new TH3F("h0", "Histo 3D", 5, 0, 700000,5,0, 700000,5,0, 700000);//-15000,15000,-15000,15000,-15000,15000,-15000,15000
  TH2F *h0 = new TH2F("h0", "Histo 2D", 5, 0, 700000,5,0, 700000);

  //Apuntando a los valores totales de momento en el TREE
  Double_t TM1;
  t1->SetBranchAddress("TM1",&TM1);
  Double_t TM2;
  t1->SetBranchAddress("TM2",&TM2);
  Double_t TM3;
  t1->SetBranchAddress("TM3",&TM3);



  //Llenando el histograma 2D con los valores de la TREE
  int n = t1->GetEntries();
  for ( Long64_t i=0 ; i<n ; i++ ){
    t1->GetEntry(i);
    h0->Fill(TM1,TM2);
  }

 //Dibujando el histograma
  h0->Draw();


  /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                      ITEM 4: Acceder al binContent del histo2d, tambien al error y hacer un histo 1d con los datos
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

  //canvas para los histogramas 1D
  TCanvas *c1 = new TCanvas("c1","contenido del bin",600,800);
  c1->Divide(4,1);

  TH1F *h1 = new TH1F("h1", "sumatoria del contenido del bin", 5, 0,70000);
  TH1F *h2 = new TH1F("h2", "sumatoria del error del contenido del bin", 5, 0,70000);
  TH1F *h3 = new TH1F("h3", "Histo 1D contenido del bin", 5, 0,70000);
  TH1F *h4 = new TH1F("h4", "Histo 1D error del contenido del bin", 5, 0,70000);


  Int_t bx = h0->GetNbinsX();
  //Int_t bz = h0->GetNbinsZ();
  Int_t by = h0->GetNbinsY();
  Int_t bin;  //el bin
  Float_t tb; //contenido del bin
  Float_t eb; //error del bin
  Float_t sumtb; //sumatoria del contenido del bin
  Float_t sumeb; //sumatoria de los errores del contenido del bin
  //Float_t tba[25][1={};//array que contiene el contenido del bin
  //Float_t eba[25][1]={};////array que contiene los errores del contenido del bin
  Float_t tba[35]={};//array que contiene el contenido del bin
  Float_t eba[35]={};////array que contiene los errores del contenido del bin


  //obtetniendo el contenido del bin y el error, graficando la sumatoria
  for (int i = 0; i< bx; i++){
      for (int j = 0; j< by; j++){
        //for (int k =1; k<=bz; k++){// para histo 3D
          bin = h0->GetBin(i,j);//el numero de bin no el contenido
          tb = h0->GetBinContent(bin);//el contenido
          tba[bin] = h0->GetBinContent(bin);//array que contiene los valores del contenido del bin
          sumtb += h0->GetBinContent(bin);// para ir sumando el contenido y graficarlo en un histograma
          h1->SetBinContent(bin,sumtb);//Llenar el histograma con los valores del contenido del bin
          eb = h0->GetBinError(bin);
          eba[bin] = h0->GetBinError(bin);//array que contiene los valores de error
          sumeb += h0->GetBinError(bin);// para ir sumando el contenido y graficarlo en un histograma
          h2->SetBinContent(bin,sumeb);//Llenar el histograma con los valores del contenido del bin
          cout << "\nEl contenido del bin " << bin << " del histograma 2D es " << tb << endl; //binContenterror guardarlo en un array y mostrar el array en un histograma
          cout << "El error del bin " << bin << " del histograma 2D es " << eb << endl;
          //cout << bin << endl;
          //cout << tba[bin] << endl;
          //cout << eba[bin] << endl;

        //}

      }
  }

//Histogramas en 1D del contenido y error del contenido del bin
  for (int i=0;i<25;i++) {
    h3->Fill(tba[i]);
    h4->Fill(eba[i]);
    //cout << tba[i] << endl;
    //cout << eba[i] << endl;

  }



  cout << "\nEl numero de bins en " << "x" << " es " << bx << endl;
  cout << "El numero de bins en " << "y" << " es " << by << endl;
  //cout << "El numero de bins en " << "z" << " es " << bz << endl;

  c1->cd(1);
  h1->Draw();
  c1->cd(2);
  h2->Draw();
  c1->cd(3);
  h3->Draw();
  c1->cd(4);
  h4->Draw();


  f1->Write();
  f1->Close();



  }

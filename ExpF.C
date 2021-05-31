/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                    ITEM 5: Escribir una funcion exponencial, graficar la funcion
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/


void ExpF(){

  //Agregando el Tree a usar para el Histo2D
  TChain *t2 = new TChain("TotalMomentum","");
  t2->Add("~/topicos_avanzados_computacion/git/respaldo/datos_de_momento.root");
  TFile *f2 =new TFile("ExpF2d.root","RECREATE");


  //Funcion exponencial
  TF1 *f4 = new TF1("f4","exp([0]+[1]*x)",-10,10);
  f4->SetParameter(0,10);
  f4->SetParameter(1,-5);


  //Canvas e Histogramas

  TCanvas *c4 = new TCanvas("c3","Exp y Momento de la particula 1",800,800);
  c4->Divide(2,1);


  TH2F *h3 = new TH2F("h0", "MOMENTOS 2D", 5, 0, 700000,5,0, 700000);
  TH1F *h4 = new TH1F("h4", "Momento de la particula 1", 5, 0,700000);

  //Apuntando a los valores totales de momento en el TREE
  Double_t TM1;
  t2->SetBranchAddress("TM1",&TM1);
  Double_t TM2;
  t2->SetBranchAddress("TM2",&TM2);
  Double_t TM3;
  t2->SetBranchAddress("TM3",&TM3);




  //Llenando los histogramas con los valores del TREE
  int n = t2->GetEntries();
  for ( Long64_t i=0 ; i<n ; i++ ){
    t2->GetEntry(i);
    h3->Fill(TM1,TM2);
    h4->Fill(TM1);


  }

  //para llenar un histo con valores random de f4
  //for ( int i=0 ; i<1000 ; i++ ){
    //h4->Fill(f4->GetRandom());

  //}


  //Dibujando los histogramas y la funcion exp
  c4->cd(1);
  f4->Draw();
  c4->cd(2);
  h4->Draw();

  TCanvas *c3 = new TCanvas("c4","Momentos 2D",600,800);
  h3->SetLineColor(38);
  h3->SetLineWidth(1);
  h3->GetXaxis()->SetTitle("GeV");
  h3->GetYaxis()->SetTitle("Eventos");
  h3->Draw("lego20");
  TPaveText *text = new TPaveText(.05,.1,.95,.8);
  text->SetTextSize(0.03);
  text->SetFillColor(0);
  text->SetTextAlign(12);
  text->AddText("La correlacion es...");
  text->Draw();


}

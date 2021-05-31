
void HistoBins(){


  TChain *t1 = new TChain("TotalMomentum","");
  t1->Add("~/topicos_avanzados_computacion/git/respaldo/datos_de_momento.root");
  TFile *f1 =new TFile("histobins.root","RECREATE");

  //canvas e histograma
  TCanvas *c1 = new TCanvas("c1","contenido del bin",600,800);
  c1->Divide(2,1);

  TH1F *h1 = new TH1F("h1", "contenido del bin", 100, 0,70000);
  TH1F *h2 = new TH1F("h2", "error del bin", 100, 0,70000);
  TH1F *h0 = new TH1F("h0", "Histo", 5, 0, 700000);


  Double_t TM1;
  t1->SetBranchAddress("TM1",&TM1);
  Double_t TM2;
  t1->SetBranchAddress("TM2",&TM2);
  Double_t TM3;
  t1->SetBranchAddress("TM3",&TM3);




  int n = t1->GetEntries();
  for ( Long64_t i=0 ; i<n ; i++ ){
    t1->GetEntry(i);
    h0->Fill(TM1);
  }


  Int_t bx = h0->GetNbinsX();
  Int_t bin;  //el bin
  Float_t tb; //contenido del bin
  Float_t eb; //error del bin
  Float_t sumtb;
  Float_t sumeb;
  Float_t tba[150]={};
  Float_t eba[150]={};


for (int i=0;i<50;i++) {
  bin = h0->GetBin(i);//el numero de bin no el contenido
  tb = h0->GetBinContent(bin);//el contenido
  tba[i] = h0->GetBinContent(bin);
  eb = h0->GetBinError(bin);
  tba[i] = h0->GetBinContent(bin);
  h1->Fill(tba[i]);
  h2->Fill(eba[i]);

}

c1->cd(1);
h1->Draw();

c1->cd(2);
h2->Draw();

f1->Write();
f1->Close();


}

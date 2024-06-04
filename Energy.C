# include <TRandom.h>
# include <TMath.h>
void GaussianDistribution (Int_t counts){
	TH1F*h1= new TH1F ("h1","Energy Resolution;Energy MeV;frequency",100,90,110);
	TH1F*h2=new TH1F ("h2", "h2 title", 100,90,110);

	TH1F*h3=new TH1F ("h3"," Energy Resolution",100,90,110);
	TRandom r;
	Double_t energy= r.Gaus(100, 2.4/2.35);
	for(Int_t i=0;i<counts; i++){
		Double_t energy= r.Gaus(100, 2.4/2.35);
		h1->Fill(energy);
		Double_t energy2= r.Gaus(95.6, 2.4/2.35);
		h2->Fill(energy2);
	}
	TF1*f1=new TF1("name","[0]*TMath::Gaus(x,[1],[2])+[3]*TMath::Gaus(x,[4],[5])", 90,110);
	TF1*gaus=new TF1("gaus1","gaus",90,110);
	TF1*gaus2=new TF1("gaus2","gaus",90,110);

	h3->Add(h1,h2,1,0.2);
	f1->SetParLimits(1,98,102);
	f1->SetParLimits(2,1,2);
	f1->SetParLimits(4,94,97);
	f1->SetParLimits(5,1,2);
	f1->SetParLimits(0,600,800);
	f1->SetParLimits(3,100,200);
	h3->Fit("name");
	
	h3->GetXaxis()->SetTitle("Energy MeV");
	h3->GetYaxis()->SetTitle("Freqency");
	h3->SetTitle("Energy Resolution");

	gaus->FixParameter(0,f1->GetParameter(0));
	gaus->FixParameter(1,f1->GetParameter(1));
	gaus->FixParameter(2,f1->GetParameter(2));
	gaus2->FixParameter(0,f1->GetParameter(3));
	gaus2->FixParameter(1,f1->GetParameter(4));
	gaus2->FixParameter(2,f1->GetParameter(5));	
	
	gaus->SetLineColor(3);
	gaus2->SetLineColor(6);

	h3->Draw();	
	gaus->Draw("SAME");
	gaus2->Draw("SAME");

	TLegend*leg= new TLegend(0.7,0.5,0.88,0.68);
	leg->AddEntry(f1,"Two Peaks","l");
	leg->AddEntry(gaus,"Contriution A","l");
	leg->AddEntry(gaus2,"Contribution B","l");

	leg->Draw();
}

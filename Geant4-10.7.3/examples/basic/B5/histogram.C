void B30(){
	TCanvas *c1= new TCanvas("c1","",20,20,1000,1000);
	c1->Divide(2,3);
	// you can find the rought drawn graphs of the following by typing  new TBrowser into root.
	// After opening the TBrowser - you can change the bounds of the x-axis of the histogram. The bounds are 	    the two last line of each line of code defining a new TH1F histogram below. 

	TString filename= "~/practice/Geant4-10.7.3/examples/basic/B5/build/B4ntuple.root"; // calling the .root file 
	TFile*f = TFile::Open(filename); // opening the .root file? 

	// naming the histograms that are going to be created and setting their x-axis bounds
	TH1F*h1 = new TH1F("Dc1 Hits","",400,-2,50); 
	TH1F*h2 = new TH1F("Dc2 Hits","",400,-2,70);
	TH1F*h3 = new TH1F("ECEnergy","",400,-20,1200);
	TH1F*h4 = new TH1F("HCEnergy","",400,-5,90);
	TH1F*h5 = new TH1F("Times1","",400,-1,9);
	TH1F*h6 = new TH1F("Times2","",400,-5,300);
	TH1F*h7 = new TH1F("ECEnergyVector","",400,0,200);
	TH1F*h8 = new TH1F("HCEnergyVector","",400,0,200);


	TTreeReader r1("B5", f); // calling the Tree B5 - can be found in the TBrowser
	TTreeReaderValue<int> Dc1Hits (r1, "Dc1Hits"); 
	TTreeReaderValue<Int_t> Dc2Hits (r1, "Dc2Hits");
	TTreeReaderValue<Double_t> ECEnergy (r1, "ECEnergy");
	TTreeReaderValue<Double_t> HCEnergy (r1, "HCEnergy");
	TTreeReaderValue<Double_t> Time1 (r1, "Time1");
	TTreeReaderValue<Double_t> Time2 (r1, "Time2");
	//TTreeReaderValue<Int_t> ECEnergyVector (r1, "ECEnergyVector");
	//TTreeReaderValue<Int_t> HCEnergyVector (r1, "HCEnergyVector");


	// filling the created histograms with the values from the pre-existing histograms in the TBrowser.
	while (r1.Next()){
		h1->Fill(*Dc1Hits);
		h2->Fill(*Dc2Hits);
		h3->Fill(*ECEnergy);
		h4->Fill(*HCEnergy);
		h5->Fill(*Time1);
		h6->Fill(*Time2);
		//h7->Fill(*ECEnergyVector);
		//h8->Fill(*HCEnergyVector);
	}
	// Dc1 Hits histogram parameters
	c1->cd(1);
	h1->GetXaxis()->SetTitle("x-axis");
	h1->GetXaxis()->CenterTitle();
	h1->GetYaxis()->SetTitle("y-axis");
	h1->GetYaxis()->CenterTitle();
	h1->SetTitle("Dc1Hits");
	h1->SetLineColor(kBlue-7);
	h1->Draw();
	
	// Dc2 Hits histogram parameters
	c1->cd(2);
	h2->GetXaxis()->SetTitle("x-axis");
	h2->GetXaxis()->CenterTitle();
	h2->GetYaxis()->SetTitle("y-axis");
	h2->GetYaxis()->CenterTitle();
	h2->SetTitle("Dc2Hits");
	h2->SetLineColor(kViolet-4);
	h2->Draw();

	// EC energy histogram parameters
	c1->cd(3);
	h3->GetXaxis()->SetTitle("x-axis");
	h3->GetXaxis()->CenterTitle();
	h3->GetYaxis()->SetTitle("y-axis");
	h3->GetYaxis()->CenterTitle();
	h3->SetTitle("EC Energy");
	h3->SetLineColor(kTeal-8);
	h3->Draw();

	// HC Energy histogram parameters 
	c1->cd(4);
	h4->GetXaxis()->SetTitle("x-axis");
	h4->GetXaxis()->CenterTitle();
	h4->GetYaxis()->SetTitle("y-axis");
	h4->GetYaxis()->CenterTitle();
	h4->SetTitle("HC Energy");
	h4->SetLineColor(kRed-7);
	h4->Draw();

	// Time 1 histogram parameters
	c1->cd(5);
	h5->GetXaxis()->SetTitle("x-axis");
	h5->GetXaxis()->CenterTitle();
	h5->GetYaxis()->SetTitle("y-axis");
	h5->GetYaxis()->CenterTitle();
	h5->SetTitle("Time 1");
	h5->SetLineColor(kCyan-6);
	h5->Draw();

	// Time 2 histogram parameters
	c1->cd(6);
	h6->GetXaxis()->SetTitle("x-axis");
	h6->GetXaxis()->CenterTitle();
	h6->GetYaxis()->SetTitle("y-axis");
	h6->GetYaxis()->CenterTitle();
	h6->SetTitle("Time 2");
	h6->SetLineColor(kPink+6);
	h6->Draw();

	/*c1->cd(7);
	h7->GetXaxis()->SetTitle("x-axis");
	h7->GetYaxis()->SetTitle("y-axis");
	h7->SetTitle("EC Energy Vector");
	h7->Draw();*/

	//c1->cd(8);
	//h8->GetXaxis()->SetTitle("x-axis");
	//h8->GetYaxis()->SetTitle("y-axis");
	//h8->SetTitle("HC Energy Vector");
	//h8->Draw();

}

void plot(){

// Setting up the canvas
	TCanvas *c1 = new TCanvas ("c1", "c1", 100, 0, 0, 180);
	c1 ->Divide(1,1);

// Calling the first file - compton scattering with a proton
 	TFile *proton = new TFile ("~/EvGen/out/5cm/compton_p_300_in.root");
	//Getting scattered theta histogram in degrees 
	TH1F *prt =(TH1F*)proton->Get("h4");
	prt->GetYaxis()->SetRangeUser(0,1900);
	prt->SetLineColor(kRed-5);

// Calling the second file - compton scattering with carbon 
	TFile *carbon = new TFile ("~/EvGen/out/5cm/compton_c_300_in.root");
	//Getting scattered theta histogram in degrees 
	TH1F *car =(TH1F*)carbon->Get("h4");
//	car->GetYaxis()->SetRangeUser(0,1800);
	car->SetLineColor(kCyan-5);

// Calling the third file - compton scattering with tungsten W 
	TFile *tungsten = new TFile ("~/EvGen/out/5cm/compton_w_300_in.root");
	//Getting scattered theta histogram in degrees 
	TH1F *tung =(TH1F*)tungsten->Get("h4");
//	tung->GetYaxis()->SetRangeUser(0,1800);
	tung->SetLineColor(kMagenta-5);

// Calling the fourth file - compton scattering with helium 3
	TFile *helium3 = new TFile ("~/EvGen/out/5cm/compton_he3_300_in.root");
	//Getting scattered theta histogram in degrees 
	TH1F *he3 =(TH1F*)helium3->Get("h4");
//	he3->GetYaxis()->SetRangeUser(0,1800);
	he3->SetLineColor(kGreen-6);

// Calling the fifth file - compton scattering with helium 4
	TFile *helium4 = new TFile ("~/EvGen/out/5cm/compton_he4_300_in.root");
	//Getting scattered theta histogram in degrees 
	TH1F *he4 =(TH1F*)helium4->Get("h4");
//	he4->GetYaxis()->SetRangeUser(0,1200);
	he4->SetLineColor(kRed-+1);

	prt->Draw();
	car->Draw("SAME");
	tung->Draw("SAME");
	he3->Draw("SAME");
	he4->Draw("SAME");

	auto legend = new TLegend (0.6, 0.7, 0.78, 0.9); // setting the size of the legend
	legend ->SetHeader ("The scattered theta angle (in degrees)", "C"); // naming the legend
	//legend ->SetNColumns(1); // list the number of columns that the variable could be listed in 
	
	legend ->AddEntry(prt, "proton","l"); // calling on the value, naming it and indicating it's a line
	legend ->AddEntry(car, "carbon","l");
	legend ->AddEntry(tung, "tungsten","l");
	legend ->AddEntry(he3, "helium 3","l");
	legend ->AddEntry(he4, "helium 4","l");
	legend ->Draw();
}









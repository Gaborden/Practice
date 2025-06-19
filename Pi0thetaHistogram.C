void plot(){

	TCanvas *c1 = new TCanvas ("c1","c1", 100, 0 ,0, 180);
	c1->Divide(1,1);

	TFile *twoPi0= new TFile ("~/practice/simulation/5cm/ARH_Pi0_P_5_200MeV.root");

	TH1F*theta200 =(TH1F*)twoPi0->Get("PHYS_Pi0Theta");
	theta200->GetYaxis()->SetRangeUser(0,1400);
	theta200->SetLineColor(kRed-5);

	TFile*threePi0 = new TFile("~/practice/simulation/5cm/ARH_Pi0_P_5_300MeV.root");

	TH1F*theta300 =(TH1F*)threePi0->Get("PHYS_Pi0Theta");
	theta300->SetLineColor(kOrange-5);

	TFile*fourPi0 = new TFile("~/practice/simulation/5cm/ARH_Pi0_P_5_400MeV.root");

	TH1F*theta400=(TH1F*)fourPi0->Get("PHYS_Pi0Theta");
	theta400->SetLineColor(kYellow-5);

	TFile*fivePi0 = new TFile("~/practice/simulation/5cm/ARH_Pi0_P_5_500MeV.root");

	TH1F*theta500=(TH1F*)fivePi0->Get("PHYS_Pi0Theta");
	theta500->SetLineColor(kTeal-5);

	TFile*sixPi0 = new TFile ("~/practice/simulation/5cm/ARH_Pi0_P_5_600MeV.root");

	TH1F*theta600=(TH1F*)sixPi0->Get("PHYS_Pi0Theta");
	theta600->SetLineColor(kCyan-5);

	TFile*sevenPi0= new TFile ("~/practice/simulation/5cm/ARH_Pi0_P_5_700MeV.root");

	TH1F*theta700=(TH1F*)sevenPi0->Get("PHYS_Pi0Theta");
	theta700->SetLineColor(kMagenta-5);

	TFile*eightPi0= new TFile("~/practice/simulation/5cm/ARH_Pi0_P_5_800MeV.root");

	TH1F*theta800=(TH1F*)eightPi0->Get("PHYS_Pi0Theta");
	theta800->SetLineColor(kPink-5);

	TFile*ninePi0 = new TFile ("~/practice/simulation/5cm/ARH_Pi0_P_5_900MeV.root");

	TH1F*theta900=(TH1F*)ninePi0->Get("PHYS_Pi0Theta");
	theta900->SetLineColor(kViolet-5);

	TFile*tenPi0 = new TFile("~/practice/simulation/5cm/ARH_Pi0_P_5_1000MeV.root");

	TH1F*theta1000=(TH1F*)tenPi0->Get("PHYS_Pi0Theta");
	theta1000->SetLineColor(kBlack-5);

		theta200->Draw();
	theta300->Draw("SAME");
	theta400->Draw("SAME");
	theta500->Draw("SAME");
	theta600->Draw("SAME");
	theta700->Draw("SAME");
	theta800->Draw("SAME");
	theta900->Draw("SAME");
	theta1000->Draw("SAME");

	auto legend = new TLegend (0.6,0.7,0.78,0.9);
	legend ->SetHeader ("The Energy (in MeV)","C");
	legend ->SetNColumns(2);

	legend->AddEntry(theta200, "200","l");
	legend->AddEntry(theta300, "300","l");
	legend->AddEntry(theta400, "400","l");
	legend->AddEntry(theta500, "500","l");
	legend->AddEntry(theta600, "600","l");
	legend->AddEntry(theta700, "700","l");
	legend->AddEntry(theta800, "800","l");
	legend->AddEntry(theta900, "900","l");
	legend->AddEntry(theta1000,"1000","l");
	legend->Draw();


}

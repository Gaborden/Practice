void pi0Efficiency(){
	TCanvas *c1 = new TCanvas ("c1" , "c1", 100, 0 ,0 ,180); 
	c1->Divide(1,1);


	TString EvGen_file2 = ("~/practice/simulation/5cmEG/pi0_p_200_in.root");
	TFile * EvGen2 = TFile::Open(EvGen_file2);

	TString Acqu_file2 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_200MeV.root");
	TFile* Acqu2 =TFile::Open(Acqu_file2);

	TH1F*EvGen_hist2 = (TH1F*)EvGen2->Get("h4");
	TH1F*Acqu_hist2 = (TH1F*)Acqu2->Get("PHYS_Pi0Theta");

	double bin_number2 = 360;
	TH1F *DividedHist2 = new TH1F("", "", bin_number2, 0, 180);
	/*for (int i = 0; i<bin_number2; i++)
	{
		for (int j = 0; j<10; i++)
		DividedHist2->Fill(j);
	}
*/
	DividedHist2->Draw();
	//cout << "Initial DividedHist #Entries: " << DividedHist2->GetEntries() << endl;

	bool division2 = DividedHist2->Divide(Acqu_hist2, EvGen_hist2, 1, 1, "");
	cout << "bool division: " << division2 << endl;
	DividedHist2->SetLineColor(kRed);
	DividedHist2->Draw();

	float final_bin_number = DividedHist2->GetNbinsX();
	float final_entry_number = DividedHist2->GetEntries();
	cout << "final bin number: " << final_bin_number << endl;
	cout << "final entry number: " << final_entry_number << endl;
	
	float sum = 0;
	for (int i = 0; i<final_bin_number; i++)
	{
	float number = DividedHist2->GetBinContent(i);
	sum = sum + number;
	}
	cout << "sum of bin content from the 360 bins: " << sum << endl;

	//300MeV
	TString EvGen_file3 = ("~/practice/simulation/5cmEG/pi0_p_300_in.root");
	TFile * EvGen3 = TFile::Open(EvGen_file3);

	TString Acqu_file3 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_300MeV.root");
	TFile* Acqu3 =TFile::Open(Acqu_file3);

	TH1F*EvGen_hist3 = (TH1F*)EvGen3->Get("h4");
	TH1F*Acqu_hist3 = (TH1F*)Acqu3->Get("PHYS_Pi0Theta");
	
	double bin_number3 = 360;
	TH1F *DividedHist3 = new TH1F("", "", bin_number3, 0, 180);
	for (int i = 0; i<bin_number3; i++)
	{
	int y = 1;
	DividedHist3->Fill(y);
	}
	//cout << "Initial DividedHist #Entries: " << DividedHist2->GetEntries() << endl;

	bool division3 = DividedHist3->Divide(Acqu_hist3, EvGen_hist3, 1, 1, "");
	cout << "bool division: " << division3 << endl;
	DividedHist3->SetLineColor(kOrange);
	DividedHist3->Draw("SAME");
//test
	float final_bin_number3 = DividedHist3->GetNbinsX();
	float final_entry_number3 = DividedHist3->GetEntries();
	cout << "final bin number: " << final_bin_number3 << endl;
	cout << "final entry number: " << final_entry_number3 << endl;
	
	float sum3 = 0;
	for (int i = 0; i<final_bin_number3; i++)
	{
	float number = DividedHist3->GetBinContent(i);
	sum3 = sum3 + number;
	}
	cout << "sum of bin content from the 360 bins: " << sum3 << endl;
//test
	//400MeV
	TString EvGen_file4 = ("~/practice/simulation/5cmEG/pi0_p_400_in.root");
	TFile * EvGen4 = TFile::Open(EvGen_file4);

	TString Acqu_file4 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_400MeV.root");
	TFile* Acqu4 =TFile::Open(Acqu_file4);
	/*TString Acqu_file4 = ("~/practice/simulation/5cm/ARH_Pi0_P_5_400MeV.root");
	TFile* Acqu4 =TFile::Open(Acqu_file4);
	trying to solve bin issue by calling a different file where the bin number was not changed in acqu_root to match that of EvGen, it did not work*/

	TH1F*EvGen_hist4 = (TH1F*)EvGen4->Get("h4");
	TH1F*Acqu_hist4 = (TH1F*)Acqu4->Get("PHYS_Pi0Theta");
	
	
	double bin_number4 = 360;
	TH1F *DividedHist4 = new TH1F("", "", bin_number4, 0, 180);
	for (int i = 0; i<bin_number4; i++)
	{
	int y = 1;
	DividedHist4->Fill(y);
	}

	bool division4 = DividedHist4->Divide(Acqu_hist4, EvGen_hist4, 1, 1, "");
	cout << "bool division: " << division4 << endl;
	DividedHist4->SetLineColor(kYellow-5);
	DividedHist4->Draw("SAME");
//test
	float final_bin_number4 = DividedHist4->GetNbinsX();
	float final_entry_number4 = DividedHist4->GetEntries();
	cout << "final bin number: " << final_bin_number4 << endl;
	cout << "final entry number: " << final_entry_number4 << endl;	
	float sum4 = 0;
	for (int i = 0; i<final_bin_number4; i++)
	{
	float number = DividedHist4->GetBinContent(i);
	sum4 = sum4 + number;
	}
	cout << "sum of bin content from the 360 bins: " << sum4 << endl;
//test
	//500MeV
	TString EvGen_file5 = ("~/practice/simulation/5cmEG/pi0_p_500_in.root");
	TFile * EvGen5 = TFile::Open(EvGen_file5);

	TString Acqu_file5 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_500MeV.root");
	TFile* Acqu5 =TFile::Open(Acqu_file5);

	TH1F*EvGen_hist5 = (TH1F*)EvGen5->Get("h4");
	TH1F*Acqu_hist5 = (TH1F*)Acqu5->Get("PHYS_Pi0Theta");
	
	double bin_number5 = 360;
	TH1F *DividedHist5 = new TH1F("", "", bin_number5, 0, 180);
	for (int i = 0; i<bin_number5; i++)
	{
	int y = 1;
	DividedHist5->Fill(y);
	}

	bool division5 = DividedHist5->Divide(Acqu_hist5, EvGen_hist5, 1, 1, "");
	cout << "bool division: " << division5 << endl;
	DividedHist5->SetLineColor(kGreen);
	DividedHist5->Draw("SAME");

	//600MeV
	TString EvGen_file6 = ("~/practice/simulation/5cmEG/pi0_p_600_in.root");
	TFile * EvGen6 = TFile::Open(EvGen_file6);

	TString Acqu_file6 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_600MeV.root");
	TFile * Acqu6 = TFile::Open(Acqu_file6);

	TH1F* EvGen_hist6 = (TH1F*)EvGen6->Get("h4");
	TH1F* Acqu_hist6 = (TH1F*)Acqu6->Get("PHYS_Pi0Theta");

	double bin_number6 =360;
	TH1F *DividedHist6 = new TH1F("","",bin_number6, 0 ,180);
	for (int i =0; i<bin_number6; i++){
		int y = 1;
		DividedHist6->Fill(y);
	}

	bool division6 =DividedHist6->Divide(Acqu_hist6, EvGen_hist6, 1, 1, "");
	cout <<"bool division: " << division6 << endl;
	DividedHist6->SetLineColor(kTeal);
	DividedHist6->Draw("SAME");

	//700MeV
	TString EvGen_file7 = ("~/practice/simulation/5cmEG/pi0_p_700_in.root");
	TFile * EvGen7 = TFile::Open(EvGen_file7);

	TString Acqu_file7 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_700MeV.root");
	TFile * Acqu7 = TFile::Open(Acqu_file7);

	TH1F* EvGen_hist7 = (TH1F*)EvGen7->Get("h4");
	TH1F* Acqu_hist7 = (TH1F*)Acqu7->Get("PHYS_Pi0Theta");

	double bin_number7 =360;
	TH1F *DividedHist7 = new TH1F ("","", bin_number7, 0 ,180);
	for (int i=0; i< bin_number7; i++){
		int y = 1;
		DividedHist7->Fill(y);
	}

	bool division7 = DividedHist7->Divide(Acqu_hist7, EvGen_hist7, 1, 1, "");
	cout << "bool division: " << division7 << endl;
	DividedHist7->SetLineColor(kBlue);
	DividedHist7->Draw("SAME");

	//800MeV
	TString EvGen_file8 = ("~/practice/simulation/5cmEG/pi0_p_800_in.root");
	TFile *EvGen8 = TFile::Open(EvGen_file8);

	TString Acqu_file8 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_800MeV.root");
	TFile* Acqu8 = TFile::Open(Acqu_file8);

	TH1F* EvGen_hist8 = (TH1F*)EvGen8->Get("h4");
	TH1F* Acqu_hist8 = (TH1F*)Acqu8->Get("PHYS_Pi0Theta");

	double bin_number8 = 360;
	TH1F *DividedHist8 = new TH1F ("","", bin_number8, 0, 180);
	for (int i=0; i< bin_number8; i++){
		int y =1;
		DividedHist8->Fill(y);
	}
	
	bool division8 = DividedHist8->Divide(Acqu_hist8, EvGen_hist8, 1 ,1, "");
	cout << "bool division8: "<<division8 <<endl;
	DividedHist8->SetLineColor(kMagenta);
	DividedHist8->Draw("SAME");

	//900MeV
	TString EvGen_file9 = ("~/practice/simulation/5cmEG/pi0_p_900_in.root");
	TFile*EvGen9 = TFile::Open(EvGen_file9);

	TString Acqu_file9 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_900MeV.root");
	TFile*Acqu9 = TFile::Open(Acqu_file9);

	TH1F*EvGen_hist9 = (TH1F*)EvGen9->Get("h4");
	TH1F*Acqu_hist9 = (TH1F*)Acqu9->Get("PHYS_Pi0Theta");

	double bin_number9 = 360;
	TH1F *DividedHist9 = new TH1F("","", bin_number9, 0 ,180);
	for (int i=0; i< bin_number9; i++){
		int y =1;
		DividedHist9->Fill(y);
	}
	
	bool division9 = DividedHist9->Divide(Acqu_hist9, EvGen_hist9, 1, 1, "");
	cout << "bool division9: " << division9 <<endl;
	DividedHist9->SetLineColor(kPink);
	DividedHist9->Draw("SAME");

	//1000MeV
	TString EvGen_file10 = ("~/practice/simulation/5cmEG/pi0_p_1000_in.root");
	TFile*EvGen10 = TFile::Open(EvGen_file10);
	
	TString Acqu_file10 = ("~/practice/simulation/detectorEfficiency/ARH_Pi0_P_5_1000MeV.root");
	TFile*Acqu10 = TFile::Open(Acqu_file10);

	TH1F*EvGen_hist10 = (TH1F*)EvGen10->Get("h4");
	TH1F*Acqu_hist10 = (TH1F*)Acqu10->Get("PHYS_Pi0Theta");

	double bin_number10 =360;
	TH1F* DividedHist10 = new TH1F ("","", bin_number10, 0, 180);
	for (int i =0; i< bin_number10; i++){
		int y = 1;
		DividedHist10->Fill(y);
	}
	
	bool division10 = DividedHist10->Divide(Acqu_hist10, EvGen_hist10, 1,1, "");
	cout<< "bool division10: " << division10 <<endl;
	DividedHist10->SetLineColor(kViolet);
	DividedHist10->Draw("SAME");
	
	//legend
	auto legend = new TLegend (0.6, 0.7,0.78,0.9);
	legend ->SetHeader("The Energy (in MeV)", "C");
	legend ->SetNColumns(2);

	legend->AddEntry(DividedHist2, "200","1");
	legend->AddEntry(DividedHist3, "300","1");
	legend->AddEntry(DividedHist4, "400","1");
	legend->AddEntry(DividedHist5, "500","1");
	legend->AddEntry(DividedHist6, "600","1");
	legend->AddEntry(DividedHist7, "700","1");
	legend->AddEntry(DividedHist8, "800","1");
	legend->AddEntry(DividedHist9, "900","1");
	legend->AddEntry(DividedHist10, "1000","1");
	legend->Draw();
		
}

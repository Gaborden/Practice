void asym(){
	//Subtraction Method
	TFile*evgen = new TFile("~/EvGen/out/5cm/compton0_p_200_in.root");

	TH1F*theta=(TH1F*)evgen->Get("h6");

	Double_t value1 = theta->Integral(theta->FindBin(-10),theta->FindBin(10));
	Double_t value2 = theta->Integral(theta->FindBin(80), theta->FindBin(90));

	Double_t value3 = (1/0.5)*((value2-value1)/(value2+value1));
	cout<<" value 3 "<<value3<<endl;


	//Fit Method
	TF1*f1=new TF1("name","[0]*(1+[1]*cos((2*x+[2])*TMath::DegToRad()))",-180,180);
	theta->Fit(f1);
	cout<<f1->GetParameter(1)/0.5<<endl;	

	//Subtraction-Fit Method
	TFile*evgen90= new TFile("~/EvGen/out/5cm/compton_p_200_in.root");
	TH1F*theta90=(TH1F*)evgen90->Get("h6");
	TH1F*f2= new TH1F ("f2","subtraction",720,-180,180);
	TH1F*f3= new TH1F ("f3","addition",720,-180,180);
	TH1F*f4= new TH1F ("f4","Subtraction-Fit Method",720,-180,180);

	f2->Add(theta,theta90,1,(-1));
	f3->Add(theta,theta90,1,1);
	f4->Divide(f2,f3,1,1);
	
	TF1*f5 = new TF1("name","[0]*cos(2*x*TMath::DegToRad())",-180,180);

	f4->Fit(f5);
	
}

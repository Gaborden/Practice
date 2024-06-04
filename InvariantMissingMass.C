#include <TLorentzVector.h>
#include <TMath.h>
#include <TRandom.h>
#include <TVector3.h>

void mmiss(Int_t n){
	TLorentzVector iph, proton1, mom4;
	TLorentzVector k,p, p1, p4In, p4out;
	TLorentzVector k_cm, p_cm, p1_cm, q_cm;

	Double_t eph = 200; 
	Double_t pm, pe_cm;
	Double_t mp= 938.27;
	Double_t c=1;

	TVector3 cmBoost, labBoost;

	iph.SetPxPyPzE(0,0,eph,eph);
	proton1.SetPxPyPzE(0,0,0,mp);
	
	TH1F*h1= new TH1F("h1","Missing Mass; X-axis; Y-axis",100, 938,939);

	for (Int_t i=0;i<n;i++){

	TF1 *f1 =new TF1("name","29.006-(17.8545*cos(x))+(10.5726*TMath::Power(cos(x),2))",-1,1);

	Double_t theta = f1->GetRandom();

	Double_t f2 =TMath::ACos(theta);
	
	TF1*gaus =new TF1("gaus1","TMath::Gaus(x,0,2.5/2.35)",-10,10);
	Double_t anglesmear = gaus->GetRandom();
	f2+=anglesmear;
	
	Double_t scat = eph/(1+(eph/(mp*c*c))*(1-cos(f2)));

	TF1*smear = new TF1("smear2","TMath::Gaus(x,0,((0.027/TMath::Power(0.2,0.25))/2.35))",-10,10);
	Double_t esmear= smear->GetRandom();
	scat+=esmear;

	mom4.SetPxPyPzE(scat*sin(f2),0,scat*cos(f2),scat);
	
	p4out= proton1 + iph - mom4;

	Double_t mimas =TMath::Sqrt(p4out.Dot(p4out));
	
	h1->Fill(mimas);
	h1->SetFillColor(7);
	
	}
	h1->Fit("gaus");
	Double_t FWHM= 2.35*(0.07053);
	cout<< "FWHM "<<FWHM<<endl;
	h1->Draw();
}

#include <TMath.h>
#include <TRandom.h>
void TwoBodyMacro(Double_t qe){
	Double_t spe;
	Double_t rike;
	Double_t rpth;
	Double_t mp= 938.27;
	Double_t c=1;
	//spe=qe/(1+(qe/mp*c*c)*(1-TMath::Cos(qth)));
	//Double_t smop=TMath::Sqrt((spe*spe)/c*c);
	//rike=qe+mp*c*c-spe;
	//
	//rpth = TMath::ASin((smop-qe)*TMath::Sin(qth));


	TCanvas *c1 = new TCanvas("c1","c1",100,0,2000,3000);
	c1->Divide(1,3);
	TGraph* g1 = new TGraph();
	TGraph* g2 = new TGraph();
	TGraph* g3 = new TGraph();

	for (int qth=0; qth<180; qth++){
		spe=qe/(1+(qe/(mp*c*c))*(1-TMath::Cos(qth*TMath::Pi()/180)));
		rike=qe-spe;
		Double_t smop=TMath::Sqrt((spe*spe)/c*c);
		rpth=TMath::ASin((smop-qe)*TMath::Sin(qth*TMath::Pi()/180)*TMath::Pi()/180);
		//Graph of the third one is most likley incorrect, kept getting stuck with the math

		g1->AddPoint(qth, spe);
		g2->AddPoint(qth, rike);
		g3->AddPoint(qth, rpth);
	}

	c1->cd(1);
	g1->GetXaxis();
	g1->GetYaxis();
	g1->SetTitle("Scattered Photon Energy");
	g1->Draw("ALP");
		
	c1->cd(2);
	g2->GetXaxis();
	g2->GetYaxis();
	g2->SetTitle("Recoil Proton K.E.");
	g2->Draw("ALP");

	c1->cd(3);
	g3->GetXaxis();
	g3->GetYaxis();
	g3->SetTitle("Recoil Proton Angle");
	g3->Draw("ALP");

}

void photon(Double_t x, Double_t th){
	Double_t t = 45*TMath::Pi()/180;
	Double_t c=1;
	Double_t kx=x/c;
	Double_t mp=938.27/(c*c);
	Double_t eph=x;

	//calculated beta and gamma with lorentz transformations
	Double_t beta=kx*c/(mp*c*c+eph);
	Double_t gamma= 1/(TMath::Sqrt(1-(beta*beta)));
	Double_t v=beta*c;
	cout<<"beta"<<beta<<endl;
	cout<<"gamma"<<gamma<<endl;

	// CM Values for the scattered photon and recoil proton
	Double_t eph1= gamma*(eph-v*kx);
	Double_t kx1=eph1/c;
	Double_t epr= 938.27;
	Double_t px=0;
	Double_t epr1=gamma*(epr-v*px);
	Double_t px1=gamma*(px-v*eph/(c*c));
	cout<<"eph1"<<eph1<<endl;
	cout<<"epr1"<<epr1<<endl;
	cout<<"px1"<<px1<<endl;

	//calculated components of the scattered photon momentum and recoil proton
	//scattered photon
	Double_t esph= eph/(1+(eph/(mp*c*c))*(1-TMath::Cos(t)));
	Double_t q1=esph/c;
	Double_t q1x=q1*TMath::Cos(t);
	Double_t q1y=q1*TMath::Sin(t);
	cout<<"esph"<<esph<<endl;
	cout<<"q1"<<q1<<endl;
	cout<<"q1x"<<q1x<<endl;
	cout<<"q1y"<<q1y<<endl;
	//recoil proton
	Double_t pf1x=kx-q1x;
	Double_t pf1y=-q1y;
	Double_t p1f= TMath::Sqrt(pf1x*pf1x+pf1y*pf1y);
	Double_t epr1f= TMath::Sqrt(c*c*p1f*p1f+mp*mp*c*c*c*c);
	cout<<"pf1x"<<pf1x<<endl;
	cout<<"pf1y"<<pf1y<<endl;
	cout<<"p1f"<<p1f<<endl;
	cout<<"epr1f"<<epr1f<<endl;

	//find lab momenta and energies of the two final state particles using lorentz transformations
	Double_t ephf=gamma*(esph-v*q1x);
	Double_t qfx=gamma*(pf1x-v*epr/(c*c));
	Double_t qfy=q1y;
	Double_t pfy=-q1y;
	Double_t pfx= gamma*(pf1x-v*epr1f/(c*c));
	Double_t eprf = gamma*(epr1f-v*pf1x);
	Double_t prpf = TMath::Sqrt(pfx*pfx + pfy*pfy);
	Double_t phqf = TMath::Sqrt(qfx*qfx + qfy*qfy);
	cout<<"ephf"<<ephf<<endl;
	cout<<"eprf"<<eprf<<endl;
	cout<<"prpf"<<prpf<<endl;
	cout<<"phqf"<<phqf<<endl;

}


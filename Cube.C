void Cube(Int_t n){
	TRandom r;
	TH3F* h=new TH3F ("h","Random Sampling for Cube;X Axis;Y axis; z axis",100,0,1,100,0,1,100,0,1);
	for(int i=0;i<n;i++){
		Double_t x= r.Rndm();
		Double_t y= r.Rndm();
		Double_t z= r.Rndm();
		h->Fill(x,y,z);
	}
	h->Draw();

}


void Cube2 (Int_t n){
	TRandom r;
	TH2F* h=new TH2F ("h", "Random Sampling for Cube; X Axis; Y Axis",100,0,1,100,0,1);
	for (int i=0; i<n;i++){
		Double_t x= r.Rndm();
		Double_t y= r.Rndm();
		h->Fill(x,y);
	}
	h->Draw();
}


# include <TMath.h>
# include <TRandom.h>
void polar2 (Int_t n){
	TRandom r;
	TH2F* h=new TH2F ("spherical coordinates","Random Sampling for Cube",100,-1,1,100,-1,1);
	for (int i=0; i<n;i++){
		Double_t R = r.Rndm();
		Double_t th = r.Rndm()*360*TMath::DegToRad();
		Double_t x = R*TMath::Sin(th);
		Double_t y = R*TMath::Cos(th); 
		h->Fill(x,y);
	}
	h->Draw();
}
		
void spherical_ (Int_t n){
	TRandom r;
	TH2F* h=new TH2F ("polar coordinates","Random Sampling for circle",100,-1,1,100,-1,1);
	for (int i=0; i<n;i++){
		Double_t R = TMath::Sqrt( r.Rndm());
		Double_t th = r.Rndm()*360*TMath::DegToRad();
		Double_t x = R*TMath::Sin(th);
		Double_t y = R*TMath::Cos(th); 
		h->Fill(x,y);
	}
	h->Draw();
}



void spherical3 (Int_t n){
	TRandom r;
	TH3F* h=new TH3F("Spherical Coordinates","Random Sampling for Cube",100,-1,1,100,-1,1,100,-1,1);
	for (int i=0; i<n;i++){
		Double_t R = r.Rndm();
		Double_t th = r.Rndm()*180*TMath::DegToRad();
		Double_t phi = r.Rndm()*360*TMath::DegToRad();
		Double_t x = R*TMath::Sin(th)*TMath::Cos(phi);
		Double_t y = R*TMath::Sin(th)*TMath::Sin(phi);
		Double_t z =R*TMath::Cos(th);
		h->Fill(x,y,z);
	}
	h->Draw();
}

void spherical_3 (Int_t n){
	TRandom r;
	TH3F* h=new TH3F("Spherical Coordinates","Unit Sphere",100,-1,1,100,-1,1,100,-1,1);
	for (int i=0; i<n;i++){
		Double_t R = TMath::Power( r.Rndm(),1/(Double_t)3) ;
		Double_t th = TMath::ACos(2*r.Rndm()-1);
		Double_t phi = r.Rndm()*360*TMath::DegToRad();
		Double_t x = R*TMath::Sin(th)*TMath::Cos(phi);
		Double_t y = R*TMath::Sin(th)*TMath::Sin(phi);
		Double_t z = R*TMath::Cos(th);
		h->Fill(x,y,z);
	}
	h->Draw();
}


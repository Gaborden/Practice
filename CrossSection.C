void crosssection(){
	Double_t Eph=200;
	Double_t deltax=5;
	Double_t A=0.01;
	Double_t r=2;
	Double_t th=45;
	Double_t edet=0.80;
	Double_t N0=TMath::Power(10,9);
	Double_t Y=8;
	Double_t Mh=2.016;
	Double_t rho =0.07;
	Double_t Na=6.022*TMath::Power(10,23);

	Double_t n= (rho*Na)/Mh;
	cout<< "number density "<< n<< endl;

	Double_t t= deltax*n;
	cout<<"thickness "<< t<<endl;

	Double_t sa = A/(r*r);
	cout<< "solid angle "<<sa<<endl;

	Double_t cs = Y/(N0*t*edet*sa);
	cout<<"differential cross section "<<cs<<endl;

}

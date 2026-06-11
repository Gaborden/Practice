void crosssection(){
	// Assume: you have a beam of incident photons with energy 200 MeV incident upon a liquid hydrogen target with thickness (delta)x = 5cm. You place a small detector area A= 0.01 m^2 at a distance of 4=2m from the target at theta= 45 degrees

	//defining parameters 

	Double_t Eph=200; // energy in Mev
	Double_t deltax=5; //physical thickness in cm
	Double_t A=0.01; // detector arean in m^2 
	Double_t r=2;// distance in m 
	Double_t th=45;// angle of the detector with respect to the target in degrees 
	Double_t edet=0.80; // detector efficiency 
	Double_t N0=TMath::Power(10,9); // incident photons launched at the target
	Double_t Y=8; // counts in the detector - number of counts detected 
	Double_t Mh=2.016; // molar mass of hydrogen g/mol
	Double_t rho =0.07; // density of water in g/cm^3
	Double_t Na=6.022*TMath::Power(10,23); // Avogadro's number

	//calculation of the target thickness
	//starting with determining the number density by multiplying the density of water with avogadro's number and dividing it by the molar mass of hydrogen
	Double_t n= (rho*Na)/Mh;
	cout<< "number density "<< n<< endl;
	//determining the "thickness" by multiplying the physical thickness and the number density 
	Double_t t= deltax*n;
	cout<<"thickness "<< t<<endl;

	//Calculate the solid angle (delta)Omega subtended by your detector in sr.
	//dividing the area by the square of the distance of the detector from the target
	Double_t sa = A/(r*r);
	cout<< "solid angle "<<sa<<endl;

	//Now assyme your detector has an efficiency of 0.80, and in an experiment you manage to shoot N_0= 1e9 incident photons at the target. If you detect only Y=8 photons in your detector, what is the differential cross section d(signma)d(Omega)(E(lamda=200 MeV, theta=45) un units of nanobarns (nb)?
	Double_t cs = Y/(N0*t*edet*sa);
	cout<<"differential cross section "<<cs<<endl;

}

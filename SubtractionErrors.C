#include <TMath.h>

void suberrors(){
	Double_t prompt = 1000;
	Double_t random = 2500;
	Double_t widthP = 50;
	Double_t widthR = 250;
	
	Double_t ratio= widthP/widthR;
	cout<<"promt-random ratio: "<<ratio<<endl;

	Double_t yield = prompt -ratio*random;
	cout<<"yield: "<<yield<<endl;

	Double_t deltaP = TMath::Sqrt(prompt);
	Double_t deltaR= TMath::Sqrt(random);
	Double_t error =TMath::Sqrt(deltaP*deltaP + ratio*ratio*(deltaR*deltaR));	cout<<"proper error in the yield: "<<error<<endl;	

	Double_t relative = error/yield;
	cout<<"relative error in the yield: "<<relative<<endl;

	Double_t relativeyield = (TMath::Sqrt(prompt))/prompt;
	cout<< "relative error in the yield ignoring subtraction: "<<relativeyield<<endl;

	//two hour measurement 
	Double_t prompt2 = 2000;
	Double_t random2 = 5000;

	Double_t yield2 = prompt2 -ratio*random2;
	cout<<"yield 2: "<<yield2<<endl;

	Double_t deltaP2 = TMath::Sqrt(prompt2);
	Double_t deltaR2 = TMath::Sqrt(random2);
	Double_t error2 =TMath::Sqrt(deltaP2*deltaP2 + ratio*ratio*(deltaR2*deltaR2));
	cout<< "proper error in the yield 2: "<<error2<<endl;

	Double_t relative2 = error2/yield2;
	cout<<"relative error in the yield2: "<<relative2<<endl;

	Double_t relativeyield2 = (TMath::Sqrt(prompt2))/prompt2;
	cout<< "relative error in the yield ignoring subtraction2: "<<relativeyield2<<endl;	

	//Doubled electron current & double photon flux, with the same prompt-random ratio 
	Double_t prompt3 = 3000;
	Double_t random3= 10000;
	
	Double_t yield3 = prompt3 - ratio*random3;
	cout<<"yield 3: "<<yield3<<endl;

	Double_t deltaP3 = TMath::Sqrt(prompt3);
	Double_t deltaR3 = TMath::Sqrt(random3);
	Double_t error3 = TMath::Sqrt(deltaP3*deltaP3 + ratio*ratio*(deltaR3*deltaR3)); 
	cout<<"proper error in the yield 3: "<<error3<<endl;

	Double_t relative3 = error3/yield3;
	cout<< "relative error in the yield 3: "<<relative3<<endl;

	Double_t relativeyield3 = (TMath::Sqrt(prompt3))/prompt3;
	cout<<"relative error in the yield ignoring subtraction3: "<<relativeyield3<<endl;

}


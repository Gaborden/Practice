// The following is the longer version of the MCvsData0 created by me in late March of 2026 for my thesis, to avoid leaving large portions commented out within the CATSEnergy.C macro (as it includes mutiple methods, I am copying the full version here, it can not run from this file as it is not connected to AR.CATS and it is missing the starting methods that are necessary to analyse certain parameters in this method. 
// April 02 2026 - Genevieve Borden 

void MCvsData0(UInt_t chan){ //Added by gen
//ResResult MCvsData(UInt_t chan)
	//attempting to collect the histogram from void CATSEnergy above
	ProjCATSE(chan);
	TH1D* h_ARH = proj_global;

	//Debugging attempt
 	if (!h_ARH) {
        	std::cerr << "Error: Failed to retrive ProjCATSE!" << std::endl;
        return;	
	}
	
	//To denote the incident photon energy as done in ProjCATSE()	
	UInt_t eg;
	TString name;

	eg = tdata[chan].egamma;

	//calling in the Monte Carlo simulation 
	TFile *f_mc = TFile::Open("ARout/CATS/MC_InBeam.root");
	//Testing error message if Monte Carlo simulation has no plot
	TH1F* h_mc = dynamic_cast<TH1F*>(f_mc ->Get("PHYS_CATSEnergy"));

	if (!h_mc){
		std::cerr << "Error: MC histogram not found!" <<  std::endl;
	}
	
	//Attempting to scale the simulated histogram here:
	int peakBin = h_ARH->GetMaximumBin();
    	double peakCentre = h_ARH->GetBinCenter(peakBin);

	//trying something else to fix smearing 
//	TF1 *g_data = new TF1("g_data", "gaus", peakCentre - 100, peakCentre + 100);
//	h_ARH->Fit(g_data, "RQ");

//	TF1 *g_mc = new TF1("g_mc", "gaus", peakCentre - 100, peakCentre + 100);
//	h_mc->Fit(g_mc, "RQ");

//	double sigma_data = g_data->GetParameter(2);
//	double sigma_mc   = g_mc->GetParameter(2);
	//this should tell us how its being fitted
//	std::cout << "Data sigma (fit) = " << sigma_data << std::endl;
//	std::cout << "MC sigma (fit)   = " << sigma_mc << std::endl;

	//double sigma_extra = 0.0;

	//if (sigma_data > sigma_mc) {
    	//	sigma_extra = sqrt(sigma_data*sigma_data - sigma_mc*sigma_mc);
	//} else {
   	 //sigma_extra = 0.0; // don't "unsmear"
	//}
	//this should tell us how varied the smearing parameter is 
	//std::cout << "Extra smearing needed = " << sigma_extra << std::endl;

	//attempting to plot with axes from peak +/- 20% intergration regions 
	double frac = 0.10; // 20%

	double xmin = peakCentre * (1.0 - frac);
	double xmax = peakCentre * (1.0 + frac);

	//width for integration
	//double width = 70.0; //this should be a flexible parameter (I think) 
	//
	//double xmin = peakCentre - width;
	//double xmax = peakCentre + width;
	//
	//another attempt for scaling
	//double sigma = h_ARH->GetRMS();

	//double xmin = peakCentre - 3.0 * sigma;
	//double xmax = peakCentre + 3.0 * sigma;	

    	//double mc_int = h_mc->Integral(bin_min, bin_max);

	int data_bin_min = h_ARH->FindBin(xmin);
	int data_bin_max = h_ARH->FindBin(xmax);
	
    	double data_int = h_ARH->Integral(data_bin_min, data_bin_max);

	int mc_bin_min = h_mc->FindBin(xmin);
	int mc_bin_max = h_mc->FindBin(xmax);

	double mc_int = h_mc->Integral(mc_bin_min, mc_bin_max);

	//Scaling the histogram: 
	TH1F* h_mc_scaled = nullptr; 
	if (mc_int > 0) {
    		double scale = data_int / mc_int;
    		h_mc_scaled = (TH1F*)h_mc->Clone("h_mc_scaled");
    		h_mc_scaled->Scale(scale);
    		std::cout << "Scaling MC by factor: " << scale << std::endl;
		} 
	else {
   	 	std::cerr << "Error: MC integral is zero in selected region!" << std::endl;
	}

	
	TCanvas *c = new TCanvas("c_comapre", "Data vs Simulation", 800, 600);
	
	//Style for ARH
	h_ARH->SetMarkerStyle(20);
	h_ARH->SetMarkerColor(kRed);
	h_ARH->SetLineWidth(0);
	//Style for MC
	if (h_mc_scaled){ 
		//h_mc_scaled->SetLineColor(kBlue);
		//h_mc_scaled->SetLineWidth(2);
        	h_mc_scaled->SetMarkerStyle(21);
        	h_mc_scaled->SetMarkerColor(kBlue);
	}

	//Style for MC - old
	//h_mc->SetMarkerStyle(21);
	//h_mc->SetMarkerColor(kBlue);

//old version 
    //	if (mc_int > 0) {
    //    	double scale = data_int / mc_int;
    //    	TH1F* h_mc_scaled = (TH1F*)h_mc->Clone("h_mc_scaled");
    //		h_mc_scaled->Scale(scale);
    //    	std::cout << "Scaling MC by factor: " << scale << std::endl;
    //	} 
    //	else {
    //    	std::cerr << "Error: MC integral is zero in selected region!" << std::endl;
    //	}

	//Drawing the histogram
//	double maxY = std::max(h_ARH->GetMaximum(), h_mc->GetMaximum());
//	h_ARH->SetMaximum(1.1 * maxY);

	double maxY = h_mc_scaled ? std::max(h_ARH->GetMaximum(), h_mc_scaled->GetMaximum())
                          : h_ARH->GetMaximum();
	h_ARH->SetMaximum(1.1 * maxY);

	//setting axis title, size and location
	h_ARH->GetXaxis()->SetTitle("Energy (MeV)");   
	h_ARH->GetYaxis()->SetTitle("Counts");      
	h_ARH->GetXaxis()->SetTitleSize(0.045);
	h_ARH->GetYaxis()->SetTitleSize(0.045);
	h_ARH->GetXaxis()->SetLabelSize(0.035);
	h_ARH->GetYaxis()->SetLabelSize(0.035);

	h_ARH->GetXaxis()->SetRangeUser(xmin, xmax);

	if(h_mc_scaled){
		h_mc_scaled->GetXaxis()->SetRangeUser(xmin,xmax);
	}


	h_ARH->Draw("E1 P");
	if (h_mc_scaled) h_mc_scaled->Draw("HIST SAME");
	//h_mc->Draw("HIST SAME");
	//h_mc_scaled->Draw("HIST SAME");

	//To denote the incident photon energy as done in ProjCATSE()
	Double_t x[2], y[2];

    	x[0] = 0.15;
    	x[1] = 0.35;
    	y[0] = 0.45;
    	y[1] = 0.55;
	
    	TPaveText *pt = new TPaveText(x[0], y[0], x[1], y[1], "NDC");
    	pt->SetBorderSize(0);
   	pt->SetFillStyle(0);
    	pt->SetTextAlign(12);
    	pt->SetTextSize(0.04);
   
    	name = Form("E_{#gamma} = %d MeV", eg);
   	pt->AddText(name);
    	pt->Draw();

	//Legend
	TLegend *leg = new TLegend(0.75, 0.4, 0.88, 0.58);
	leg->SetHeader("In Beam", "C");
	leg->AddEntry(h_ARH, "Data", "lep");
	leg->AddEntry(h_mc_scaled, "Simulation" , "l");
	leg->Draw();


	c->Print("plots/MCvsDATA.pdf");	
}


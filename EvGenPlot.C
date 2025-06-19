void Plot(){

// Open EvGen output file
	TFile *file = new TFile( "EvGen/out/5cm/compton_p_200_in.root");

	// Get scattered theta histogram h4
	TH1D *hist = (TH1D*)file->Get( "h4");

	// Create a canvas
	TCanvas *c1 = new TCanvas( "c1", "EvGen Results", 200, 10, 700, 500);

	/*// setting parametrs for aesthetic and clarification perposes
	hist->GetXAxis()->SetTitle("x-axis"); // giving a title to x-axis
	hist->GetYAxis()->SetTitle("y-axis"); //giving a tiltle to y-axis
	hist->SetColor(kMagenta-6)*/

	// Draw the histogram
	hist->Draw();
}

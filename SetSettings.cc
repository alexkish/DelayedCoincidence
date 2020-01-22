        //gStyle->SetOptStat("em");
    gStyle->SetOptStat(1);
	gStyle->SetOptFit(1);
	
	gStyle->SetPalette(1);
	gStyle->SetStatBorderSize(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(10);
	gStyle->SetStatColor(10);
	gStyle->SetStatFont(42);
	gStyle->SetMarkerStyle(1);
	gStyle->SetMarkerColor(4);


	//------ define color gradinet ---------------------------------------------
	const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    //gStyle->SetNumberContours(NCont);
    gStyle->SetNumberContours(30);
	//--------------------------------------------------------------------------
	
	//------ canvas dimensions -------------------------------------------------
	double win_x	= 700;
	double win_y	= 500;
	//--------------------------------------------------------------------------

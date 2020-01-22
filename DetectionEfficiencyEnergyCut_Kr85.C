#include "TTree.h"
#include "TFile.h"
#include "TBranch.h"
#include "TBranchElement.h"
#include "TROOT.h"
#include "TObject.h"
#include "TMath.h"
#include "TRandom.h"
#include "TChain.h"
#include "TPad.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TF1.h"
#include "TF2.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TCut.h"
#include "TCutG.h"
#include "TPaveStats.h"
#include "TPaletteAxis.h"
#include "TText.h"
#include "TEllipse.h"
#include "TDatime.h"
#include "TList.h"
#include "TMarker.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include <ctime>

using namespace std;


void DetectionEfficiencyEnergyCut_Kr85()
{
	
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(1);

	TF1 *S1resolution = new TF1("S1resolution", "(1/sqrt(x)+11.2)/100", 0, 2000);

	const double gammaE = 514.;//keV
	double gammaRes

	TF1 *gamma1 = new TF1("gamma1", "gaus", 0, 100);
		livetime_Kr85->SetParameter(1, Egamma);
		livetime_Kr85->SetLineColor(2, Sgamma);
		livetime_Kr85->SetNpx(1000);
		livetime_Kr85->Draw("");

	// Livetime
	TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 700, 500);
			 c1->SetFillColor(10);
			 c1->SetFillStyle(0);
			 c1->SetLogy();

		livetime_Kr85->SetTitle(0);
		livetime_Kr85->SetMaximum(2);
		livetime_Kr85->SetMinimum(1e-5);
		livetime_Kr85->GetXaxis()->SetRangeUser(0.,15.);

		Lmin->Draw();
		Lmax->Draw();

		livetime_Kr85	-> GetXaxis() -> SetTitle("Livetime [#mus]");
		livetime_Kr85	-> GetYaxis() -> SetTitle("Counts");
		livetime_Kr85	-> GetXaxis() -> CenterTitle(true);
		livetime_Kr85	-> GetYaxis() -> CenterTitle(true);
		livetime_Kr85	-> GetXaxis() -> SetTitleOffset(1.20);
		livetime_Kr85	-> GetYaxis() -> SetTitleOffset(1.20);
	c1->Update();

	double int_full = livetime_Kr85->Integral(0,100.);
	double int_win 	= livetime_Kr85->Integral(Tmin,Tmax);
	double detEff_dt 	= int_win/int_full;
	cout <<"Detection efficiency = "<< detEff_dt << endl;
	

}   		

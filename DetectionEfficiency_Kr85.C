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


TF1 *likely_Kr85, *LLike90, *LLike95;
double finter1_90(double *x, double*par) {
return TMath::Abs(likely_Kr85->EvalPar(x,par)-LLike90->EvalPar(x,par));
}
double finter2_90(double *x, double*par) {
return TMath::Abs(likely_Kr85->EvalPar(x,par)-LLike90->EvalPar(x,par));
}
double finter1_95(double *x, double*par) {
return TMath::Abs(likely_Kr85->EvalPar(x,par)-LLike95->EvalPar(x,par));
}
double finter2_95(double *x, double*par) {
return TMath::Abs(likely_Kr85->EvalPar(x,par)-LLike95->EvalPar(x,par));
}


void DetectionEfficiency_Kr85()
{
	
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(1);


/*	TF1 *fitExpTrue = new TF1("fitExpTrue","expo",0,10000);
	double HalfLife = 1.015; //us
	double lambda = -TMath::Log(2)/HalfLife;
	fitExpTrue->SetParameter(1,lambda);
	//double int_inf	= fitExpTrue->Integral(0, 3.1536e7); // 1 year livetime
	double int_inf	= fitExpTrue->Integral(0, 100); // 1 year livetime
*/      
/*	for (int i=0; i<nslices; i++) {
	   	double t1 = 0+tstep*i;
	   	double t2 = t1+tstep;
	   	t[i] = t2;
	   	intS1_slice[i]	= fitExpTrue->Integral(resS1, t2);
		detEfS1[i] 		= intS1_slice[i]/int_inf *100; // in %
	   	cout <<"S1 efficiency in Slice "<< i <<" ("<< t1 <<" to "<< t2 <<" us) = "<< detEfS1[i] << endl;
		intS2_slice[i] 	= fitExpTrue->Integral(resS2, twindow-t2);
		detEfS2[i] 		= intS2_slice[i]/int_inf *100; // in %
	   	cout <<"S2 efficiency in Slice "<< i <<" ("<< t1 <<" to "<< t2 <<" us) = "<< detEfS2[i] << endl;
		detEfTotal[i]	= (detEfS1[i]/100)*(detEfS2[i]/100)*100;	
	   	cout <<"Total efficiency in Slice "<< i <<" ("<< t1 <<" to "<< t2 <<" us) = "<< detEfTotal[i] << endl;
		}
*/
	double HalfLife = 1.015; //us
	double lambda 	= -TMath::Log(2)/HalfLife;
	double MeanLife = 1/lambda;


	double Tmin = 0.3;
	double Tmax = 10;
	
	TLine *Lmin = new TLine(Tmin, 0, Tmin, 2);
	TLine *Lmax = new TLine(Tmax, 0, Tmax, 2);
	Lmin->SetLineStyle(2);
	Lmax->SetLineStyle(2);
	Lmin->SetLineColor(4);
	Lmax->SetLineColor(4);

	// Livetime
	TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 700, 500);
			 c1->SetFillColor(10);
			 c1->SetFillStyle(0);
			 c1->SetLogy();

		TF1 *livetime_Kr85 = new TF1("livetime_Kr85", "expo", 0, 100);
			 livetime_Kr85->SetParameter(1,lambda);
			 livetime_Kr85->SetLineColor(2);
			 livetime_Kr85->SetNpx(1000);
			 livetime_Kr85->Draw("");

			 livetime_Kr85->SetTitle("");
			 livetime_Kr85->SetMaximum(2);
			 livetime_Kr85->SetMinimum(1e-4);
			 livetime_Kr85->GetXaxis()->SetRangeUser(-1.,12.);

		Lmin->Draw();
		Lmax->Draw();

		livetime_Kr85	-> GetXaxis() -> SetTitle("Time [#mus]");
		livetime_Kr85	-> GetYaxis() -> SetTitle("Counts");
		livetime_Kr85	-> GetXaxis() -> CenterTitle(true);
		livetime_Kr85	-> GetYaxis() -> CenterTitle(true);
		livetime_Kr85	-> GetXaxis() -> SetTitleOffset(1.20);
		livetime_Kr85	-> GetYaxis() -> SetTitleOffset(1.20);

   	TPaveStats *ptstats = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   	ptstats->SetName("stats");
   	ptstats->SetBorderSize(0);
   	ptstats->SetTextAlign(12);
   	ptstats->SetFillStyle(0);
   	ptstats->SetFillColor(0);
   
   	char text1[256];
   	char text2[256];
   	char text3[256];
  	sprintf(text1, "#lambda =   %1.2f ", lambda);
  	sprintf(text2, "#tau    =   %1.2f #mus", -MeanLife);
  	sprintf(text3, "T_{1/2} =   %1.3f #mus", HalfLife);
  
   	TText *text = ptstats->AddText(text1);
   		   text = ptstats->AddText(text2);
   		   text = ptstats->AddText(text3);
   	ptstats->Draw();
	c1->Update();

	double int_full = livetime_Kr85->Integral(0,100.);
	double int_win 	= livetime_Kr85->Integral(Tmin,Tmax);
	double detEff_dt 	= int_win/int_full;
	cout <<"Detection efficiency DT = "<< detEff_dt << endl;




	// compute scaling factor to go from the concentration of natural krypton to the activity of Kr-85
	// half-life time
	double T12 = 10.756 * 365 * 24 *3600; //10.756 years
	// lifetime in seconds
	double tau = T12/log(2);
	// avogadro number
	double Na = 6.022e23; // g-1
	// concentration (assuming 1e-11 abundance of Kr85 in natural Krypton)
	//double C_Kr   	= 150e-12;
	double ratio_KrXe 	= 0.641221;
	//double ratio_KrXe 	= 1.0;
	double C_Kr85 		= 1e-11;
	double act_LXe_Kr	= 1;
	double C      		= act_LXe_Kr *C_Kr85 *ratio_KrXe;
	// atomic number
	double A = 85;

	// COMPUTE
	//double R_g 	= (C*Na)/(A*tau); //Bq/g
	//double R_kg = R_g*1000; // Bq/kg

	//cout <<"Activity of "<< act_LXe_Kr <<" of nat. Krypton = "<< R_kg <<" Bq/kg"<< endl;




	//--------------------------------------------------------------------------------------------------
	// confidence interval

/*	// run07
	const double nEvents	= 19;	
	double limitLeft 		= 10;
	double limitRight 		= 32;
	double livetime_days 	= 40.4021; // measured livetime
	double detEff_E = 0.95*0.95;
*/
/*	// run07 before leak
	const double nEvents	= 3;	
	double limitLeft 		= 0.1;
	double limitRight 		= 10;
	double livetime_days 	= 21.4428; // measured livetime
	double detEff_E = 0.95*0.95;
*/
/*	// run07 after leak
	const double nEvents	= 16;	
	double limitLeft 		= 10;
	double limitRight 		= 32;
	double livetime_days 	= 18.9594; // measured livetime
	double detEff_E = 0.95*0.95;
*/
/*	//run08
	const double nEvents	= 104;	
	double limitLeft 		= 80;
	double limitRight 		= 130;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;
*/
/*	// run10, short
	const double nEvents	= 7;	
	double limitLeft 		= 2;
	double limitRight 		= 15;
	//double livetime_days 	= 37.7;
	//double livetime_days 	= 34.6; // corrected(1) livetime, overestimated
	//double livetime_days 	= 26.0; // corrected(2) livetime, underestimated
	double livetime_days 	= 32.1228; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 4.4kV, 124 files
	const double nEvents	= 24;	
	double limitLeft 		= 10;
	double limitRight 		= 40;
	double livetime_days 	= 84.2159; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 4.4kV, 163 files
	const double nEvents	= 43;	
	double limitLeft 		= 20;
	double limitRight 		= 60;
	double livetime_days 	= 140.152; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 4.4kV, 188 files
	const double nEvents	= 43;	
	double limitLeft 		= 25;
	double limitRight 		= 70;
	double livetime_days 	= 156.977; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 4.4kV, 180 files
	const double nEvents	= 43;	
	double limitLeft 		= 25;
	double limitRight 		= 70;
	double livetime_days 	= 150.578; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 14 files
	const double nEvents	= 3;	
	double limitLeft 		= 0;
	double limitRight 		= 15;
	double livetime_days 	= 11.7803; // COR
	double detEff_E = 0.95*0.95;
*/


/*	// run10, 180 files
	const double nEvents	= 31;	
	double limitLeft 		= 10;
	double limitRight 		= 45;
	double livetime_days 	= 150.578; // COR
	double detEff_E = 0.95*0.95;
*/
/*	//run08
	const double nEvents	= 24;	
	double limitLeft 		= 10;
	double limitRight 		= 40;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 180 files
	const double nEvents	= 12;
	double limitLeft 		= 4;
	double limitRight 		= 30;
	double livetime_days 	= 150.578; // COR
	double detEff_E = 0.95*0.95;
*/
/*	//run08
	const double nEvents	= 80;	
	double limitLeft 		= 60;
	double limitRight 		= 100;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, entire target
	const double nEvents	= 55;
	double limitLeft 		= 40;
	double limitRight 		= 70;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, R>14cm
	const double nEvents	= 39;
	double limitLeft 		= 25;
	double limitRight 		= 55;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, R<14cm
	const double nEvents	= 16;
	double limitLeft 		= 2;
	double limitRight 		= 30;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, R>14.5cm
	const double nEvents	= 37;
	double limitLeft 		= 25;
	double limitRight 		= 55;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, R>13.5cm
	const double nEvents	= 42;
	double limitLeft 		= 25;
	double limitRight 		= 55;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, R<14.5cm
	const double nEvents	= 18;
	double limitLeft 		= 8;
	double limitRight 		= 35;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	// run10, 248 files, R<13.5cm
	const double nEvents	= 13;
	double limitLeft 		= 4;
	double limitRight 		= 30;
	double livetime_days 	= 198.6; // COR
	double detEff_E = 0.95*0.95;
*/
/*	//run08, R>14.5
	const double nEvents	= 22;	
	double limitLeft 		= 10;
	double limitRight 		= 40;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;
*/
/*	//run08, R>13.5
	const double nEvents	= 29;	
	double limitLeft 		= 10;
	double limitRight 		= 45;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;
*/
	//run08, R>14.5
	const double nEvents	= 82;	
	double limitLeft 		= 60;
	double limitRight 		= 110;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;

/*	//run08, R>13.5
	const double nEvents	= 75;	
	double limitLeft 		= 40;
	double limitRight 		= 100;
	double livetime_days 	= 100.9; // corrected
	double detEff_E = 0.95*0.95;
*/
	// scaling factor to convert from 1Bq/kg to concentration
	//double R1_kg = 1.0; 		// 1Bq/kg
	//double massLXe	= 62.0; // kg
	//double massLXe	= 8.360; // kg
	//double massLXe	= 55.7; // kg
	//double massLXe	= 6.258; // kg
	double massLXe	= 57.742; // kg
	//double massLXe	= 14.221; // kg
	//double massLXe		= 49.8; // kg
	double livetime_sec = livetime_days*86400;

	double R1_kg 	= nEvents/livetime_sec/massLXe; // 1Bq/kg
	double R1_g  	= R1_kg/1000;	// 1Bq/g
	double C1_Kr85 	= (R1_g*A*tau)/Na;
	//double C1_Kr   	= C1_Kr85/C_Kr85;
	double C1_Kr   	= C1_Kr85/C;
	double C2_Kr   	= C1_Kr/0.00434/detEff_dt/detEff_E;
	
	//cout <<"1 Bq/kg of Kr85  ::  "<< C1_Kr <<" g/g of nat. Krypton"<< endl;
	cout <<"Kr85 central value ::  "<< C2_Kr <<" g/g of nat. Krypton"<< endl;

	
	
	// probabiolity, Poisson distribution
	TCanvas *c2 = new TCanvas("c2", "c2", 0, 0, 700, 500);
			 c2->SetFillColor(10);
			 c2->SetFillStyle(0);

		TF1 *events_Kr85 = new TF1("events_Kr85", "TMath::Poisson([1], x)", limitLeft, limitRight);
		events_Kr85->SetTitle("");
		events_Kr85->SetParameter(1,nEvents);
		events_Kr85->SetLineColor(2);
		events_Kr85->Draw("");

		events_Kr85	-> GetXaxis() -> SetTitle("N");
		events_Kr85	-> GetYaxis() -> SetTitle("f(N)");
		events_Kr85	-> GetXaxis() -> CenterTitle(true);
		events_Kr85	-> GetYaxis() -> CenterTitle(true);
		events_Kr85	-> GetXaxis() -> SetTitleOffset(1.20);
		events_Kr85	-> GetYaxis() -> SetTitleOffset(1.20);
	c2->Update();


	// Log likelyhood
	TCanvas *c3 = new TCanvas("c3", "c3", 0, 0, 700, 500);
			 c3->SetFillColor(10);
			 c3->SetFillStyle(0);

		likely_Kr85 = new TF1("likely_Kr85", "log(TMath::Poisson([1], x))", limitLeft, limitRight);
		likely_Kr85->SetTitle("");
		likely_Kr85->SetParameter(1,nEvents);
		likely_Kr85->SetLineColor(2);
		likely_Kr85->Draw("");

		double LogMaxX = likely_Kr85->GetMaximumX();
		double LogMaxY = likely_Kr85->GetMaximum();
		double LogMinY = likely_Kr85->GetMinimum();
		cout <<"LogMaxX = "<< LogMaxX << endl;
		cout <<"LogMaxY = "<< LogMaxY << endl;
		cout <<"LogMinY = "<< LogMinY << endl;
		TLine *LogMaxLine = new TLine(LogMaxX, LogMinY, LogMaxX, LogMaxY);
			   LogMaxLine->SetLineStyle(7);
			   LogMaxLine->SetLineColor(4);
			   LogMaxLine->Draw();
		
		double maximum_Kr85 	= likely_Kr85->GetMaximum();
		double minimum90_Kr85 	= maximum_Kr85 - 2.71/2;
		double minimum95_Kr85 	= maximum_Kr85 - 3.84/2;
		//cout <<"maximum = "<< maximum_Kr85 << endl;
		//cout <<"minimum = "<< minimum_Kr85 << endl;
		
		LLike90 = new TF1("LLike90","pol0",limitLeft, limitRight);
			 LLike90->SetLineColor(4);
			 LLike90->SetParameter(0, minimum90_Kr85);
		LLike90->Draw("same");

		LLike95 = new TF1("LLike95","pol0",limitLeft, limitRight);
			 LLike95->SetLineColor(4);
			 LLike95->SetParameter(0, minimum95_Kr85);
		LLike95->Draw("same");
		
		likely_Kr85	-> GetXaxis() -> SetTitle("N");
		likely_Kr85	-> GetYaxis() -> SetTitle("logL(N)");
		likely_Kr85	-> GetXaxis() -> CenterTitle(true);
		likely_Kr85	-> GetYaxis() -> CenterTitle(true);
		likely_Kr85	-> GetXaxis() -> SetTitleOffset(1.20);
		likely_Kr85	-> GetYaxis() -> SetTitleOffset(1.20);
	c3->Update();


	c2->cd();
		// find intersect 90 1
		TF1 *fint1_90 	= new TF1("fint1_90", finter1_90, 0, nEvents);
		double xint1_90 = fint1_90->GetMinimumX();
		double yint1_90 = events_Kr85->Eval(xint1_90);
		TMarker *mint1_90 = new TMarker(xint1_90, yint1_90, 24);
				 mint1_90->SetMarkerColor(4);
				 mint1_90->SetMarkerSize(1.6);
				 mint1_90->Draw();
		// find intersect 90 2
		TF1 *fint2_90 	= new TF1("fint2_90", finter2_90, nEvents, 1000);
		double xint2_90 = fint2_90->GetMinimumX();
		double yint2_90 = events_Kr85->Eval(xint2_90);
		TMarker *mint2_90 = new TMarker(xint2_90, yint2_90, 24);
				 mint2_90->SetMarkerColor(4);
				 mint2_90->SetMarkerSize(1.6);
				 mint2_90->Draw();
		// find intersect 95 1
		TF1 *fint1_95 	= new TF1("fint1_95", finter1_95, 0, nEvents);
		double xint1_95 = fint1_95->GetMinimumX();
		double yint1_95 = events_Kr85->Eval(xint1_95);
		TMarker *mint1_95 = new TMarker(xint1_95, yint1_95, 24);
				 mint1_95->SetMarkerColor(4);
				 mint1_95->SetMarkerSize(1.6);
				 mint1_95->Draw();
		// find intersect 95 2
		TF1 *fint2_95 	= new TF1("fint2_95", finter2_95, nEvents, 1000);
		double xint2_95 = fint2_95->GetMinimumX();
		double yint2_95 = events_Kr85->Eval(xint2_95);
		TMarker *mint2_95 = new TMarker(xint2_95, yint2_95, 24);
				 mint2_95->SetMarkerColor(4);
				 mint2_95->SetMarkerSize(1.6);
				 mint2_95->Draw();

		// mean
		double xM 	= events_Kr85->GetMaximumX();
		double yM 	= events_Kr85->GetMaximum();
		TLine *lintM = new TLine(xM, 0, xM, yM);
		// 90 CL
		TLine *lint1_90 = new TLine(xint1_90, 0, xint1_90, yint1_90);
		TLine *lint2_90 = new TLine(xint2_90, 0, xint2_90, yint2_90);
		// 95 CL
		TLine *lint1_95 = new TLine(xint1_95, 0, xint1_95, yint1_95);
		TLine *lint2_95 = new TLine(xint2_95, 0, xint2_95, yint2_95);

		lintM	->SetLineColor(4);
		lint1_90->SetLineColor(4);
		lint2_90->SetLineColor(4);
		lint1_95->SetLineColor(4);
		lint2_95->SetLineColor(4);

		lintM	->SetLineStyle(7); 
		lint1_90->SetLineStyle(7);
		lint2_90->SetLineStyle(7);
		lint1_95->SetLineStyle(7);
		lint2_95->SetLineStyle(7);

		lintM	->Draw();
		lint1_90->Draw();
		lint2_90->Draw();
		lint1_95->Draw();
		lint2_95->Draw();

		double errorLow_90	= nEvents - xint1_90;
		double errorHigh_90	= xint2_90 - nEvents;
		cout <<"90% C.L.: central value = "<< nEvents <<"  +"<< errorHigh_90 <<"  -"<< errorLow_90 <<" events"<< endl;
		cout <<"Nevents: Lower limit   = "<< xint1_90 	<< endl;
		cout <<"Nevents: Upper limit   = "<< xint2_90 	<< endl;

		double errorLow_95	= nEvents - xint1_95;
		double errorHigh_95	= xint2_95 - nEvents;
		cout <<"95% C.L.: central value = "<< nEvents <<"  +"<< errorHigh_95 <<"  -"<< errorLow_95 <<" events"<< endl;
		cout <<"Nevents: Lower limit   = "<< xint1_95 	<< endl;
		cout <<"Nevents: Upper limit   = "<< xint2_95 	<< endl;
	c2->Update();


	// convert from Nevents to concentration

	// 90% C.L.
	double lowEr90_R1_kg 	= errorLow_90/livetime_sec/massLXe; // 1Bq/kg
	double lowEr90_R1_g  	= lowEr90_R1_kg/1000;	// 1Bq/g
	double lowEr90_C1_Kr85 	= (lowEr90_R1_g*A*tau)/Na;
	//double lowEr90_C1_Kr   	= lowEr90_C1_Kr85/C_Kr85;
	double lowEr90_C1_Kr   	= lowEr90_C1_Kr85/C;
	double lowEr90_C2_Kr   	= lowEr90_C1_Kr/0.00434/detEff_dt/detEff_E;

	double highEr90_R1_kg 	= errorHigh_90/livetime_sec/massLXe; // 1Bq/kg
	double highEr90_R1_g  	= highEr90_R1_kg/1000;	// 1Bq/g
	double highEr90_C1_Kr85 = (highEr90_R1_g*A*tau)/Na;
	//double highEr90_C1_Kr   = highEr90_C1_Kr85/C_Kr85;
	double highEr90_C1_Kr   = highEr90_C1_Kr85/C;
	double highEr90_C2_Kr   = highEr90_C1_Kr/0.00434/detEff_dt/detEff_E;

	// 95% C.L.
	double lowEr95_R1_kg 	= errorLow_95/livetime_sec/massLXe; // 1Bq/kg
	double lowEr95_R1_g  	= lowEr95_R1_kg/1000;	// 1Bq/g
	double lowEr95_C1_Kr85 	= (lowEr95_R1_g*A*tau)/Na;
	//double lowEr95_C1_Kr   	= lowEr95_C1_Kr85/C_Kr85;
	double lowEr95_C1_Kr   	= lowEr95_C1_Kr85/C;
	double lowEr95_C2_Kr   	= lowEr95_C1_Kr/0.00434/detEff_dt/detEff_E;

	double highEr95_R1_kg 	= errorHigh_95/livetime_sec/massLXe; // 1Bq/kg
	double highEr95_R1_g  	= highEr95_R1_kg/1000;	// 1Bq/g
	double highEr95_C1_Kr85 = (highEr95_R1_g*A*tau)/Na;
	//double highEr95_C1_Kr   = highEr95_C1_Kr85/C_Kr85;
	double highEr95_C1_Kr   = highEr95_C1_Kr85/C;
	double highEr95_C2_Kr   = highEr95_C1_Kr/0.00434/detEff_dt/detEff_E;
	
	cout <<"Krypton concentration at 90 C.L.: "<< C2_Kr*1e12 <<" +"<< highEr90_C2_Kr*1e12 <<" -"<< lowEr90_C2_Kr*1e12 <<" g/g of nat. Krypton"<< endl;
	cout <<"Krypton concentration at 95 C.L.: "<< C2_Kr*1e12 <<" +"<< highEr95_C2_Kr*1e12 <<" -"<< lowEr95_C2_Kr*1e12 <<" g/g of nat. Krypton"<< endl;

// run07
//Krypton concentration at 90 C.L.: 296.73 +126.595 -98.4239 g/g of nat. Krypton
//Krypton concentration at 95 C.L.: 296.73 +154.094 -114.203 g/g of nat. Krypton

// run07, before leak
//Krypton concentration at 90 C.L.: 88.2777 +112.341 -59.7034 g/g of nat. Krypton
//Krypton concentration at 95 C.L.: 88.2777 +140.6 -66.317 g/g of nat. Krypton

// run07, after leak
//Krypton concentration at 90 C.L.: 532.484 +250.184 -190.171 g/g of nat. Krypton
//Krypton concentration at 95 C.L.: 532.484 +305.091 -220.12 g/g of nat. Krypton

// run08	
//Krypton concentration at 90 C.L.: 650.36 +110.707 -99.4123 g/g of nat. Krypton
//Krypton concentration at 95 C.L.: 650.36 +133.098 -117.096 g/g of nat. Krypton

// run10, short
//Krypton concentration at 90 C.L.: 137.498 +104.143 -68.8072 g/g of nat. Krypton
//Krypton concentration at 95 C.L.: 137.498 +128.388 -78.4065 g/g of nat. Krypton

// run10, 124 files (84.2159 days)
//Krypton concentration at 90 C.L.: 179.816 +67.373 -53.8538 g/g of nat. Krypton
//Krypton concentration at 95 C.L.: 179.816 +81.8197 -62.6734 g/g of nat. Krypton

// run10, 163 files (140.152 days)
// Krypton concentration at 90 C.L.: 193.589 +52.7486 -44.6205 g/g of nat. Krypton
// Krypton concentration at 95 C.L.: 193.589 +63.7517 -52.2378 g/g of nat. Krypton


}   		

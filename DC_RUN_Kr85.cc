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
#include "TPad.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TF1.h"
#include "TF2.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TLegend.h"
#include "TCut.h"
#include "TCutG.h"
#include "TPaveStats.h"
#include "TPaletteAxis.h"
#include "TText.h"
#include "TColor.h"
#include "TEllipse.h"
#include "TDatime.h"
#include "TMath.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include <ctime>

using namespace std;

void DC_RUN_Kr85()
{	

	clock_t init, final;

	init=clock();


#include "SetSettings.cc"

#include "LoadData.cc"
#include "DC_Histograms.cc"


TCanvas *c_S1 = new TCanvas("c_S1", "c_S1", 0, 0,700,500);
		 c_S1->SetFillColor(10);
		 c_S1->SetGrid();
		 c_S1->SetFillStyle(0);			 
		 //c_S1->SetLogx();
		 //c_S1->SetLogy();
		 //c_S1->SetLogz();


TCanvas *c_delayT = new TCanvas("c_delayT", "c_delayT", 705, 0,700,500);
		 c_delayT->SetFillColor(10);
		 c_delayT->SetGrid();
		 c_delayT->SetFillStyle(0);			 


//----------------------------------------------------------------------------------

	//char date[200], time[200];
	char yr[300], mon[300], day[300], hour[300], min[300];
	int yr_i[300], day_i[300], mon_i[300], hour_i[300], min_i[300];

	float x[1000], xEr[1000], y[1000], yEr[1000], y2[1000], y2Er[1000];


	// LOOP ON DATAFILES INCLUDED IN THE FILE-LIST
	while((logfile >> date >> time >> livetime)){
	
	yr[0] 	= date[0];
	yr[1] 	= date[1];
	yr[2] 	= date[17];
	
	mon[0] 	= date[2];
	mon[1] 	= date[3];
	mon[2] 	= date[6];
	
	day[0] 	= date[4];
	day[1] 	= date[5];
	day[2] 	= date[6];

	hour[0] = time[0];
	hour[1]	= time[1];
	hour[2]	= time[4];
	
	min[0]	= time[2];
	min[1]	= time[3];
	min[2]	= time[4];
	
	char temp_yr[300];
	sprintf(temp_yr,"20%s",yr);
	char temp_mon[300];
	sprintf(temp_mon,"%s",mon);
	char temp_day[300];
	sprintf(temp_day,"%s",day);
	char temp_hour[300];
	sprintf(temp_hour,"%s",hour);
	char temp_min[300];
	sprintf(temp_min,"%s",min);

	yr_i[nf] 	= atoi(temp_yr);
	mon_i[nf] 	= atoi(temp_mon);
	day_i[nf] 	= atoi(temp_day);
	hour_i[nf] 	= atoi(temp_hour);
	min_i[nf] 	= atoi(temp_min);
		
	TDatime da(yr_i[nf],mon_i[nf],day_i[nf],hour_i[nf],min_i[nf],00); 
	x[nf] 	= da.Convert() + livetime/2;
	xEr[nf] = livetime/2;

	////////////////////////////////////////////////////////////////////
	// COUT
	cout << nf <<" ("<< date <<" "<< time <<");   " 
		 <<"livetime = "<< livetime << endl;
	////////////////////////////////////////////////////////////////////

	Char_t  rootFile[500];
	sprintf(rootFile, "%s/xe100_%s_%s.root", rootFolder, date, time);

	//Char_t  rootFile_T3xy[500];
	//sprintf(rootFile_T3xy, "%s/xe100_%s_%s_T3xy.root", rootFolder_T3xy, date, time);

	TChain *T1 		= new TChain("T1");
	TChain *T2 		= new TChain("T2");
	TChain *T3 		= new TChain("T3");
	//TChain *T3xy 	= new TChain("T3xy");
		T1		->Add(rootFile);
		T2		->Add(rootFile);
		T3		->Add(rootFile);
		//T3xy	->Add(rootFile_T3xy);

		T1->AddFriend("T2");
		T1->AddFriend("T3");
		//T1->AddFriend("T3xy");
	
	#include "DC_SetAlias.cc"
	#include "DC_SetCuts.cc"


	////////////////////////////////////////////////////////////////////

	// DC, U238
	c_S1->cd();
	T1->Draw("S1sTotC1>>+h1_S1beta", 	cutData_Kr85,	"");
	T1->Draw("S1sTotC0>>+h1_S1alpha", 	cutData_Kr85, "same");
	c_S1->Update();	

	double nn_alpha		= h1_S1alpha->GetEntries();
	double nnEr_alpha	= sqrt(nn_alpha);
	double rate_alpha 	= nn_alpha / livetime;
	double rateEr_alpha = nnEr_alpha / livetime;
	double rate2_alpha 	= nn_alpha / livetime * 86400;
	double rate2Er_alpha = nnEr_alpha / livetime * 86400;
	double activity_alpha 	= rate_alpha	/mass_LXe *1e6;
	double activityEr_alpha = rateEr_alpha	/mass_LXe *1e6;
	// rate
	y[nf] 	= activity_alpha;
	yEr[nf] = activityEr_alpha;
	// events/day
	y2[nf] 	= rate2_alpha;
	y2Er[nf] = rate2Er_alpha;
	
	cout <<">>> EVTS found = "<< nn_alpha 	<<" events"<< endl;
	cout <<"RATE = "<< rate2_alpha 		<<" events/day"<< endl;
	cout <<"Error = "<< rate2Er_alpha 	<<" events/day"<< endl;

	//cout <<"Activity = "<< activity_alpha 	<< " uBq/kg"<< endl;
	//cout <<"Error    = "<< activityEr_alpha <<" uBq/kg"<< endl;

	// delay time
	c_delayT->cd();
	T1->Draw("delayT>>+h1_delayT", 	cutData_Kr85,"");
	c_delayT->Update();	

	// calculate total livetime
	livetime_tot += livetime;

	nf++;
	
	// clean buffer after each file
	T1	->Delete();
	T2	->Delete();
	T3	->Delete();
	//T3xy->Delete();

}	// end looping on files

	// compute scaling factors
	double livetime_tot_days = livetime_tot / 3600 / 24;
	cout <<"Total Livetime = "<< livetime_tot <<" sec = "<< livetime_tot_days <<" days"<< endl;
	double rescaleF_mHz			= 1 / livetime_tot *1000;
	double rescaleF_uBqKg		= 1 / livetime_tot / mass_LXe *1e6;
	//double rescaleF_dru		= 1 / livetime_tot_days / binwidth_S1kev /65;
	//double rescaleF_dru_FV30	= 1 / livetime_tot_days / binwidth_S1kev /30;


	// plot rate VS time
	TCanvas *c_EventDay = new TCanvas("c_EventDay", "events vs days", 0, 0, 1200, 500);
			 c_EventDay->SetFillColor(10);
			 c_EventDay->SetGrid();
			 c_EventDay->SetFillStyle(0);

    TGraphErrors *gr2 = new TGraphErrors(nf, x, y2, xEr, y2Er);
    			  gr2->SetMarkerStyle(22);
    			  gr2->SetMarkerSize(1.3);
    			  gr2->SetMarkerColor(2);
    			  gr2->SetLineColor(2);
    			  gr2->SetTitle("");

			gr2->GetXaxis()->SetTimeFormat("%m/%d");
			gr2->GetXaxis()->SetTimeDisplay(1);
			gr2->GetXaxis()->SetTitle("Time");
    		//gr2->GetYaxis()->SetTitle("rate [#muBq/kg]");
    		gr2->GetYaxis()->SetTitle("Rate [events/day]");
			gr2->GetXaxis()->CenterTitle(true);
			gr2->GetYaxis()->CenterTitle(true);
    		//gain_er->GetYaxis()->SetRangeUser(0.0,3.0);
			gr2->Draw("AP");

	c_EventDay->Update();

	Char_t  c1_name1[500];
	sprintf(c1_name1, "%s/Kr85/%s_Kr85_rate-EvtsDay.png", outFolder, dataName);
	c_EventDay->SaveAs(c1_name1);
	Char_t  c1_name2[500];
	sprintf(c1_name2, "%s/Kr85/%s_Kr85_rate-EvtsDay.C", outFolder, dataName);
	c_EventDay->SaveAs(c1_name2);

	// delay time
	c_delayT->cd();
	h1_delayT->Sumw2();
	h1_delayT->GetXaxis()->SetTitle("Delay time [#mus]");
	h1_delayT->GetYaxis()->SetTitle("Counts");
	h1_delayT->GetXaxis()->CenterTitle(true);
	h1_delayT->GetYaxis()->CenterTitle(true);
	c_delayT->Update();	

	Char_t  c2_name1[500];
	sprintf(c2_name1, "%s/Kr85/%s_Kr85_delayT.png", outFolder, dataName);
	c_delayT->SaveAs(c2_name1);
	Char_t  c2_name2[500];
	sprintf(c2_name2, "%s/Kr85/%s_Kr85_delayT.C", outFolder, dataName);
	c_delayT->SaveAs(c2_name2);
	

	//
	// do stuff
	//
	final=clock()-init;
	cout <<"RUNNING TIME: "<< (double)final / ((double)CLOCKS_PER_SEC) << endl;

}

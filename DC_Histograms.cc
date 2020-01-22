// S1 phe
int nbins_S1		= 100;
double min_S1		= 0;
double max_S1		= 1200;
double binwidth_S1 	= (max_S1-min_S1)/nbins_S1;

int nbins_S2		= 100;
double min_S2		= 0;
double max_S2		= 84e3;
double binwidth_S2 	= (max_S2-min_S2)/nbins_S2;

double max_S1a		= 1200;

// phe
TH1F *h1_S1			= new TH1F("h1_S1",		"", nbins_S1,0,max_S1a);
	  h1_S1			->SetLineColor(1);
	  h1_S1			->SetLineWidth(2);	  
TH1F *h1_S1beta		= new TH1F("h1_S1beta",	"", nbins_S1,0,max_S1a);
	  h1_S1beta		->SetLineColor(4);
	  h1_S1beta		->SetLineWidth(2);
TH1F *h1_S1alpha	= new TH1F("h1_S1alpha","", nbins_S1,0,max_S1a);
	  h1_S1alpha	->SetLineColor(2);
	  h1_S1alpha	->SetLineWidth(2);
TH1F *h1_S1alpha1	= new TH1F("h1_S1alpha1","", nbins_S1,0,max_S1a);
	  h1_S1alpha1	->SetLineColor(3);
	  h1_S1alpha1	->SetLineWidth(2);
TH1F *h1_S1alpha2	= new TH1F("h1_S1alpha2","", nbins_S1,0,max_S1a);
	  h1_S1alpha2	->SetLineColor(6);
	  h1_S1alpha2	->SetLineWidth(2);


TH2F *h2_S2vsS1 = new TH2F("h2_S2vsS1","", nbins_S1, min_S1, max_S1, nbins_S2, min_S2, max_S2);
	  h2_S2vsS1->SetMarkerStyle(1);
	  h2_S2vsS1->SetMarkerColor(4);
	  
	  
	  
int nbins_xy 	= 100;
double min_xy	= -17.0;
double max_xy	= 17.0;

TH2F *h2_xy_svm = new TH2F("h2_xy_svm", "", nbins_xy, min_xy, max_xy, nbins_xy, min_xy, max_xy);
TH2F *h2_xy_chi = new TH2F("h2_xy_chi", "", nbins_xy, min_xy, max_xy, nbins_xy, min_xy, max_xy);
TH2F *h2_xy_nn 	= new TH2F("h2_xy_nn", 	"", nbins_xy, min_xy, max_xy, nbins_xy, min_xy, max_xy);
TH2F *h2_xy_nn1 = new TH2F("h2_xy_nn1", "", nbins_xy, min_xy, max_xy, nbins_xy, min_xy, max_xy);

int nbins_delayT 	= 50;
double min_delayT	= 0;
double max_delayT	= 10;

TH1F *h1_delayT = new TH1F("h1_delayT","", nbins_delayT, min_delayT, max_delayT);
	  h1_delayT->SetLineColor(2);
	  h1_delayT->SetMarkerColor(2);


TProfile2D	*tp_S1xy	= new TProfile2D("tp_S1xy",	"", nbins_xy, min_xy, max_xy, nbins_xy, min_xy, max_xy, min_S1, max_S1);
TProfile2D	*tp_S2xy	= new TProfile2D("tp_S2xy",	"", nbins_xy, min_xy, max_xy, nbins_xy, min_xy, max_xy, min_S2, max_S2);

int nbins_a		= 60;
double min_a	= 0;
double max_a	= 760;
int nbins_z		= 31;
double min_z	= -31;
double max_z	= 0;
TProfile2D	*tp_S1az	= new TProfile2D("tp_S1az",	"", nbins_a, min_a, max_a, nbins_z, min_z, max_z, min_S1, max_S1);
TProfile2D	*tp_S2az	= new TProfile2D("tp_S2az",	"", nbins_a, min_a, max_a, nbins_z, min_z, max_z, min_S2, max_S2);
TH2F 		*h2_az		= new TH2F("h2_az", "", nbins_a, min_a, max_a, nbins_z, min_z, max_z);

int nbins_dt	= 200;
double min_dt	= 0;
double max_dt	= 190;
int nbins_S2W	= 200;
double min_S2W	= 0;
double max_S2W	= 500;
TH2F *h2_S2W = new TH2F("h2_S2W", "", nbins_dt, min_dt, max_dt, nbins_S2W, min_S2W, max_S2W);

int nbins_r		= 50;
double min_r	= 0;
double max_r	= 16.0;
TH2F *h2_S1vsR	= new TH2F("h2_S1vsR","", nbins_r, min_r, max_r, nbins_S1, min_S1, max_S1);
TH2F *h2_S2vsR	= new TH2F("h2_S2vsR","", nbins_r, min_r, max_r, nbins_S2, min_S2, max_S2);

TH1F *h1_R	= new TH1F("h1_R", "",	nbins_r, min_r, max_r);
	  h1_R	->SetLineColor(2);
	  h1_R	->SetLineWidth(2);

	
	// QUALITY CUTS, AmBe
	TCut cutData_1	= "S1sCoin[0]>1 && Alt$(S1sCoin[1],0)<2";
	TCut cutData_2	= "S2sTot[0]>200 && Alt$(S2sTot[1],0)<200";
	TCut cutData_3	= "(log10((S1sTot[0]+S2sTot[0])/(AreaTot-S1sTot[0]-S2sTot[0])) > 0.0)";
	TCut cutData_4	= "(S2sSaturation[0] == 0)";
	TCut cutData_5	= "CE<100";//cS2sTot[0]<50000";
	TCut cutData_6	= "Z_cm<-5 && Z_cm>-20";
	//TCut cutData	= cutData_1 && cutData_2 && cutData_3 && cutData_4 && cutData_5 && cutData_6;
	//TCut cutData	= cutData_1 && cutData_2 && cutData_3 && cutData_4;

	// QUALITY CUTS
	TCut Xsignalnoise2 	= "(log10((S1sTot[0]+S2sTot[0])/(AreaTot-S1sTot[0]-S2sTot[0])) > 0.00)";   // remove events with a poor signal/noise ratio
	TCut Xs1coin0 		= "(S1sCoin[0] > 1)";   // the largest S1 peak should be at least twofold coincident
	TCut XS1			= "cS1sTot[0]>15e3 && cS1sTot[0]<28e3";
	TCut XS2			= "cS2sTotBottom[0]>2e3 && cS2sTotBottom[0]<84e3";
	TCut cutData 		= Xsignalnoise2 && Xs1coin0 && XS1 && XS2;

	TCut X40kg0 = "((R_nn < 13.5) && (Z_nn <-3.3 && Z_nn>-27.6))";

	// delayed coincidence analysis
	TCut cutData_U238_doublepeak		= "NbS1Peaks==2 || (NbS1Peaks>2 && S2sCoin[2]<3)";
	TCut cutData_U238_minEalpha			= "S1sTotC0>10e3";	// energy range for alpha
	TCut cutData_U238_maxEalpha			= "S1sTotC0<100e3";
	TCut cutData_U238_minEbeta			= "S1sTotC1>200";	// energy range for beta
	TCut cutData_U238_maxEbeta			= "S1sTotC1<9e3";
	TCut cutData_U238_AlphaAfterBeta	= "S1sPeak[0]>S1sPeak[1]"; // S1: peak 0 after peak 1 (alpha after beta)
	TCut cutData_U238_AlphaAfterBetaS2	= "S2sPeak[0]>S2sPeak[1]"; // S2: peak 0 after peak 1
	TCut cutData_U238_timeDelay			= "(S1sPeak[0]-S1sPeak[1])/100>2.0";
	TCut cutData_U238_s1coin 			= "((S1sCoin[0] > 2) && (S1sCoin[1] > 2))";
	//TCut cutData_U238					= cutData_U238_doublepeak && cutData_U238_minEalpha && cutData_U238_maxEalpha && cutData_U238_minEbeta && cutData_U238_maxEbeta && cutData_U238_AlphaAfterBeta && cutData_U238_timeDelay;

	TCut cutData_U238_1a	= "S1sTotC0>10e3 && S1sTotC0<50e3";
	TCut cutData_U238_1b	= "S1sTotC1>200 && S1sTotC1<17e3";
	TCut cutData_U238_1c	= "NbS1Peaks==2 || (NbS1Peaks>2 && S1sCoin[2]<3)";
	//TCut cutData_U238_1d	= "S1sCoin[0]>2 && S1sCoin[1]>2";
	TCut cutData_U238_1d	= "S1sCoin[0]>1 && S1sCoin[1]>1";
	TCut cutData_U238_1e	= "(S1sPeak[0]-S1sPeak[1])/100>2.0";
	TCut cutData_U238		= cutData_U238_1a && cutData_U238_1b && cutData_U238_1c && cutData_U238_1d && cutData_U238_1e && X40kg0;
	
	double yield = 1.6;
	TCut cutData_Kr85_1 = Form("S1sTot[0]<1200 && S1sTot[0]>300");	//	Energy of first interaction between 300 and 700 keV (*)
	TCut cutData_Kr85_2 = Form("S1sTot[1]<230 && S1sTot[1]>24");	// 	Energy of second interaction between 20 and 210 keV (*)
	TCut cutData_Kr85_3	= "NbS1Peaks>1";	//At least 2 S1 peaks
	TCut cutData_Kr85_4	= "S1sCoin[0]>4 && S1sCoin[1]>4";	//Both S1 peaks with multiple coincidences
	//TCut cutData_Kr85_5 = "TMath::Abs(S1sPeak[0]-S1sPeak[1])/100>0.3 && TMath::Abs(S1sPeak[0]-S1sPeak[1])/100<10.0";	//Time distance between peaks bigger than 0.3us and smaller than 5 us
	TCut cutData_Kr85_5 = "(S1sPeak[0]-S1sPeak[1])/100>0.3 && (S1sPeak[0]-S1sPeak[1])/100<10.0";	//Time distance between peaks bigger than 0.3us and smaller than 5 us
	TCut cutData_Kr85_6	= "S2Tot>1000";	//S2 of the event bigger than 1000 pe
	TCut cutData_Kr85_7	= "S1sTotOutside[0]==0 && S1sTotOutside[1]==0";	//No energy deposit in the veto in the region of the two most energetic S1 peaks 	
	
	TCut cutData_Kr85	= cutData_Kr85_1 && cutData_Kr85_2 && cutData_Kr85_3 && cutData_Kr85_4 && cutData_Kr85_5 && cutData_Kr85_6 && cutData_Kr85_7;

/*	// Kr85
	TCut cutKr85_1 = "NbS1Peaks>1";
	TCut cutKr85_2 = "S1sCoin[0]>4 && S1sCoin[1]>4";
	TCut cutKr85_3 = "S1sTotOutside[0]==0 && S1sTotOutside[1]==0";
	TCut cutKr85_4 = "S2sTot[0]>1000";
	TCut cutKr85_5 = "(S1sPeak[0]-S1sPeak[1])/100>0.2 && (S1sPeak[0]-S1sPeak[1])/100<10.0";
	TCut cutKr85_6 = "S1sTot[0]>300 && S1sTot[0]<1200";
	TCut cutKr85_7 = "S1sTot[1]>24 && S1sTot[1]<230";
	TCut cutKr85 = cutKr85_1 && cutKr85_2 && cutKr85_3 && cutKr85_4 && cutKr85_5 && cutKr85_6 && cutKr85_7;
*/
	TCut cutData_AlphaBox 	= "S1sTotC0>16e3 && S1sTotC0<24e3  &&  S2sTotBotC0>50e3 && S2sTotBotC0<80e3"; 
	
	////////////////////////////////////////////////////////////////////////////
	double r0	= 0.;			
	double r1	= 154.0;
	double z2	= 0;
	double z1	= -306.5;
		
	double TopVeto_IR	= 0.	;
	double TopVeto_OR	= 205.0	;
	double TopVetoZ		= 68.5	;
	
	double BotVetoIR	= 0.	;
	double BotVetoOR	= 205.0	;
	double BotVetoZ		= -378.	;
	
	double SideVetoIR	= 160.	;
	double SideVetoOR	= 205.	;
	double SideVetoZ2	= 68.5	;
	double SideVetoZ1	= -378.	;
	
  	double density_LXe = 2.85; // *g/cm3
  
  	double mass_FV = TMath::Pi() * (pow(r1,2) - pow(r0,2)) * TMath::Abs(z1 - z2) * density_LXe /1e6;
  	//cout << "mass of LXe in target volume = " << mass_FV << " kg" <<endl;
	

	//------ FIDUCIAL VOLUME CUTS
	
	// FV50
	double r_cut_FV50 		= 12;
	double rad_FV50 		= r1 - r_cut_FV50;
	double z1_cut_FV50 		= 10;
	double z2_cut_FV50 		= 10;
	double corner_cut_FV50 	= 30;

	double height_FV50 = TMath::Abs(z1+z1_cut_FV50)-TMath::Abs(z2-z2_cut_FV50);

	double corn_r_FV50 			= rad_FV50 - corner_cut_FV50;
	double corn_z_up_max_FV50	= z2-z1_cut_FV50;
	double corn_z_up_min_FV50 	= z2-z1_cut_FV50 - corner_cut_FV50;
	double corn_z_down_max_FV50 = z1+z1_cut_FV50 + corner_cut_FV50;
	double corn_z_down_min_FV50 = z1+z1_cut_FV50;
	double corner_cut2_FV50 	= TMath::Power(corner_cut_FV50,2);
	
	// middle cylindrical cut
	TCut cut_FV50_a1	= Form("sqrt(pow(xp,2)+pow(yp,2)) < %g", rad_FV50); 
	TCut cut_FV50_a2	= Form("zp < %g", corn_z_up_min_FV50);
	TCut cut_FV50_a3	= Form("zp > %g", corn_z_down_max_FV50);
	TCut cut_FV50_a		= cut_FV50_a1 && cut_FV50_a2 && cut_FV50_a3;
  	// upper cylindrical cut
	TCut cut_FV50_b1	= Form("sqrt(pow(xp,2)+pow(yp,2)) < %g", corn_r_FV50);
	TCut cut_FV50_b2	= Form("zp < %g", corn_z_up_max_FV50);
	TCut cut_FV50_b3	= Form("zp > %g", corn_z_up_min_FV50);
	TCut cut_FV50_b4	= cut_FV50_b1 && cut_FV50_b2 && cut_FV50_b3;
	// upper corner cut
	TCut cut_FV50_b5	= Form("pow((sqrt(pow(xp,2)+pow(yp,2))-%g),2) + pow((zp-%g),2) < %g", corn_r_FV50, corn_z_up_min_FV50, corner_cut2_FV50);
  	TCut cut_FV50_b		= cut_FV50_b4 || cut_FV50_b5;
	// lower cylindrical cut
	TCut cut_FV50_c1	= Form("sqrt(pow(xp,2)+pow(yp,2)) < %g", corn_r_FV50);
	TCut cut_FV50_c2	= Form("zp < %g", corn_z_down_max_FV50);
	TCut cut_FV50_c3	= Form("zp > %g", corn_z_down_min_FV50);
	TCut cut_FV50_c4	= cut_FV50_c1 && cut_FV50_c2 && cut_FV50_c3;
	// lower corner cut
	TCut cut_FV50_c5	= Form("pow((sqrt(pow(xp,2)+pow(yp,2))-%g),2) + pow((zp-%g),2) < %g", corn_r_FV50, corn_z_down_max_FV50, corner_cut2_FV50);
  	TCut cut_FV50_c		= cut_FV50_c4 || cut_FV50_c5;
	
  	TCut cut_FV50		= cut_FV50_a || cut_FV50_b || cut_FV50_c;
	
	double volume_FV50	= TMath::Pi()*pow(rad_FV50,2)*height_FV50-(4*TMath::Pi())*((1-TMath::Pi()/4)*pow(corner_cut_FV50,2)*rad_FV50-(5./6-TMath::Pi()/4)*pow(corner_cut_FV50,3));
	double mass_FV50	= density_LXe * volume_FV50 / 1e6;
	//cout << "Mass FV50 = " << mass_FV50 << endl;
	
	// FV30
	double r_cut_FV30 		= 32;
	double rad_FV30 		= r1 - r_cut_FV30;
	double z1_cut_FV30 		= 32;
	double z2_cut_FV30 		= 32;
	double corner_cut_FV30 	= 52;

	double height_FV30 = TMath::Abs(z1+z1_cut_FV30)-TMath::Abs(z2-z2_cut_FV30);

	double corn_r_FV30 			= rad_FV30 - corner_cut_FV30;
	double corn_z_up_max_FV30	= z2-z1_cut_FV30;
	double corn_z_up_min_FV30 	= z2-z1_cut_FV30 - corner_cut_FV30;
	double corn_z_down_max_FV30 = z1+z1_cut_FV30 + corner_cut_FV30;
	double corn_z_down_min_FV30 = z1+z1_cut_FV30;
	double corner_cut2_FV30 	= TMath::Power(corner_cut_FV30,2);
	
	// middle cylindrical cut
	TCut cut_FV30_a1	= Form("sqrt(pow(xp,2)+pow(yp,2)) < %g", rad_FV30); 
	TCut cut_FV30_a2	= Form("zp < %g", corn_z_up_min_FV30);
	TCut cut_FV30_a3	= Form("zp > %g", corn_z_down_max_FV30);
	TCut cut_FV30_a		= cut_FV30_a1 && cut_FV30_a2 && cut_FV30_a3;
  	// upper cylindrical cut
	TCut cut_FV30_b1	= Form("sqrt(pow(xp,2)+pow(yp,2)) < %g", corn_r_FV30);
	TCut cut_FV30_b2	= Form("zp < %g", corn_z_up_max_FV30);
	TCut cut_FV30_b3	= Form("zp > %g", corn_z_up_min_FV30);
	TCut cut_FV30_b4	= cut_FV30_b1 && cut_FV30_b2 && cut_FV30_b3;
	// upper corner cut
	TCut cut_FV30_b5	= Form("pow((sqrt(pow(xp,2)+pow(yp,2))-%g),2) + pow((zp-%g),2) < %g", corn_r_FV30, corn_z_up_min_FV30, corner_cut2_FV30);
  	TCut cut_FV30_b		= cut_FV30_b4 || cut_FV30_b5;
	// lower cylindrical cut
	TCut cut_FV30_c1	= Form("sqrt(pow(xp,2)+pow(yp,2)) < %g", corn_r_FV30);
	TCut cut_FV30_c2	= Form("zp < %g", corn_z_down_max_FV30);
	TCut cut_FV30_c3	= Form("zp > %g", corn_z_down_min_FV30);
	TCut cut_FV30_c4	= cut_FV30_c1 && cut_FV30_c2 && cut_FV30_c3;
	// lower corner cut
	TCut cut_FV30_c5	= Form("pow((sqrt(pow(xp,2)+pow(yp,2))-%g),2) + pow((zp-%g),2) < %g", corn_r_FV30, corn_z_down_max_FV30, corner_cut2_FV30);
  	TCut cut_FV30_c		= cut_FV30_c4 || cut_FV30_c5;
		
	//TCut cut_FV30		= cut_FV30_a || cut_FV30_b || cut_FV30_c;

	// NEW 30 KG CUT
	//TCut cut_FV30 = TCut("(pow((((zp+21.5)+155)/(112.)),2)+pow(((xp*xp+yp*yp)/(19274.)),2))<1");
	TCut cut_FV30 = TCut("(pow(((-zp-150)/(110.)),2)+pow(((xp*xp+yp*yp)/(19481.)),2))<1");

	double volume_FV30	= TMath::Pi()*pow(rad_FV30,2)*height_FV30-(4*TMath::Pi())*((1-TMath::Pi()/4)*pow(corner_cut_FV30,2)*rad_FV30-(5./6-TMath::Pi()/4)*pow(corner_cut_FV30,3));
	double mass_FV30	= density_LXe * volume_FV30 / 1e6;
	//cout << "Mass FV30 = " << mass_FV30 << endl;

	//------ boundary for FV50
	float x50_a[202],y50_a[202];//cm
	x50_a[0] = 0;
	y50_a[0] = (z2-z1_cut_FV50)/10;
	x50_a[201] = 0;
	y50_a[201] = (z1+z2_cut_FV50)/10;

	for (int i=1;i<=100;i++){
		x50_a[i] 		= (corn_r_FV50+corner_cut_FV50*(i-1)/99.)*(corn_r_FV50+corner_cut_FV50*(i-1)/99.)/100;
		y50_a[i] 		= (z2-z1_cut_FV50 - corner_cut_FV50+corner_cut_FV50*TMath::Sqrt(1-TMath::Power((i-1)/99.,2)))/10;
		x50_a[i+100]	= (corn_r_FV50+corner_cut_FV50*(100-i)/99.)*(corn_r_FV50+corner_cut_FV50*(100-i)/99.)/100;
		y50_a[i+100]	= (z1+z2_cut_FV50 + corner_cut_FV50 - corner_cut_FV50*TMath::Sqrt(1-TMath::Power((100-i)/99.,2)))/10;
	}

	TGraph *boundary_FV50 = new TGraph(202,x50_a,y50_a);
			boundary_FV50->SetLineColor(1);
			boundary_FV50->SetLineStyle(7);
			boundary_FV50->SetLineWidth(3);
	
	//------ boundary for FV30
	float x30_a[202],y30_a[202];//cm
	x30_a[0] = 0;
	y30_a[0] = (z2-z1_cut_FV30)/10;
	x30_a[201] = 0;
	y30_a[201] = (z1+z2_cut_FV30)/10;

	for (int i=1;i<=100;i++){
		x30_a[i] 		= (corn_r_FV30+corner_cut_FV30*(i-1)/99.)*(corn_r_FV30+corner_cut_FV30*(i-1)/99.)/100;
		y30_a[i] 		= (z2-z1_cut_FV30 - corner_cut_FV30+corner_cut_FV30*TMath::Sqrt(1-TMath::Power((i-1)/99.,2)))/10;
		x30_a[i+100]	= (corn_r_FV30+corner_cut_FV30*(100-i)/99.)*(corn_r_FV30+corner_cut_FV30*(100-i)/99.)/100;
		y30_a[i+100]	= (z1+z2_cut_FV30 + corner_cut_FV30 - corner_cut_FV30*TMath::Sqrt(1-TMath::Power((100-i)/99.,2)))/10;
	}

	TGraph *boundary_FV30 = new TGraph(202,x30_a,y30_a);
			boundary_FV30->SetLineColor(1);
			boundary_FV30->SetLineStyle(7);
			boundary_FV30->SetLineWidth(2);

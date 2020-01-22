	// ALIAS

	// drift time and Z
	T1->SetAlias("dt",		"(S2sPeak[0]-S1sPeak[0])/100.");	//microsec 
	T1->SetAlias("zp",		"dt *(-1.85)"); 					//mm
	T1->SetAlias("Z_cm", 	"zp/10");							//cm

	// COMBINED ENERGY
	T1->SetAlias("CE","(cS2sTotBottom[0]/132.5381+cS1sTot[0])/4.4019352");

	// SVM
	T1->SetAlias("xp_svm", 	"cS2sPosSvm[0][0]");
	T1->SetAlias("X_svm", 	"cS2sPosSvm[0][0]/10");
	T1->SetAlias("yp_svm", 	"cS2sPosSvm[0][1]");
	T1->SetAlias("Y_svm", 	"cS2sPosSvm[0][1]/10");
	T1->SetAlias("R_svm", 	"sqrt(xp_svm*xp_svm+yp_svm*yp_svm)/10");
	T1->SetAlias("A_svm",	"(pow(xp_svm,2)+pow(yp_svm,2))*TMath::Pi()/100");
	T1->SetAlias("Theta_svm","TMath::ATan2(yp_svm,-xp_svm)*180/TMath::Pi()");
	// NN
	T1->SetAlias("xp_nn", 	"cS2sPosNn[0][0]");
	T1->SetAlias("X_nn", 	"cS2sPosNn[0][0]/10");
	T1->SetAlias("yp_nn", 	"cS2sPosNn[0][1]");
	T1->SetAlias("Y_nn", 	"cS2sPosNn[0][1]/10");
	T1->SetAlias("Z_nn", 	"cS2sPosNn[0][2]/10");
	T1->SetAlias("R_nn", 	"sqrt(xp_nn*xp_nn+yp_nn*yp_nn)/10");
	T1->SetAlias("A_nn",	"(pow(xp_nn,2)+pow(yp_nn,2))*TMath::Pi()/100");
	T1->SetAlias("Theta_nn","TMath::ATan2(yp_nn,-xp_nn)*180/TMath::Pi()");
	// Chi2 minimization
	T1->SetAlias("xp_chi", 	"cS2sPosChi2[0][0]");
	T1->SetAlias("X_chi", 	"cS2sPosChi2[0][0]/10");
	T1->SetAlias("yp_chi", 	"cS2sPosChi2[0][1]");
	T1->SetAlias("Y_chi", 	"cS2sPosChi2[0][1]/10");
	T1->SetAlias("R_chi", 	"sqrt(xp_chi*xp_chi+yp_chi*yp_chi)/10");
	T1->SetAlias("A_chi",	"(pow(xp_chi,2)+pow(yp_chi,2))*TMath::Pi()/100");
	T1->SetAlias("Theta_chi","TMath::ATan2(yp_chi,-xp_chi)*180/TMath::Pi()");
/*	// NN new
	T1->SetAlias("xp_nn1", 	"Xnn[0]");
	T1->SetAlias("X_nn1", 	"Xnn[0]/10");
	T1->SetAlias("yp_nn1", 	"Ynn[0]");
	T1->SetAlias("Y_nn1", 	"Ynn[0]/10");
	T1->SetAlias("R_nn1", 	"sqrt(xp_nn1*xp_nn1+yp_nn1*yp_nn1)/10");
	T1->SetAlias("A_nn1",	"(pow(xp_nn1,2)+pow(yp_nn1,2))*TMath::Pi()/100");
	T1->SetAlias("Theta_nn1","TMath::ATan2(yp_nn1,-xp_nn1)*180/TMath::Pi()");
*/
	T1->SetAlias("xp", 		"Xnn[0]");
	T1->SetAlias("yp", 		"Ynn[0]");

	// corrected S1
	T1->SetAlias("S1sTotC0",	"cS1sTot[0]");
	T1->SetAlias("S1sTotC1",	"cS1sTot[1]");
	T1->SetAlias("S2sTotBotC0",	"cS2sTotBottom[0]");

	// delay time
	T1->SetAlias("delayT",	"(S1sPeak[0]-S1sPeak[1])/100");
	
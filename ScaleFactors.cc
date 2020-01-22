	double livetime_tot_days = livetime_tot / 3600 / 24;
	cout <<"Total Livetime = "<< livetime_tot <<" sec = "<< livetime_tot_days <<" days"<< endl;
	double rescaleF_mHz		= 1 / livetime_tot *1000;
	
	double mass_FV 			= 65.0829; // kg
	double rescaleF_DRU		= 1/ livetime_tot_days / mass_FV / binwidth_S1;
	double rescaleFa_DRU	= 1/ livetime_tot_days / mass_FV / binwidth_keVa;

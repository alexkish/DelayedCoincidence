	char *dataName 		= "run07";
	char *rootFolder 	= "/Volumes/xen04/data/xenon100/root/run_10";	// idarkx
	char *outFolder 	= "/Users/alex/analysis/DelayedCoincidence/plots/run_10";

	//char *rootFolder_T3xy 	= "/Volumes/xen01/data/xenon100/root/run_10/T3xy";	// idarkx
	char *logFolder 		= "/Users/alex/analysis/DelayedCoincidence/filelists";

	ifstream logfile;
	
	char logfile_char[200];

	//sprintf(logfile_char,"%s/FileList_run07_BG_0.4.1.dat", logFolder);
	//sprintf(logfile_char,"%s/FileList_run07_Class1.dat", logFolder);
	//sprintf(logfile_char,"%s/FileList_run08_BG_0.4.2.dat", logFolder);
	//sprintf(logfile_char,"%s/FileList_run08_Class0.dat", logFolder);
	//sprintf(logfile_char,"%s/FileList_run10_BG_0.4.2.dat", logFolder);
	//sprintf(logfile_char,"%s/FileList_run10_BG_0.4.4.dat", logFolder);
	//sprintf(logfile_char,"%s/FileList_run10_DM_4.4kV_1.dat", logFolder);

	logfile.open(logfile_char);

	int nf = 0;
	
	char dataset[200], date[200], time[200];
	double livetime;
	double livetime_tot = 0;

	const double mass_LXe = 62.0; //kg
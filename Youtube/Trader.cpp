#include "pch.h"
#include "zorro.h"
#include "bots.h"


DLLFUNC void run()
{
	assetList("history\\bovespa.csv");
	BarPeriod = 1440;
	NumYears = 5;
	MaxLong = MaxShort = -1;
	LookBack = 350;
	set(LOGFILE + PARAMETERS + FACTORS);
	BarMode = BR_LOCAL + BR_WEEKEND + BR_SLEEP;
	NumWFOCycles = 7;
	NumCores = 7;
	Capital = 50000;
	BarOffset = 605;
	string selectedAsset;
	while (selectedAsset = (loop(Assets)))
	{


		asset(selectedAsset);
		
		MediasMoveis();


	}



}
#pragma once
#include "RunConfig.h"
#include "WindCrystal.h"
#include "WaterCrystal.h"
#include "FireCrystal.h"
#include "EarthCrystal.h"

class FourJobFiestaBuilder 
{
private:
	WindCrystal windCrystal{};
	WaterCrystal waterCrystal{};
	FireCrystal fireCrystal{};
	EarthCrystal earthCrystal{};

	Jobs GetJob(Crystals crystal);
	void DisplayRun(RunConfig runConfig);
public:
	void GenerateJob(RunConfig runDetails);
	void GenerateFullJobSet(RunConfig runDetails);

};
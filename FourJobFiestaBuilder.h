#pragma once
#include "RunConfig.h"
#include "WindCrystal.h"
#include "WaterCrystal.h"
#include "FireCrystal.h"
#include "EarthCrystal.h"
#include "Helper.h"

class FourJobFiestaBuilder 
{
private:
	WindCrystal windCrystal{};
	WaterCrystal waterCrystal{};
	FireCrystal fireCrystal{};
	EarthCrystal earthCrystal{};

	ConsoleFormatter Console{};
	Helper helper{};

	std::vector<Crystals> NormalRun{WIND, WATER, FIRE, EARTH};
	std::vector<std::vector<Crystals>> TyphoonRun{{WIND}, { WIND, WATER }, { WIND, WATER, FIRE }, { WIND, WATER, FIRE, EARTH }};
	std::vector<std::vector<Crystals>> VolcanoRun{{ WIND, WATER, FIRE, EARTH }, { WATER, FIRE, EARTH }, { FIRE, EARTH }, { EARTH } };
	std::vector<std::vector<Crystals>> MeteorRun{{ WIND, WATER, FIRE, EARTH }, { WIND, WATER, FIRE, EARTH }, { WIND, WATER, FIRE, EARTH }, { WIND, WATER, FIRE, EARTH } };

	Jobs GetJob(Crystals crystal, JobCompositionTypes jobComp, bool allowDupes, bool allowBerserkers, std::vector<Jobs> previousJobs);
	Crystals GetCrystal(RunTypes typeofRun, int round);
	void DisplayRun(RunConfig runConfig);

	RunTypes GetRunType();
	JobCompositionTypes GetJobType(RunTypes runType);
	bool AllowDuplicates();
	bool AllowBerserker();

public:
	void GenerateJob(RunConfig runDetails);
	void GenerateFullJobSet(RunConfig runDetails);

	void BuildRun();

};
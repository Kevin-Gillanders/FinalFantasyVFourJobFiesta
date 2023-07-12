#pragma once
#include "FinalFantasyVEnums.h"
#include <vector>

class RunConfig {
public:
	RunConfig(Crystals currentCrystal, std::vector<Jobs>& currentJobs, RunTypes runType, JobCompositionTypes jobComp, std::vector<AdvancedOptions>& advancedOptionsList);
	void AddJob(Jobs jobToAdd);
	void PrintRunConfig();
	Crystals CurrentCrystal;
	std::vector<Jobs> CurrentJobs;
	RunTypes RunType;
	JobCompositionTypes JobComp;
	std::vector<AdvancedOptions> AdvancedOptionsList;

};
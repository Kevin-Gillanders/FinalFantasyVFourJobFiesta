#include "RunConfig.h"

RunConfig::RunConfig(Crystals currentCrystal, std::vector<Jobs>& currentJobs, RunTypes runType, JobCompositionTypes jobComp, std::vector<AdvancedOptions>& advancedOptionsList)
{
	CurrentCrystal = currentCrystal;
	CurrentJobs = currentJobs;
	RunType = runType;
	JobComp = jobComp;
	AdvancedOptionsList = advancedOptionsList;	
}

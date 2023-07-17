#include "RunConfig.h"

RunConfig::RunConfig(Crystals currentCrystal, std::vector<Jobs>& currentJobs, RunTypes runType, JobCompositionTypes jobComp, bool allowDuplicates, bool allowBerserkers, std::vector<AdvancedOptions>& advancedOptionsList)
{
	CurrentCrystal = currentCrystal;
	CurrentJobs = currentJobs;
	RunType = runType;
	JobComp = jobComp;
	AdvancedOptionsList = advancedOptionsList;	
	AllowBerserkers = allowBerserkers;
	AllowDuplicates = allowDuplicates;
}

void RunConfig::AddJob(Jobs jobToAdd)
{
	CurrentJobs.push_back(jobToAdd);
}

void RunConfig::PrintRunConfig()
{
}

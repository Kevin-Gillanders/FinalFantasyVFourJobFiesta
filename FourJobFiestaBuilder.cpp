#include "FourJobFiestaBuilder.h"


void FourJobFiestaBuilder::GenerateJob(RunConfig runDetails)
{
	//Crystals x = runDetails.CurrentCrystal;
	//JobCompositionTypes jobComp = runDetails.JobComp;

	//Jobs job = GetJob(x, jobComp);
}

void FourJobFiestaBuilder::GenerateFullJobSet(RunConfig runDetails)
{
	RunTypes runType = runDetails.RunType;
	JobCompositionTypes jobComp = runDetails.JobComp;

	bool allowDupes = runDetails.AllowDuplicates;
	bool allowBerserkers = runDetails.AllowBerserkers;
	std::vector<Jobs> jobsList{};
	int _750 = 0, no750 = 0;
	//bool allowBerserker = runDetails
	int amountOfJobs = 4;

	if ((runType == METEOR && jobComp != TEAMMETEOR) || (runType != METEOR && jobComp == TEAMMETEOR))
		throw;
	int jobs = 0;
	while(jobs < amountOfJobs)
	{
		Jobs jobPicked{};

		if (jobComp == CLASSICJOBS)
		{
			int amountOfClassicJobs = 6;
			int classicIdx = windCrystal.GetRandom(amountOfClassicJobs) + 1;

			if (amountOfClassicJobs == classicIdx)
				jobPicked = GetJob(WATER, jobComp, allowDupes, allowBerserkers, jobsList);
			else
				jobPicked = GetJob(WIND, jobComp, allowDupes, allowBerserkers, jobsList);
			jobs++;
		}
		else if (jobComp == TEAM375)
		{
			int rand = windCrystal.GetRandom(2);
			if (rand == 0)
			{
				if (_750 != 2)
				{
					jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAM750, allowDupes, allowBerserkers, jobsList);
					_750++;
				}
				else
				{
					jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAMNO750, allowDupes, allowBerserkers, jobsList);
					no750++;
				}
			}
			else
			{
				if (no750 != 2)
				{
					jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAMNO750, allowDupes, allowBerserkers, jobsList);
					no750++;
				}
				else
				{
					jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAM750, allowDupes, allowBerserkers, jobsList);
					_750++;
				}
			}
			jobs++;
		}
		else
		{
			jobPicked = GetJob(GetCrystal(runType, jobs), jobComp, allowDupes, allowBerserkers, jobsList);
			jobs++;
		}
		jobsList.push_back(jobPicked);
	}
}

Jobs FourJobFiestaBuilder::GetJob(Crystals crystal, JobCompositionTypes jobComp, bool allowDupes, bool allowBerserkers, std::vector<Jobs> previousJobs)
{
	Jobs jobPicked;
	switch (crystal)
	{
	case WIND:
		jobPicked = windCrystal.GetValidJob(jobComp, allowDupes,allowBerserkers, previousJobs);
		windCrystal.DisplayJobs(jobPicked);
		break;
	case WATER:
		jobPicked = waterCrystal.GetValidJob(jobComp, allowDupes, allowBerserkers, previousJobs);
		waterCrystal.DisplayJobs(jobPicked);
		break;
	case FIRE:
		jobPicked = fireCrystal.GetValidJob(jobComp, allowDupes, allowBerserkers, previousJobs);
		fireCrystal.DisplayJobs(jobPicked);
		break;
	case EARTH:
		jobPicked = earthCrystal.GetValidJob(jobComp, allowDupes, allowBerserkers, previousJobs);
		earthCrystal.DisplayJobs(jobPicked);
		break;
	default:
		throw;
		break;
	}

	return jobPicked;
}

Crystals FourJobFiestaBuilder::GetCrystal(RunTypes typeofRun, int round)
{
	Crystals pickedCrystal{};
	std::vector<Crystals> crystalsToPickFrom{};
	int idx = 0; 
	switch (typeofRun)
	{
	case REGULAR:
		pickedCrystal = NormalRun[round];
		break;
	case TYPHOON:
		crystalsToPickFrom = TyphoonRun[round];
		idx = windCrystal.GetRandom(crystalsToPickFrom.size());
		pickedCrystal = crystalsToPickFrom[idx];
		break;
	case VOLCANO:
		crystalsToPickFrom = VolcanoRun[round];
		idx = windCrystal.GetRandom(crystalsToPickFrom.size());
		pickedCrystal = crystalsToPickFrom[idx];
		break;
	case METEOR:
		crystalsToPickFrom = MeteorRun[round];
		idx = windCrystal.GetRandom(crystalsToPickFrom.size());
		pickedCrystal = crystalsToPickFrom[idx];
		break;
	default:
		throw;
		break;
	}


	return pickedCrystal;
}

void FourJobFiestaBuilder::DisplayRun(RunConfig runConfig)
{
}


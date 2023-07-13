#include "FourJobFiestaBuilder.h"


void FourJobFiestaBuilder::GenerateJob(RunConfig runDetails)
{
	Crystals x = runDetails.CurrentCrystal;
	JobCompositionTypes jobComp = runDetails.JobComp;

	Jobs job = GetJob(x, jobComp);
}

void FourJobFiestaBuilder::GenerateFullJobSet(RunConfig runDetails)
{
	RunTypes runType = runDetails.RunType;
	JobCompositionTypes jobComp = runDetails.JobComp;
	int _750 = 0, no750 = 0;
	//bool allowBerserker = runDetails
	int amountOfJobs = 4;

	if ((runType == METEOR && jobComp != TEAMMETEOR) || (runType != METEOR && jobComp == TEAMMETEOR))
		throw;
	for (int jobs = 0; jobs < amountOfJobs; jobs++)
	{
		if (jobComp == CLASSICJOBS)
		{
			int amountOfClassicJobs = 6;
			int classicIdx = windCrystal.GetRandom(amountOfClassicJobs) + 1;

			if (amountOfClassicJobs == classicIdx)
				GetJob(WATER, jobComp);
			else
				GetJob(WIND, jobComp);
		}
		else if (jobComp == TEAM375)
		{
			int rand = windCrystal.GetRandom(2);
			if (rand == 0)
			{
				if (_750 != 2)
				{
					GetJob(GetCrystal(REGULAR, jobs), TEAM750);
					_750++;
				}
				else
				{
					GetJob(GetCrystal(REGULAR, jobs), TEAMNO750);
					no750++;
				}
			}
			else
			{
				if (no750 != 2)
				{
					GetJob(GetCrystal(REGULAR, jobs), TEAMNO750);
					no750++;
				}
				else
				{
					GetJob(GetCrystal(REGULAR, jobs), TEAM750);
					_750++;
				}
			}
		}
		else
		{
			GetJob(GetCrystal(runType, jobs), jobComp);
		}
	}
}

Jobs FourJobFiestaBuilder::GetJob(Crystals crystal, JobCompositionTypes jobComp)
{
	Jobs jobPicked;
	switch (crystal)
	{
	case WIND:
		jobPicked = windCrystal.GetValidJob(jobComp);
		windCrystal.DisplayJobs(jobPicked);
		break;
	case WATER:
		jobPicked = waterCrystal.GetValidJob(jobComp);
		waterCrystal.DisplayJobs(jobPicked);
		break;
	case FIRE:
		jobPicked = fireCrystal.GetValidJob(jobComp);
		fireCrystal.DisplayJobs(jobPicked);
		break;
	case EARTH:
		jobPicked = earthCrystal.GetValidJob(jobComp);
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


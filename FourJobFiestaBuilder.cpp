#include "FourJobFiestaBuilder.h"


void FourJobFiestaBuilder::GenerateJob(RunConfig runDetails)
{
	Crystals x = runDetails.CurrentCrystal;

	Jobs job = GetJob(x);
}

void FourJobFiestaBuilder::GenerateFullJobSet(RunConfig runDetails)
{
}

Jobs FourJobFiestaBuilder::GetJob(Crystals crystal)
{
	Jobs jobPicked;
	switch (crystal)
	{
	case WIND:
		jobPicked = windCrystal.GetValidJob();
		windCrystal.DisplayJobs(jobPicked);
		break;
	case WATER:
		jobPicked = waterCrystal.GetValidJob();
		waterCrystal.DisplayJobs(jobPicked);
		break;
	case FIRE:
		jobPicked = fireCrystal.GetValidJob();
		fireCrystal.DisplayJobs(jobPicked);
		break;
	case EARTH:
		jobPicked = earthCrystal.GetValidJob();
		earthCrystal.DisplayJobs(jobPicked);
		break;
	default:
		throw;
		break;
	}

	return jobPicked;
}

void FourJobFiestaBuilder::DisplayRun(RunConfig runConfig)
{
}


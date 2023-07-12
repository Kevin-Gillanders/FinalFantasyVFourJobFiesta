#include "FireCrystal.h"

void FireCrystal::SetValidJobs()
{
	ValidJobs.push_back(Jobs::NINJA);
	ValidJobs.push_back(Jobs::HUNTER);
	ValidJobs.push_back(Jobs::GEOMANCER);
	ValidJobs.push_back(Jobs::TRAINER);
	ValidJobs.push_back(Jobs::BARD);

}

FireCrystal::FireCrystal()
{
	SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_RED;
	CrystalDefinition = Crystals::FIRE;
	CrystalName = "Fire";
}


void FireCrystal::DisplayJobs(Jobs jobToDisplay)
{

		std::string jobName;

		switch (jobToDisplay)
		{
		case NINJA:
			jobName = "Ninja";
			break;
		case HUNTER:
			jobName = "Hunter";
			break;
		case GEOMANCER:
			jobName = "Geomancer";
			break;
		case TRAINER:
			jobName = "Trainer";
			break;
		case BARD:
			jobName = "Bard";
			break;
		default:
			throw;
			break;
		}

		PrintMessage(jobName);
	

}

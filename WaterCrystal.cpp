#include "WaterCrystal.h"

void WaterCrystal::SetValidJobs()
{
	ValidJobs.push_back(Jobs::REDMAGE);
	ValidJobs.push_back(Jobs::TIMEMAGE);
	ValidJobs.push_back(Jobs::SUMMONER);
	ValidJobs.push_back(Jobs::BERSERKER);
	ValidJobs.push_back(Jobs::SORCERER);
	ValidJobs.push_back(Jobs::MIME);
}

WaterCrystal::WaterCrystal()
{
    SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_BLUE;
	CrystalDefinition = Crystals::WATER;
	CrystalName = "Water";
}


void WaterCrystal::DisplayJobs(Jobs jobToDisplay)
{
    std::string jobName;

	switch (jobToDisplay)
	{

	case REDMAGE:
		jobName = "Red Mage";
		break;
	case TIMEMAGE:
		jobName = "Time Mage";
		break;
	case SUMMONER:
		jobName = "Summoner";
		break;
	case BERSERKER:
		jobName = "Berserker";
		break;
	case SORCERER:
		jobName = "Sorcerer";
		break;
	case MIME:
		jobName = "Mime";
		break;
	default:
		throw;
		break;
	}
    PrintMessage(jobName);
}

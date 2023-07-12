#include "EarthCrystal.h"

void EarthCrystal::SetValidJobs()
{
	ValidJobs.push_back(Jobs::DRAGOON);
	ValidJobs.push_back(Jobs::SAMURAI);
	ValidJobs.push_back(Jobs::DANCER);
	ValidJobs.push_back(Jobs::CHEMIST);

}

EarthCrystal::EarthCrystal()
{
	SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_GREEN;
	CrystalDefinition = Crystals::EARTH;
	CrystalName = "Earth";
}


void EarthCrystal::DisplayJobs(Jobs jobToDisplay)
{
	std::string jobName;

	switch (jobToDisplay)
	{
	case DRAGOON:
		jobName = "Dragoon";
		break;
	case SAMURAI:
		jobName = "Samurai";
		break;
	case DANCER:
		jobName = "Dancer";
		break;
	case CHEMIST:
		jobName = "Chemist";
		break;
	default:
		throw;
		break;
	}
	
	PrintMessage(jobName);
}

#include "EarthCrystal.h"

void EarthCrystal::SetValidJobs()
{
	ValidJobs.push_back(Jobs::DRAGOON);
	ValidJobs.push_back(Jobs::SAMURAI);
	ValidJobs.push_back(Jobs::DANCER);
	ValidJobs.push_back(Jobs::CHEMIST);

	//750
	_750Jobs.push_back(Jobs::CHEMIST);
	_750Jobs.push_back(Jobs::DANCER);

	//No 750
	No750Jobs.push_back(Jobs::SAMURAI);
	No750Jobs.push_back(Jobs::DRAGOON);

	OnionJobs.push_back(Jobs::DRAGOON);

}

EarthCrystal::EarthCrystal()
{
	SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_GREEN;
	CrystalDefinition = Crystals::EARTH;
	CrystalName = "Earth";
}

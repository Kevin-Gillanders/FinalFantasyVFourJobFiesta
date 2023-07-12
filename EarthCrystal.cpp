#include "EarthCrystal.h"

void EarthCrystal::SetValidJobs()
{
}

EarthCrystal::EarthCrystal()
{
	SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_GREEN;
	CrystalDefinition = Crystals::EARTH;
	CrystalName = "Earth";
}

Jobs EarthCrystal::GetValidJob()
{
	return Jobs();
}

void EarthCrystal::DisplayJobs()
{

}

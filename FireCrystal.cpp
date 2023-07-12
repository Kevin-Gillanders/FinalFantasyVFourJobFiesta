#include "FireCrystal.h"

void FireCrystal::SetValidJobs()
{

}

FireCrystal::FireCrystal()
{
	SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_RED;
	CrystalDefinition = Crystals::FIRE;
	CrystalName = "Fire";
}

Jobs FireCrystal::GetValidJob()
{
	return Jobs();
}

void FireCrystal::DisplayJobs()
{
}

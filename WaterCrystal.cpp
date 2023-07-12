#include "WaterCrystal.h"

void WaterCrystal::SetValidJobs()
{

}

WaterCrystal::WaterCrystal()
{
    SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_BLUE;
	CrystalDefinition = Crystals::WATER;
	CrystalName = "Water";
}

Jobs WaterCrystal::GetValidJob()
{
    return Jobs();
}

void WaterCrystal::DisplayJobs()
{
}

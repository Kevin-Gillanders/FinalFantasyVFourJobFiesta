

#include "WindCrystal.h"

WindCrystal::WindCrystal()
{
    SetValidJobs();
    CrystalColour = ConsoleColour::BRIGHT_CYAN;
    CrystalDefinition = Crystals::WIND;
    CrystalName = "Wind";
}

void WindCrystal::DisplayJobs()
{
}

void WindCrystal::SetValidJobs()
{
    ValidJobs.push_back(Jobs::KNIGHT);
    ValidJobs.push_back(Jobs::MONK);
    ValidJobs.push_back(Jobs::THIEF);
    ValidJobs.push_back(Jobs::WHITEMAGE);
    ValidJobs.push_back(Jobs::BLACKMAGE);
    ValidJobs.push_back(Jobs::BLUEMAGE);
}

Jobs WindCrystal::GetValidJob()
{
    return Jobs();
}

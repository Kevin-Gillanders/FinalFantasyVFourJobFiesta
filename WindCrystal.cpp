

#include "WindCrystal.h"

WindCrystal::WindCrystal()
{
    SetValidJobs();
    CrystalColour = ConsoleColour::BRIGHT_CYAN;
    CrystalDefinition = Crystals::WIND;
    CrystalName = "Wind";
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


void WindCrystal::DisplayJobs(Jobs jobToDisplay)
{
    std::string jobName;

    switch (jobToDisplay)
    {
    case FREELANCER:
        jobName = "Freelancer";
        break;
    case KNIGHT:
        jobName = "Knight";
        break;
    case MONK:
        jobName = "Monk";
        break;
    case THIEF:
        jobName = "Thief";
        break;
    case WHITEMAGE:
        jobName = "White Mage";
        break;
    case BLACKMAGE:
        jobName = "Black Mage";
        break;
    case BLUEMAGE:
        jobName = "Blue Mage";
        break;
    default:
        break;
    }

    PrintMessage(jobName);
}

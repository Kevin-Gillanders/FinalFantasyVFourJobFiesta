

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

    //750
    _750Jobs.push_back(Jobs::WHITEMAGE);
    _750Jobs.push_back(Jobs::BLACKMAGE);
    _750Jobs.push_back(Jobs::BLUEMAGE);

    //No 750
    No750Jobs.push_back(Jobs::THIEF);
    No750Jobs.push_back(Jobs::MONK);
    No750Jobs.push_back(Jobs::KNIGHT);

    ClassicJobs.push_back(Jobs::KNIGHT);
    ClassicJobs.push_back(Jobs::THIEF);
    ClassicJobs.push_back(Jobs::MONK);
    ClassicJobs.push_back(Jobs::WHITEMAGE);
    ClassicJobs.push_back(Jobs::BLACKMAGE);

    OnionJobs.push_back(Jobs::BLACKMAGE);
    OnionJobs.push_back(Jobs::WHITEMAGE);
    OnionJobs.push_back(Jobs::THIEF);
    OnionJobs.push_back(Jobs::KNIGHT);
    OnionJobs.push_back(Jobs::MONK);

}


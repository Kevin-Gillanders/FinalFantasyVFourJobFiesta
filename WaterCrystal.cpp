#include "WaterCrystal.h"

void WaterCrystal::SetValidJobs()
{
	ValidJobs.push_back(Jobs::REDMAGE);
	ValidJobs.push_back(Jobs::TIMEMAGE);
	ValidJobs.push_back(Jobs::SUMMONER);
	ValidJobs.push_back(Jobs::BERSERKER);
	ValidJobs.push_back(Jobs::SORCERER);
	ValidJobs.push_back(Jobs::MIME);

	//750
	_750Jobs.push_back(Jobs::TIMEMAGE);
	_750Jobs.push_back(Jobs::SUMMONER);
	_750Jobs.push_back(Jobs::REDMAGE);

	//no 750
	No750Jobs.push_back(Jobs::BERSERKER);
	No750Jobs.push_back(Jobs::SORCERER);

	ClassicJobs.push_back(Jobs::REDMAGE);


	OnionJobs.push_back(Jobs::REDMAGE);
	OnionJobs.push_back(Jobs::SUMMONER);

}

WaterCrystal::WaterCrystal()
{
    SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_BLUE;
	BackgroundColour = { 102, 178, 255 };
	ForegroundColour = { 153, 255, 204 };
	CrystalDefinition = Crystals::WATER;
	CrystalName = "Water";
}


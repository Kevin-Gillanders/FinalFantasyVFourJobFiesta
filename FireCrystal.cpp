#include "FireCrystal.h"

void FireCrystal::SetValidJobs()
{
	ValidJobs.push_back(Jobs::NINJA);
	ValidJobs.push_back(Jobs::HUNTER);
	ValidJobs.push_back(Jobs::GEOMANCER);
	ValidJobs.push_back(Jobs::TRAINER);
	ValidJobs.push_back(Jobs::BARD);

	//750
	_750Jobs.push_back(Jobs::GEOMANCER);
	_750Jobs.push_back(Jobs::BARD);

	//no 750
	No750Jobs.push_back(Jobs::HUNTER);
	No750Jobs.push_back(Jobs::TRAINER);
	No750Jobs.push_back(Jobs::NINJA);


	OnionJobs.push_back(Jobs::BARD);
	OnionJobs.push_back(Jobs::GEOMANCER);
	OnionJobs.push_back(Jobs::NINJA);
	OnionJobs.push_back(Jobs::HUNTER);


}

FireCrystal::FireCrystal()
{
	SetValidJobs();
	CrystalColour = ConsoleColour::BRIGHT_RED;
	BackgroundColour = { 255, 20, 20 };
	ForegroundColour = { 255, 255, 0 };
	CrystalDefinition = Crystals::FIRE;
	CrystalName = "Fire";
}


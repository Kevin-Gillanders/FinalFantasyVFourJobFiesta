#pragma once

#include <vector>
#include "FinalFantasyVEnums.h"
#include "ConsoleEnums.h"
#include <time.h>
#include "ConsoleFormatter.h"
#include <iostream>

class Crystal
{

protected:
	std::vector<Jobs> ValidJobs{};
	std::vector<Jobs> _750Jobs{};
	std::vector<Jobs> No750Jobs{};
	std::vector<Jobs> ClassicJobs{};
	std::vector<Jobs> OnionJobs{};
	std::vector<Jobs> MeteorJobs{};

	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;
	std::string CrystalName;
	virtual void SetValidJobs() = 0;

public:
	ConsoleFormatter console{};

	Crystal();
	
	void DisplayJobs(Jobs jobToDisplay);

	Jobs GetValidJob(JobCompositionTypes type, bool allowDupes, bool allowBerserkers, std::vector<Jobs> previousJobs);
	Jobs Get375ValidJob(JobCompositionTypes type, int _750, int no750);
	void PrintMessage(std::string text);
	void ResetColour();
	int GetRandom(int jobNum);
	void SetColour();

private:

	void SetRandomSeed();
	void SetMeteorJobs();

};
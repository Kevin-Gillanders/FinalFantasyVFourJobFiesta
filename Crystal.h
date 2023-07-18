#pragma once

#include <vector>
#include "FinalFantasyVEnums.h"
#include "ConsoleEnums.h"
#include <time.h>
#include "ConsoleFormatter.h"
#include <iostream>
#include "Helper.h"
#include "ColourStruct.h"

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
	ColourStruct ForegroundColour;
	ColourStruct BackgroundColour;

	Crystals CrystalDefinition;
	std::string CrystalName;
	Helper helper{};
	virtual void SetValidJobs() = 0;

public:
	ConsoleFormatter console{};

	Crystal();
	
	void DisplayJobs(Jobs jobToDisplay);

	Jobs GetValidJob(JobCompositionTypes type, bool allowDupes, bool allowBerserkers, std::vector<Jobs> previousJobs);
	Jobs Get375ValidJob(JobCompositionTypes type, int _750, int no750);
	void PrintMessage(std::string text);
	void ResetColour();
	void SetColour();

private:

	void SetMeteorJobs();

};
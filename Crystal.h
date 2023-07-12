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
	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;
	std::string CrystalName;
	virtual void SetValidJobs() = 0;

public:
	ConsoleFormatter console{};

	Crystal();
	
	virtual Jobs GetValidJob() = 0;
	virtual void DisplayJobs() = 0;

	void PrintMessage(std::string text);
	void ResetColour();
	int GetRandom(int jobNum);
	void SetColour();

private:

	void SetRandomSeed();

};
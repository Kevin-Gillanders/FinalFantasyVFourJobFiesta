#include <vector>
#include "FinalFantasyVEnums.h"
#include "ConsoleEnums.h"
#include <time.h>
#include "ConsoleFormatter.h"
#include <iostream>
using namespace std;

class Crystal
{

protected:
	std::vector<Jobs> ValidJobs{};
	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;
	string CrystalName;

public:
	ConsoleFormatter console{};

	Crystal()
	{
		SetRandomSeed();
	}
	
	virtual Jobs GetValidJob() = 0;

	virtual void DisplayJobs() = 0;
	
	virtual void SetValidJobs() = 0;


	void PrintMessage(string text)
	{

		SetColour(); 
		cout << "This is the " << CrystalName << " crystal" << endl;
		cout << text << endl;
		ResetColour();
	}

	void ResetColour()
	{
		console.ResetColour();
	}

	int GetRandom(int jobNum)
	{
		return rand() % jobNum;
	}

	virtual void SetColour()
	{
		console.SetColour(CrystalColour);
	}


private:
	void SetRandomSeed()
	{
		srand(time(NULL));
	}

};



class WindCrystal : public Crystal
{
private:
	void SetValidJobs()
	{
		ValidJobs.push_back(Jobs::KNIGHT);
		ValidJobs.push_back(Jobs::MONK);
		ValidJobs.push_back(Jobs::THIEF);
		ValidJobs.push_back(Jobs::WHITEMAGE);
		ValidJobs.push_back(Jobs::BLACKMAGE);
		ValidJobs.push_back(Jobs::BLUEMAGE);
	}

public:
	WindCrystal()
	{
		SetValidJobs();
		CrystalColour = ConsoleColour::BRIGHT_CYAN;
		CrystalDefinition = Crystals::WIND;
		CrystalName = "Wind";

	}

	virtual Jobs GetValidJob() override
	{
		return Jobs();
	}

	virtual void DisplayJobs() override
	{
	}

};


class WaterCrystal : public Crystal
{
private:
	void SetValidJobs()
	{
		ValidJobs.push_back(Jobs::KNIGHT);
	}

public:
	WaterCrystal()
	{
		SetValidJobs();
		CrystalColour = ConsoleColour::BRIGHT_BLUE;
		CrystalDefinition = Crystals::WATER;
		CrystalName = "Water";

	}

	virtual Jobs GetValidJob() override
	{
		throw std::exception("Not implemented");
	}

	virtual void DisplayJobs() override
	{
		std::cout << "Hello";
	}
};


class FireCrystal : public Crystal
{
private:
	void SetValidJobs()
	{
		ValidJobs.push_back(Jobs::KNIGHT);
	}

public:
	FireCrystal()
	{
		SetValidJobs();
		CrystalColour = ConsoleColour::BRIGHT_RED;
		CrystalDefinition = Crystals::FIRE;
		CrystalName = "Fire";
	}

	Jobs GetValidJob()
	{
		throw std::exception("Not implemented");
	}

	void DisplayJobs()
	{
		std::cout << "Hello";
	}
};



class EarthCrystal : public Crystal
{
private:

	void SetValidJobs()
	{
		ValidJobs.push_back(Jobs::KNIGHT);
	}

public:
	EarthCrystal()
	{
		SetValidJobs();
		CrystalColour = ConsoleColour::BRIGHT_GREEN;
		CrystalDefinition = Crystals::EARTH;
		CrystalName = "Earth";

	}

	Jobs GetValidJob()
	{
		throw std::exception("Not implemented");
	}

	void DisplayJobs()
	{
		std::cout << "Hello";
	}
};


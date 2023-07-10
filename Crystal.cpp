#include <vector>
#include "FinalFantasyVEnums.h"
#include "ConsoleEnums.h"
#include <time.h>
#include "ConsoleFormatter.h"
#include <iostream>
using namespace std;

class Crystal
{
public:
	ConsoleFormatter console{};

	Crystal()
	{
		SetRandomSeed();
	}
	
	virtual Jobs GetValidJob() = 0;

	virtual void DisplayJobs() = 0;
	
	virtual void SetValidJobs() = 0;

	virtual void PrintMessage() = 0;
	virtual void SetColour() = 0;

	virtual void PrintMessage(string text) = 0;

	void ResetColour()
	{
		console.ResetColour();
	}
	int GetRandom(int jobNum)
	{
		return rand() % jobNum;
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
	std::vector<Jobs> ValidJobs{};
	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;


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

	}

	Jobs GetValidJob()
	{
		throw std::exception("Not implemented");
	}

	void DisplayJobs()
	{
		std::cout << "Hello";
	}

	void PrintMessage()
	{
		printf("This is the wind crystal\n");
	}

	// Inherited via Crystal
	virtual void PrintMessage(string text) override
	{
		SetColour();
		cout << text;
		ResetColour();
	}

	virtual void SetColour() override
	{
		console.SetColour(CrystalColour);
	}
};


class WaterCrystal : public Crystal
{
private:
	std::vector<Jobs> ValidJobs{};
	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;


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

	}

	Jobs GetValidJob()
	{
		throw std::exception("Not implemented");
	}

	void DisplayJobs()
	{
		std::cout << "Hello";
	}

	void PrintMessage()
	{
		console.SetColour(CrystalColour);
		printf("This is the water crystal\n");
		console.ResetColour();
	}

	// Inherited via Crystal
	virtual void SetColour() override
	{
		console.SetColour(CrystalColour);
	}
	virtual void PrintMessage(string text) override
	{
		SetColour();
		cout << text;
		ResetColour();
	}
};


class FireCrystal : public Crystal
{
private:
	std::vector<Jobs> ValidJobs{};
	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;


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

	}

	Jobs GetValidJob()
	{
		throw std::exception("Not implemented");
	}

	void DisplayJobs()
	{
		std::cout << "Hello";
	}

	void PrintMessage()
	{
		console.SetColour(CrystalColour);
		printf("This is the fire crystal\n");
		console.ResetColour();
	}

	// Inherited via Crystal
	virtual void SetColour() override
	{
		console.SetColour(CrystalColour);
	}
	virtual void PrintMessage(string text) override
	{
		SetColour();
		cout << text;
		ResetColour();
	}
};



class EarthCrystal : public Crystal
{
private:
	std::vector<Jobs> ValidJobs{};
	ConsoleColour CrystalColour;
	Crystals CrystalDefinition;


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

	}

	Jobs GetValidJob()
	{
		throw std::exception("Not implemented");
	}

	void DisplayJobs()
	{
		std::cout << "Hello";
	}

	void PrintMessage()
	{
		console.SetColour(CrystalColour);
		printf("This is the earth crystal\n");
		console.ResetColour();
	}

	// Inherited via Crystal
	virtual void SetColour() override
	{
		console.SetColour(CrystalColour);
	}
	virtual void PrintMessage(string text) override
	{
		SetColour();
		cout << text;
		ResetColour();
	}
};


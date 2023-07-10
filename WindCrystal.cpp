#include "Crystal.cpp"
#include <iostream>

//
//class WindCrystal : public Crystal
//{
//private:
//	std::vector<Jobs> ValidJobs{};
//	ConsoleColour CrystalColour;
//	Crystals CrystalDefinition;
//	
//
//	void SetValidJobs()
//	{
//		ValidJobs.push_back(Jobs::KNIGHT);
//		ValidJobs.push_back(Jobs::MONK);
//		ValidJobs.push_back(Jobs::THIEF);
//		ValidJobs.push_back(Jobs::WHITEMAGE);
//		ValidJobs.push_back(Jobs::BLACKMAGE);
//		ValidJobs.push_back(Jobs::BLUEMAGE);
//	}
//
//public:
//	WindCrystal()
//	{
//		SetValidJobs();
//		CrystalColour = ConsoleColour::BRIGHT_CYAN;
//		CrystalDefinition = Crystals::WIND;
//
//	}
//
//	Jobs GetValidJob()
//	{
//		throw std::exception("Not implemented");
//	}
//
//	void DisplayJobs()
//	{
//		std::cout << "Hello";
//	}
//
//	void PrintMessage()
//	{
//		console.SetColour(CrystalColour);
//		printf("This is the wind crystal\n");
//		console.ResetColour();
//	}
//};
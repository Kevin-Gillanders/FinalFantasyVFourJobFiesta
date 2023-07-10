//#include "Crystal.cpp"
//#include <iostream>
//
//
//class WaterCrystal : public Crystal
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
//	}
//
//public:
//	WaterCrystal()
//	{
//		SetValidJobs();
//		CrystalColour = ConsoleColour::BRIGHT_BLUE;
//		CrystalDefinition = Crystals::WATER;
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
//		printf("This is the water crystal\n");
//		console.ResetColour();
//	}
//};
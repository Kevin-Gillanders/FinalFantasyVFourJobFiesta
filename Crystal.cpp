#include <vector>
#include "FinalFantasyVEnums.h"
#include "ConsoleEnums.h"
#include <time.h>
#include "ConsoleFormatter.h"
#include <iostream>
#include "Crystal.h"
using namespace std;


Crystal::Crystal()
{
	SetRandomSeed();
}

void Crystal::PrintMessage(std::string text)
{
	SetColour();
	cout << "This is the " << CrystalName << " crystal" << endl;
	cout << text << endl;
	ResetColour();
}

void Crystal::ResetColour()
{
	console.ResetColour();
}

int Crystal::GetRandom(int jobNum)
{
	int rndNum = rand() % jobNum;
	return rndNum;
}

void Crystal::SetColour()
{
	console.SetColour(CrystalColour);
}

void Crystal::SetRandomSeed()
{
	srand(time(NULL));
}

Jobs Crystal::GetValidJob()
{
	int x = ValidJobs.size();
	return ValidJobs[GetRandom(x)];
}


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
	SetMeteorJobs();
}

void Crystal::DisplayJobs(Jobs jobToDisplay)
{
	std::string jobName;

	switch (jobToDisplay)
	{
	case FREELANCER:
		jobName = "Freelancer";
		break;
	case KNIGHT:
		jobName = "Knight";
		break;
	case MONK:
		jobName = "Monk";
		break;
	case THIEF:
		jobName = "Thief";
		break;
	case WHITEMAGE:
		jobName = "White Mage";
		break;
	case BLACKMAGE:
		jobName = "Black Mage";
		break;
	case BLUEMAGE:
		jobName = "Blue Mage";
		break;
	case REDMAGE:
		jobName = "Red Mage";
		break;
	case TIMEMAGE:
		jobName = "Time Mage";
		break;
	case SUMMONER:
		jobName = "Summoner";
		break;
	case BERSERKER:
		jobName = "Berserker";
		break;
	case SORCERER:
		jobName = "Sorcerer";
		break;
	case MIME:
		jobName = "Mime";
		break;
	case NINJA:
		jobName = "Ninja";
		break;
	case HUNTER:
		jobName = "Hunter";
		break;
	case GEOMANCER:
		jobName = "Geomancer";
		break;
	case TRAINER:
		jobName = "Trainer";
		break;
	case BARD:
		jobName = "Bard";
		break;
	case DRAGOON:
		jobName = "Dragoon";
		break;
	case SAMURAI:
		jobName = "Samurai";
		break;
	case DANCER:
		jobName = "Dancer";
		break;
	case CHEMIST:
		jobName = "Chemist";
		break;
	default:
		throw;
		break;
	}

	PrintMessage(jobName);
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

void Crystal::SetMeteorJobs()
{
	MeteorJobs.push_back(Jobs::FREELANCER);
	MeteorJobs.push_back(Jobs::KNIGHT);
	MeteorJobs.push_back(Jobs::MONK);
	MeteorJobs.push_back(Jobs::THIEF);
	MeteorJobs.push_back(Jobs::WHITEMAGE);
	MeteorJobs.push_back(Jobs::BLACKMAGE);
	MeteorJobs.push_back(Jobs::BLUEMAGE);
	MeteorJobs.push_back(Jobs::REDMAGE);
	MeteorJobs.push_back(Jobs::TIMEMAGE);
	MeteorJobs.push_back(Jobs::SUMMONER);
	MeteorJobs.push_back(Jobs::BERSERKER);
	MeteorJobs.push_back(Jobs::SORCERER);
	MeteorJobs.push_back(Jobs::MIME);
	MeteorJobs.push_back(Jobs::NINJA);
	MeteorJobs.push_back(Jobs::HUNTER);
	MeteorJobs.push_back(Jobs::GEOMANCER);
	MeteorJobs.push_back(Jobs::TRAINER);
	MeteorJobs.push_back(Jobs::BARD);
	MeteorJobs.push_back(Jobs::DRAGOON);
	MeteorJobs.push_back(Jobs::SAMURAI);
	MeteorJobs.push_back(Jobs::DANCER);
	MeteorJobs.push_back(Jobs::CHEMIST);
}

Jobs Crystal::GetValidJob(JobCompositionTypes jobComp)
{

	Jobs pickedJob{};
	int x;
	switch (jobComp)
	{
	case ALL:
		x = ValidJobs.size();
		pickedJob = ValidJobs[GetRandom(x)];
		break;
	case TEAM750:
		x = _750Jobs.size();
		pickedJob = _750Jobs[GetRandom(x)];
		break;
	case TEAMNO750:
		x = No750Jobs.size();
		pickedJob = No750Jobs[GetRandom(x)];
		break;
	case TEAM375:
		throw;
		break;
	case CLASSICJOBS:
		x = ClassicJobs.size();
		pickedJob = ClassicJobs[GetRandom(x)];
		break;
	case ONIONJOBS:
		throw;
		break;
	case TEAMMETEOR:
		x = MeteorJobs.size();
		pickedJob = MeteorJobs[GetRandom(x)];
		break;
	default:
		throw;
		break;
	}

	return pickedJob;
}

Jobs Crystal::Get375ValidJob(JobCompositionTypes type, int _750, int no750)
{
	Jobs pickedJob{};
	int x;
	if(_750 == 2)
	{
		x = No750Jobs.size();
		pickedJob = No750Jobs[GetRandom(x)];
	}
	else if (no750 == 2)
	{
		x = _750Jobs.size();
		pickedJob = _750Jobs[GetRandom(x)];
	}
	return pickedJob;

}


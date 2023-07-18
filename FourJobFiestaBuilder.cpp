#include "FourJobFiestaBuilder.h"
using namespace std;


void FourJobFiestaBuilder::GenerateJob(RunConfig runDetails)
{
	//Crystals x = runDetails.CurrentCrystal;
	//JobCompositionTypes jobComp = runDetails.JobComp;

	//Jobs job = GetJob(x, jobComp);
}

void FourJobFiestaBuilder::GenerateFullJobSet(RunConfig runDetails)
{
	RunTypes runType = runDetails.RunType;
	JobCompositionTypes jobComp = runDetails.JobComp;

	bool allowDupes = runDetails.AllowDuplicates;
	bool allowBerserkers = runDetails.AllowBerserkers;
	std::vector<Jobs> jobsList{};
	int _750 = 0, no750 = 0;
	//bool allowBerserker = runDetails
	int amountOfJobs = 4;

	if ((runType == METEOR && jobComp != TEAMMETEOR) || (runType != METEOR && jobComp == TEAMMETEOR))
		throw;
	int jobs = 0;
	while(jobs < amountOfJobs)
	{
		try
		{
			Jobs jobPicked{};

			if (jobComp == CLASSICJOBS)
			{
				int amountOfClassicJobs = 6;
				int classicIdx = helper.GetRandom(amountOfClassicJobs) + 1;

				if (amountOfClassicJobs == classicIdx)
					jobPicked = GetJob(WATER, jobComp, allowDupes, allowBerserkers, jobsList);
				else
					jobPicked = GetJob(WIND, jobComp, allowDupes, allowBerserkers, jobsList);
				jobs++;
			}
			else if (jobComp == TEAM375)
			{
				int rand = helper.GetRandom(2);
				if (rand == 0)
				{
					if (_750 != 2)
					{
						jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAM750, allowDupes, allowBerserkers, jobsList);
						_750++;
					}
					else
					{
						jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAMNO750, allowDupes, allowBerserkers, jobsList);
						no750++;
					}
				}
				else
				{
					if (no750 != 2)
					{
						jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAMNO750, allowDupes, allowBerserkers, jobsList);
						no750++;
					}
					else
					{
						jobPicked = GetJob(GetCrystal(REGULAR, jobs), TEAM750, allowDupes, allowBerserkers, jobsList);
						_750++;
					}
				}
				jobs++;
			}
			else
			{
				jobPicked = GetJob(GetCrystal(runType, jobs), jobComp, allowDupes, allowBerserkers, jobsList);
				jobs++;
			}
			jobsList.push_back(jobPicked);
		}
		catch(std::string dupe)
		{
			//GetJob throws if a duplicate is found as it can lead to deadlock in a crystal
		}
	}
}

void FourJobFiestaBuilder::BuildRun()
{
	// TODO - convert this to a file
	Console.SetColour(BLACK, BRIGHT_CYAN);
	Console.ClearConsole();

	RunTypes runType = GetRunType();
	JobCompositionTypes jobComp = GetJobType(runType);
	bool allowDupes = AllowDuplicates();
	bool allowBerserk = AllowBerserker();

	vector<AdvancedOptions> advancedOptionsList{};
	vector<Jobs> testJobs{};


	RunConfig runConf{ WIND, testJobs, runType, jobComp, allowDupes, allowBerserk, advancedOptionsList };

	GenerateFullJobSet(runConf);

}

Jobs FourJobFiestaBuilder::GetJob(Crystals crystal, JobCompositionTypes jobComp, bool allowDupes, bool allowBerserkers, std::vector<Jobs> previousJobs)
{
	Jobs jobPicked;
	switch (crystal)
	{
	case WIND:
		jobPicked = windCrystal.GetValidJob(jobComp, allowDupes,allowBerserkers, previousJobs);
		windCrystal.DisplayJobs(jobPicked);
		break;
	case WATER:
		jobPicked = waterCrystal.GetValidJob(jobComp, allowDupes, allowBerserkers, previousJobs);
		waterCrystal.DisplayJobs(jobPicked);
		break;
	case FIRE:
		jobPicked = fireCrystal.GetValidJob(jobComp, allowDupes, allowBerserkers, previousJobs);
		fireCrystal.DisplayJobs(jobPicked);
		break;
	case EARTH:
		jobPicked = earthCrystal.GetValidJob(jobComp, allowDupes, allowBerserkers, previousJobs);
		earthCrystal.DisplayJobs(jobPicked);
		break;
	default:
		throw;
		break;
	}

	return jobPicked;
}

Crystals FourJobFiestaBuilder::GetCrystal(RunTypes typeofRun, int round)
{
	Crystals pickedCrystal{};
	std::vector<Crystals> crystalsToPickFrom{};
	int idx = 0; 
	switch (typeofRun)
	{
	case REGULAR:
		pickedCrystal = NormalRun[round];
		break;
	case TYPHOON:
		crystalsToPickFrom = TyphoonRun[round];
		idx = helper.GetRandom(crystalsToPickFrom.size());
		pickedCrystal = crystalsToPickFrom[idx];
		break;
	case VOLCANO:
		crystalsToPickFrom = VolcanoRun[round];
		idx = helper.GetRandom(crystalsToPickFrom.size());
		pickedCrystal = crystalsToPickFrom[idx];
		break;
	case METEOR:
		crystalsToPickFrom = MeteorRun[round];
		idx = helper.GetRandom(crystalsToPickFrom.size());
		pickedCrystal = crystalsToPickFrom[idx];
		break;
	default:
		throw;
		break;
	}


	return pickedCrystal;
}

void FourJobFiestaBuilder::DisplayRun(RunConfig runConfig)
{
}

RunTypes FourJobFiestaBuilder::GetRunType()
{
	cout << "Welcome to the Final Fantasy V four job fiesta builder. Lets get started" << endl << endl;
	cout << "First you need to pick a run type, there are 4 to choose from :" << endl;

	cout << "[R/r]egular run - Each crystal job pool is picked from is sequence." << endl;
	cout << "[T/t]yphoon run - This type of run leans towards early available jobs." << endl;
	cout << "[V/v]olcano run - This type of run leans towards later available Jobs." << endl;
	cout << "[M/m]eteor  run - This type of run gives out Jobs randomly." << endl;

	cout << "Please enter the type of run that you would like to do : ";

	RunTypes pickedRunType{};
	bool runPicked = false;

	string runReg = "regular";
	string runTyp = "typhoon";
	string runVol = "volcano";
	string runMet = "meteor";

	string run{};

	cin >> run;

	while (!runPicked)
	{
		char runChar = (char)std::tolower(run.at(0));

		if (runChar == runReg.at(0) || helper.ToLower(run) == runReg)
		{
			pickedRunType = REGULAR;
			runPicked = true;
		}
		else if (runChar == runTyp.at(0) || helper.ToLower(run) == runTyp)
		{
			pickedRunType = TYPHOON;
			runPicked = true;
		}
		else if (runChar == runVol.at(0) || helper.ToLower(run) == runVol)
		{
			pickedRunType = VOLCANO;
			runPicked = true;
		}
		else if (runChar == runMet.at(0) || helper.ToLower(run) == runMet)
		{
			pickedRunType = METEOR;
			runPicked = true;
		}
		else
		{
			cout << "Value given " << run << " is not recognised, please enter correct value : ";
			cin >> run;
		}
	}
	Console.ClearConsole();
	Console.ResetPosition();
	cout << "You selected " << run << endl;
	return pickedRunType;
}

JobCompositionTypes FourJobFiestaBuilder::GetJobType(RunTypes runType)
{
	if(runType == METEOR)
		return TEAMMETEOR;

	bool regRun = runType == REGULAR;
	cout << "####################################################" << endl;
	cout << "The next option that you have to select is your job composition." << endl << endl;

	if (!regRun)
	{
		cout << "As you have not selected a regular run, Team 375 and Team Classic job  will be unavailable." << endl << endl;
		cout << "####################################################" << endl;
	}
	cout << "There are a number of Job compositions to select from :" << endl;

	cout << "[All] jobs" << endl;
	cout << "This team will pick from all available jobs" << endl;

	cout << "Team [750]" << endl;
	cout << "This team is all mages" << endl;

	cout << "Team [no750]" << endl;
	cout << "This team has no mages" << endl ;
	if(regRun)
	{
		cout << "Team [375]" << endl;
		cout << "This team is 2 from 750 and 2 from no750" << endl ;

		cout << "Team [Classic]" << endl;
		cout << "These are jobs that were in the original final fantasy" << endl ;
	}

	cout << endl << "Please enter the Job comp that you would like : ";


	JobCompositionTypes pickedJobComp{};
	string allJobs = "all";
	string job750 = "750";
	string jobNo750 = "no750";
	string job375 = "375";
	string jobClassic = "classic";

	string jobComp{};
	bool jobPicked = false;

	cin >> jobComp;

	while (!jobPicked)
	{
		jobComp = helper.ToLower(jobComp);
		if (jobComp == allJobs)
		{
			pickedJobComp = ALL;
			jobPicked = true;
		}
		else if (jobComp == job750)
		{
			pickedJobComp = TEAM750;
			jobPicked = true;
		}
		else if (jobComp == jobNo750)
		{
			pickedJobComp = TEAMNO750;
			jobPicked = true;
		}
		else if (jobComp == job375 && runType == REGULAR)
		{
			pickedJobComp = TEAM375;
			jobPicked = true;
		}
		else if (jobComp == jobClassic && runType == REGULAR)
		{
			pickedJobComp = CLASSICJOBS;
			jobPicked = true;
		}
		else
		{
			cout << "Value given " << jobComp << " is not recognised, please enter correct value : ";
			cin >> jobComp;
		}
	}

	Console.ClearConsole();
	Console.ResetPosition();
	cout << "You selected " << jobComp << endl;
	return pickedJobComp;


}

bool FourJobFiestaBuilder::AllowDuplicates()
{
	cout << "####################################################" << endl;

	cout << "Do you want to allow duplicates? [y/n]" << endl;

	string dupes{};

	cin >> dupes;

	dupes = helper.ToLower(dupes);

	string yes = "y";

	if (dupes == yes)
		return true;

	Console.ClearConsole();
	Console.ResetPosition();
	cout << "You selected " << dupes << endl;
	return false;

}

bool FourJobFiestaBuilder::AllowBerserker()
{
	cout << "####################################################" << endl;

	cout << "Do you want to allow berserkers in your job pool? [y/n]" << endl;

	string berserk{};

	cin >> berserk;

	berserk = helper.ToLower(berserk);

	string yes = "y";

	if (berserk == yes)
		return true;

	Console.ClearConsole();
	Console.ResetPosition();
	cout << "You selected " << berserk << endl;
	return false;
}


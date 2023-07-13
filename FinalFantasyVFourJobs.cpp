

#include <iostream>
#include "ConsoleFormatter.h"
#include "RunConfig.h"
#include "Crystal.h"
#include "WindCrystal.h"
#include "WaterCrystal.h"
#include "FireCrystal.h"
#include "EarthCrystal.h"
#include "FourJobFiestaBuilder.h"
using namespace std;

int main()
{
    ConsoleFormatter console{};

    Crystals testCrystal = Crystals::WIND;
    vector<Jobs> testJobs = { Jobs::BARD };
    RunTypes runType = RunTypes::REGULAR;
    JobCompositionTypes jobComp = JobCompositionTypes::TEAM750;
    vector<AdvancedOptions> advancedOptionsList{AdvancedOptions::ALLOWBERSERKER};


    //WindCrystal windTest{};
    //WaterCrystal waterTest{};
    //FireCrystal fireTest{};
    //EarthCrystal earthTest{};


    //windTest.PrintMessage("Windy");
    //waterTest.PrintMessage("Watery");
    //fireTest.PrintMessage("Firey");
    //earthTest.PrintMessage("Earthy");

    //earthTest.PrintMessage("Rocks and the like");


    
    FourJobFiestaBuilder fjfBuilder{};

    //RunConfig runConf750{ Crystals::WATER, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfNo750{ Crystals::FIRE, testJobs, runType, jobComp, advancedOptionsList };
    ////RunConfig runConf375{ Crystals::EARTH, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfClassic{ Crystals::EARTH, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfOnion{ Crystals::EARTH, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfMeteor{ Crystals::EARTH, testJobs, runType, jobComp, advancedOptionsList };

    RunConfig runConf{ testCrystal, testJobs, runType, JobCompositionTypes::ALL, advancedOptionsList };


    cout << "Regular, all" << endl;
    fjfBuilder.GenerateFullJobSet(runConf);
    
    cout << "Regular, Typhoon" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::TYPHOON, JobCompositionTypes::ALL, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);
    
    cout << "Regular, Volcano" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::VOLCANO, JobCompositionTypes::ALL, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "750, All" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::TEAM750, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "750, Typhoon" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::TYPHOON, JobCompositionTypes::TEAM750, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "750, Volcano" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::VOLCANO, JobCompositionTypes::TEAM750, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);


    cout << "NO750, ALL" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::TEAMNO750, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf );

    cout << "NO750, Volcano" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::VOLCANO, JobCompositionTypes::TEAMNO750, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf );

    cout << "NO750, Typhoon" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::TYPHOON, JobCompositionTypes::TEAMNO750, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf );


    cout << "Meteor, Meteor" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::METEOR, JobCompositionTypes::TEAMMETEOR, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);


    cout << "CLASSICJOBS, ALL" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::CLASSICJOBS, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "CLASSICJOBS, TYPHOON" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::TYPHOON, JobCompositionTypes::CLASSICJOBS, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "CLASSICJOBS, VOLCANO" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::VOLCANO, JobCompositionTypes::CLASSICJOBS, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);


    cout << "Team375, Regular" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::TEAM375, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "Team375, Regular" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::TEAM375, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    cout << "Team375, Regular" << endl;
    runConf = RunConfig(testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::TEAM375, advancedOptionsList);
    fjfBuilder.GenerateFullJobSet(runConf);

    //cout << "REGULAR, CLASSICJOBS" << endl;
    //RunConfig runConfNoMeteor{ testCrystal, testJobs, RunTypes::REGULAR, JobCompositionTypes::CLASSICJOBS, advancedOptionsList };
    //fjfBuilder.GenerateFullJobSet(runConfNoMeteor);

    //RunConfig runConf{ testCrystal, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfWa{ Crystals::WATER, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfFi{ Crystals::FIRE, testJobs, runType, jobComp, advancedOptionsList };
    //RunConfig runConfEa{ Crystals::EARTH, testJobs, runType, jobComp, advancedOptionsList };

    //fjfBuilder.GenerateJob(runConf);
    //fjfBuilder.GenerateJob(runConf);

    //fjfBuilder.GenerateJob(runConfWa);
    //fjfBuilder.GenerateJob(runConfWa);
    //
    //fjfBuilder.GenerateJob(runConfFi);
    //fjfBuilder.GenerateJob(runConfFi);
    //
    //fjfBuilder.GenerateJob(runConfEa);
    //fjfBuilder.GenerateJob(runConfEa);

    /*console.SetColour(consoleColour::BLUE, consoleColour::YELLOW);

    printf("hello world");

    console.ClearConsole();
    printf("hello world");
    console.ResetColour();
    printf("hello world");
    console.ResetPosition();
    console.ClearConsole();
    console.ResetConsole();

    printf("hello world\n");
    console.SetTextMode(TextMode::BOLD);
    printf("hello world\n");
    console.SetTextMode(TextMode::BOLD);


    printf("hello world\n");
    console.SetTextMode(TextMode::UNDERLINE);
    printf("hello world\n");
    console.SetTextMode(TextMode::UNDERLINE);

    printf("hello world\n");
    console.SetTextMode(TextMode::ITALICS);
    printf("hello world\n");
    console.SetTextMode(TextMode::ITALICS);

    printf("hello world\n");
    console.SetTextMode(TextMode::STRIKETHROUGH);
    printf("hello world\n");
    console.SetTextMode(TextMode::STRIKETHROUGH);

    console.ResetPosition();
    console.ClearConsole();
    console.ResetConsole();

    for (int i = 0; i <= 255; i++)
    {
        console.SetColour(BACKGROUND, i, 0 , i);
        printf("%i ", i);
    }*/
    return 0;

}

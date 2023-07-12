

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
    RunTypes runType = RunTypes::METEOR;
    JobCompositionTypes jobComp = JobCompositionTypes::ALL;
    vector<AdvancedOptions> advancedOptionsList{AdvancedOptions::ALLOWBERSERKER};


    WindCrystal windTest{};
    WaterCrystal waterTest{};
    FireCrystal fireTest{};
    EarthCrystal earthTest{};


    windTest.PrintMessage("Windy");
    waterTest.PrintMessage("Watery");
    fireTest.PrintMessage("Firey");
    earthTest.PrintMessage("Earthy");

    earthTest.PrintMessage("Rocks and the like");

    RunConfig runConf{ testCrystal, testJobs, runType, jobComp, advancedOptionsList };
    RunConfig runConfWa{ Crystals::WATER, testJobs, runType, jobComp, advancedOptionsList };
    RunConfig runConfFi{ Crystals::FIRE, testJobs, runType, jobComp, advancedOptionsList };
    RunConfig runConfEa{ Crystals::EARTH, testJobs, runType, jobComp, advancedOptionsList };


    FourJobFiestaBuilder fjfBuilder{};

    fjfBuilder.GenerateJob(runConf);
    fjfBuilder.GenerateJob(runConf);

    fjfBuilder.GenerateJob(runConfWa);
    fjfBuilder.GenerateJob(runConfWa);
    
    fjfBuilder.GenerateJob(runConfFi);
    fjfBuilder.GenerateJob(runConfFi);
    
    fjfBuilder.GenerateJob(runConfEa);
    fjfBuilder.GenerateJob(runConfEa);

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

#pragma once

enum Crystals{
	WIND,
	WATER,
	FIRE,
	EARTH,
};

enum Jobs {
    //Starting job
    FREELANCER,
    //Wind Crystal Jobs
    KNIGHT,
    MONK,
    THIEF,
    WHITEMAGE,
    BLACKMAGE,
    BLUEMAGE,
    //Water Crystal Jobs
    REDMAGE,
    TIMEMAGE,
    SUMMONER,
    BERSERKER,
    SORCERER,
    MIME,
    //Fire Crystal Jobs
    NINJA,
    HUNTER,
    GEOMANCER,
    TRAINER,
    BARD,
    //Earth Crystal Jobs
    DRAGOON,
    SAMURAI,
    DANCER,
    CHEMIST,
    //Advance Jobs
    NECROMANCER,
    CANNONEER,
    ORACLE,
    GLADIATOR,
};

enum RunTypes {
    REGULAR,
    TYPHOON,
    VOLCANO,
    METEOR,
};

enum JobCompositionTypes {
    ALL,
    TEAM750,
    TEAMNO750,
    TEAM375,
    CLASSICJOBS,
    ONIONJOBS,
    TEAMMETEOR,
};

enum AdvancedOptions {
    NORESTRICTIONS,
    NATURALJOBS,
    UPGRADEJOBS,
    ALLOWDUPLICATES,
    FIFTHJOB,
    EXTRAJOBS,
    FORBIDDEN,
    ALLOWBERSERKER,
};
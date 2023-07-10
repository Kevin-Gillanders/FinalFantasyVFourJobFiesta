#pragma once
#include "FinalFantasyVEnums.h"
#include "RunConfig.h"
#include <vector>

class FinalFantasyVJobs {
public:
	Jobs GenerateJob(RunConfig runDetails);
	std::vector<Jobs> GenerateFullJobSet(RunConfig runDetails);

};
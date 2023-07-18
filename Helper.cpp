#include "Helper.h"
#include <time.h>

void Helper::SetRandomSeed()
{
	srand(time(NULL));
	//srand(1);
}

std::string Helper::ToLower(std::string str)
{
	std::string newStr{};

	for (int idx = 0; idx < str.size(); idx++)
		newStr = newStr + (char)std::tolower(str.at(idx));

	return newStr;
}

int Helper::GetRandom(int jobNum)
{
	int rndNum = rand() % jobNum;
	return rndNum;
}

Helper::Helper()
{
	SetRandomSeed();
}

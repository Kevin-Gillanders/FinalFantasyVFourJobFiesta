#pragma once
#include <string>

class Helper{
private:
	void SetRandomSeed();
public:
	std::string ToLower(std::string str);
	int GetRandom(int jobNum);
	Helper();
};
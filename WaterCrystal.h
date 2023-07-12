#pragma once

#include "Crystal.h"

class WaterCrystal : public Crystal
{
protected:
	virtual void SetValidJobs() override;

public:
	WaterCrystal();
	// Inherited via Crystal
	virtual Jobs GetValidJob() override;
	virtual void DisplayJobs() override;
};


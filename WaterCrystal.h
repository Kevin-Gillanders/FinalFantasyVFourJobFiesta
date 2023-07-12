#pragma once

#include "Crystal.h"

class WaterCrystal : public Crystal
{
protected:
	virtual void SetValidJobs() override;

public:
	WaterCrystal();
	// Inherited via Crystal
	virtual void DisplayJobs(Jobs jobToDisplay) override;
};


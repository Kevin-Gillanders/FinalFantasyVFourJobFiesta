#pragma once
#include "Crystal.h"

class WindCrystal : public Crystal
{
protected:
	virtual void SetValidJobs() override;

public:
	WindCrystal();
	// Inherited via Crystal
	virtual void DisplayJobs(Jobs jobToDisplay) override;
};

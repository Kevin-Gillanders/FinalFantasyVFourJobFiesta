#pragma once
#include "Crystal.h"

class EarthCrystal : public Crystal
{
protected:
	virtual void SetValidJobs() override;

public:
	EarthCrystal();
	// Inherited via Crystal
	virtual void DisplayJobs(Jobs jobToDisplay) override;
};

#pragma once
#include "Crystal.h"

class FireCrystal : public Crystal
{
protected:
	virtual void SetValidJobs() override;

public:
	FireCrystal();
	// Inherited via Crystal
	virtual Jobs GetValidJob() override;
	virtual void DisplayJobs() override;
};

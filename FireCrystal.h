#pragma once
#include "Crystal.h"

class FireCrystal : public Crystal
{
protected:
	virtual void SetValidJobs() override;

public:
	FireCrystal();
};

#pragma once

#include "pch.h"

#ifndef TESTCOURIER_H
#define TESTCOURIER_H

class ctest::TestCourier
{
public:
	TestCourier();
	virtual ~TestCourier();

	virtual void run(TestSet* testset, int size);
};

#endif //TESTCOURIER_H
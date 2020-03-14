#pragma once

#include "pch.h"

#ifndef TESTPRINTER_H
#define TESTPRINTER_H

class ctest::TestPrinter
{
public:
	virtual void Printt(const TestResult* testresult) = 0;
};

#endif //TESTPRINTER_H
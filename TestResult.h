#pragma once

#include "pch.h"

#ifndef TESTRESULT_H
#define TESTRESULT_H

class ctest::TestResult
{
public:
	TestResult();
	virtual ~TestResult();

	int TotalSuccessess() const;
	int TotalErrors() const;
	int TotalFailures() const;

	int Successes() const;
	int Failures() const;
	int Errors() const;

	int TestSetCount() const;
	int TestRanCount() const;
	int TestSetRanCount() const;

	TestSet* TestSets() const;
	void SetTestSets(TestSet* testsets, int testsetcount);
	virtual void AddResult(TestSet* testset);
protected:
	int _testsetcount;
	int _testrancount;
	int _testsetrancount;

	int _totalfailures;
	int _totalsuccesses;
	int _totalerrors;

	int _failures;
	int _successes;
	int _errors;
	
	TestSet* _testsets;
};

#endif //TESTRESULT_H
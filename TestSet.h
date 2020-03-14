#pragma once

#include "pch.h"

#ifndef TESTSET_H
#define TESTSET_H

class ctest::TestSet
{
public:
	TestSet(std::string name, TestResult* testRes);
	virtual ~TestSet();

	void addTest(Test* t);
	Test* GetTests() const;

	void run();
	bool ran() const;

	int TestCount() const;
	int FailureCount() const;
	int SuccessCount() const;
	int ErrorCount() const;

	const std::string& Name() const;

	TestSet* GetNext() const;
	void SetNext(TestSet* set);

protected:
	int _failures;
	int _successes;
	int _errors;
	int _tests;

	Test* _testss;
	std::string _name;
	TestSet* _nextTestSet;
	TestResult* _testresult;

private:
	void updateCount(Test* test);
	void runTests(Test* test);
	void runTest(Test* test);
	bool _ran;
};

#endif //TESTSET_H
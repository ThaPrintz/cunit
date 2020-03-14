#pragma once

#include "pch.h"

#ifndef TESTREGISTRY_H
#define TESTREGISTRY_H

class ctest::TestRegistry
{
public:
	TestRegistry()
	~TestRegistry();

	static void RegisterTest(Test* test);
	static const TestResult* Run();
	static const TestResult* Run(TestCourier* msg);
	static const TestResult* RunAndPrint();
	static const TestResult* RunAndPrint(TestCourier* msg);
	static const TestResult* RunAndPrint(TestPrinter* prnt);
	static const TestResult* RunAndPrint(TestPrinter* prnt, TestCourier* msg);

private:
	static TestRegistry& instance();
	static int _nextn;
	void Add(Test* test);
	void AddTestSet(TestSet* testset);
	int _testsetamt;
	const TestResult* RunTests(TestCourier* msg);

	TestSet* _curts;
	TestPrinter* _defaultprnter;
	TestCourier* _defaultcourier;
	TestResult* _testresult;
};

#endif //TESTREGISTRY_H
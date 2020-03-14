#pragma once

#ifndef CTEST_H
#define CTEST_H

class ctest
{
public:
	class TestSet;
	class TestCourier;
	class TestRegistry;
	class TestResult;
	class TestPartialResult;
	class TestPrinter;

	class Test
	{
	public:
		Test(const std::string testSet, const std::string name);
		virtual ~Test();

		virtual void PostTest();
		virtual void PreTest();
		virtual void RunTest();

		void SetNextTest(Test * next);
		Test* GetNext() const;

		const std::string TestSetID() const;
		const std::string TestID() const;

		//Test set members
		void AssignTestSet(TestSet * testset);
		TestSet* GetTestSet() const;

		//TestData members
		virtual void SetPartialResult(TestPartialResult * datarepo);
		TestPartialResult* getPartialResult() const;

		int FailCount() const;
		int SuccessCount() const;
		int ErrorCount() const;
	protected:
		std::string _testsetname;
		std::string _testname;

		TestSet* _testset;
		TestPartialResult* _testpartresult;
		Test* _nexttest;

		int fails;
		int success;
		int errors;
	};

	enum testRet {failure, success, error};
};

#endif //CTEST
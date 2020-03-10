#pragma once

#ifndef LIBCUNIT
#define LIBCUNIT

#include <string>

namespace cunit
{
	class TestSet;
	class TestDataPack;

	class Test
	{
	public:
		Test(const std::string testSet, const std::string name);
		virtual ~Test();

		virtual void PostTest();
		virtual void PreTest();
		virtual void RunTest();

		void SetNextTest(Test* next);
		Test* GetNext() const;

		const std::string TestSetID() const;
		const std::string TestID() const;

		//Test set members
		void AssignTestSet(TestSet* testset);
		TestSet* GetTestSet() const;

		//TestData members
		virtual void AssignDataRepo(TestDataPack* datarepo);
		TestDataPack* GetDataRepo() const;

		int FailCount();
		int SuccessCount();
		int ErrorCount();
	protected:
		std::string _testsetname;
		std::string _testname;

		TestSet* _testset;
		TestDataPack* _testdatarepo;
		Test* _nexttest;

		int fails;
		int success;
		int errors;
	};
};






#endif //LIBCUNIT
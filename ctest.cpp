#include "pch.h"

ctest::Test::Test(const std::string testsetid, const std::string testid) : 
_testname(testid), _testsetname(testsetid), fails(0), success(0), _nexttest(0), _testpartresult(0)
{
	TestRegistry::RegisterTest(this);
}

ctest::Test::~Test()
{
	TestPartialResult* tmp;
	int size = fails + success;

	for (int i = 0; i < size; i++) {
		tmp = _testpartresult;
		_testpartresult = _testpartresult->GetNext();

		delete tmp;
	}
}

void ctest::Test::PostTest(){}
void ctest::Test::PreTest(){}
void ctest::Test::RunTest(){}

ctest::TestSet* ctest::Test::GetTestSet() const
{
	return _testset;
}

void ctest::Test::AssignTestSet(TestSet* testset)
{
	_testset = testset;
}

void ctest::Test::SetNextTest(Test* next)
{
	_nexttest = next;
}

ctest::Test* ctest::Test::GetNext() const
{
	return _nexttest;
}

void ctest::Test::SetPartialResult(TestPartialResult* testPartResult)
{
	TestPartialResult* tmp;
	int type = testPartResult->getType();

	if (_testpartresult == 0) {
		_testpartresult = testPartResult;
		_testpartresult->SetNext(_testpartresult);
	} else {
		tmp = _testpartresult;
		_testpartresult = testPartResult;
		_testpartresult->SetNext(tmp->GetNext());
		tmp->SetNext(_testpartresult);
	}

	if (type == failure) {
		fails++;
	} else if (type == error) {
		errors++;
	} else {
		success++;
	}
}

ctest::TestPartialResult* ctest::Test::getPartialResult() const
{
	TestPartialResult* tpr = _testpartresult;

	if (tpr != 0) {
		tpr = tpr->GetNext();
	}

	return tpr;
}

int ctest::Test::FailCount() const
{
	return fails;
}
int ctest::Test::SuccessCount() const
{
	return success;
}
int ctest::Test::ErrorCount() const
{
	return errors;
}

const std::string ctest::Test::TestID() const
{
	return _testname;
}

const std::string ctest::Test::TestSetID() const
{
	return _testsetname;
}
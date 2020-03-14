#pragma once

#include "pch.h"

#ifndef TESTPARTIALRESULT_H
#define TESTPARTIALRESULT_H

class ctest::TestPartialResult
{
public:
	TestPartialResult(Test* test, const std::string name, long lineNumber, const std::string msg, testRet ret);

	void SetNext(TestPartialResult* next);
	TestPartialResult* GetNext() const;

	testRet getType() const;
	const std::string GetMessage() const;
	Test* GetTest() const;

	const std::string GetFileName() const;
	long GetLineNumber() const;
protected:
	std::string _message;
	Test* test;
	std::string _filename;
	long _linenumber;

private:
	TestPartialResult* _next;
	testRet _type;
};

#endif //TESTPARTIALRESULT_H
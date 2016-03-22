#pragma once

#include "MyString.h"
class QuestionPool
{
public:
	QuestionPool();

	~QuestionPool();

	void SetQuestion(int choice);

	void Print();

private:
	MyString _question;
	MyString _answer;
	int _riddlePoolSize;
	bool _solved = false;
};


#pragma once
#include <cstdlib>

#include "MyString.h"
class QuestionPool
{
public:
	QuestionPool();

	~QuestionPool();

	void SetQuestion(char* question, char* answer);

	void SetAdditionalAnswers(char* answ2);

	void SetAdditionalAnswers(char* answ2, char* answ3);

	void QuestionList(int choice);

	bool CheckAnswer(MyString userAnswer);

	bool CheckSolved();

	void Print();

private:
	MyString* _question = nullptr;
	MyString* _answer = nullptr;
	MyString* _answer2 = nullptr;
	MyString* _answer3 = nullptr;
	int _riddlePoolSize = 11;
	bool _solved = false;
};


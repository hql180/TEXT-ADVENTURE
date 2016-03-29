#pragma once
#include <cstdlib>

#include "MyString.h"
class QuestionPool
{
public:
	QuestionPool();

	QuestionPool(int math);

	~QuestionPool();

	void SetQuestion(char* question, char* answer);

	void SetAdditionalAnswers(char* answ2);

	void SetAdditionalAnswers(char* answ2, char* answ3);

	void QuestionList(int choice);

	void MathList(int choice);

	void GetRiddle();

	bool CheckAnswer(MyString userAnswer);

	//bool CheckAnswer(int userAnswer);

	bool CheckSolved();

	char* GetQuestion();

	void Print();

private:
	MyString* _question = nullptr;
	MyString* _answer = nullptr;
	MyString* _answer2 = nullptr;
	MyString* _answer3 = nullptr;
	MyString _mathQuestion;
	MyString _mathAnswer;
	int _riddlePoolSize = 11;
	bool _solved = false;
	bool _isMath = false;
};


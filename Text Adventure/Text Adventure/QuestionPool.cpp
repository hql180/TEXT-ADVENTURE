#include "QuestionPool.h"



QuestionPool::QuestionPool()
{
	MyString tempQuenstion = "What do you get when you cross a karate expert with a pig?";
	_question = tempQuenstion;
}

QuestionPool::~QuestionPool()
{
	
}

void QuestionPool::SetQuestion(int choice)
{
	MyString temp = "What do you get when you cross a karate expert with a pig?";



	//switch (choice)
	//{
	//case 0:
	////	_question = "What do you get when you cross a karate expert with a pig?";
	//	break;

	//}

}

void QuestionPool::Print()
{
	_question.PrintString();
}

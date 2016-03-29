#include "QuestionPool.h"



QuestionPool::QuestionPool()
{
	GetRiddle();
}

QuestionPool::QuestionPool(int math)
{
	int moreRand = rand() % 4 + 1; // get random number 1-3
	int randQuestion;

	for (int i = 0; i <= moreRand; ++i)
	{
		randQuestion = rand() % 3;
	}
	MathList(randQuestion);
	_isMath = true;
}

QuestionPool::~QuestionPool()
{
	if (_question != nullptr)
	{
		delete _question;
	}
	if (_answer != nullptr)
	{
		delete _answer;
	}
	if (_answer2 != nullptr)
	{
		delete _answer2;
	}
	if (_answer3 != nullptr)
	{
		delete _answer3;
	}
}

void QuestionPool::SetQuestion(char * question, char * answer)
{
	MyString* tempQuenstion = new MyString(question);
	if (_question != nullptr)
	{
		delete _question;
	}
	_question = tempQuenstion;
	MyString* tempAnswer = new MyString(answer);
	if (_answer != nullptr)
	{
		delete answer;
	}
	_answer = tempAnswer;
}

void QuestionPool::SetAdditionalAnswers(char * answ2)
{
	MyString* tempAnswer2 = new MyString(answ2);
	if (_answer2 != nullptr)
	{
		delete _answer2;
	}
	_answer2 = tempAnswer2;
}

void QuestionPool::SetAdditionalAnswers(char * answ2, char * answ3)
{
	MyString* tempAnswer2 = new MyString(answ2);
	if (_answer2 != nullptr)
	{
		delete _answer2;
	}
	_answer2 = tempAnswer2;

	MyString* tempAnswer3 = new MyString(answ3);
	if (_answer3 != nullptr)
	{
		delete _answer3;
	}
	_answer3 = tempAnswer3;
}

void QuestionPool::QuestionList(int choice)
{
	switch (choice)
	{
	case 0:
		SetQuestion("What do you get when you cross a karate expert with a pig?", "porkchop");
		SetAdditionalAnswers("pork chop");
		break;
	case 1:
		SetQuestion("I'm tall when I'm young and I'm short when I'm old. What am I?", "candle");
		break;
	case 2:
		SetQuestion("Mary's father has 5 daughters - Nana, Nene, Nini, Nono. What is the fifth daughters name?", "Mary");
		break;
	case 3:
		SetQuestion("What is the longest word in the dictionary?", "Smiles");
		break;
	case 4:
		SetQuestion("What word becomes shorter when you add two letters to it?", "Short");
		break;
	case 5:
		SetQuestion("What occurs once in a minute, twice in a moment and never in one thousand years?", "M");
		SetAdditionalAnswers("letter");
		break;
	case 6:
		SetQuestion("Take away my first letter, and I still sound the same. \nTake away my last letter, I still sound the same. \nEven take away my letter in the middle, I will still sound the same. \nI am a five letter word. What am I?", "empty");
		break;
	case 7:
		SetQuestion("If an electric train is travelling south, which way is the smoke going?", "No smoke");
		SetAdditionalAnswers("electric train");
		break;
	case 8:
		SetQuestion("Which weighs more, a pound of feathers or a pound of bricks?", "Neither");
		SetAdditionalAnswers("both", "same");
		break;
	case 9:
		SetQuestion("How many months have 28 days?", "All");
		SetAdditionalAnswers("every");
		break;
	case 10:
		SetQuestion("What gets wetter the more it dries?", "Towel");
		SetAdditionalAnswers("sponge");
		break;
	default:
		SetQuestion("Why did the chicken cross the road", "To get to the other side");
		break;
	}
}

void QuestionPool::MathList(int choice)
{
	switch (choice)
	{
	case 0:
		_mathQuestion = "5 x 3 + 3 = ?";
		_mathAnswer = "18";
		break;
	case 1:
		_mathQuestion = "If 10 people can do a piece of work in 5 days, working 2 hours a day, how long will 2 people take to do the same work, working 5 hours a day?";
		_mathAnswer = "10";
		break;
	case 2:
		_mathQuestion = "25, 24, 22, 19, 15, ? What number comes after 15?";
		_mathAnswer = "10";
		break;
	default:
		_mathQuestion = "What is 2 + 2 = ?";
		_mathAnswer = "4";
	}
}

void QuestionPool::GetRiddle()
{
	int moreRand = rand() % 3 + 1; // get random number 1-3
	int randQuestion = 0;

	for (int i = 0; i < 3; ++i)
	{
		randQuestion = rand() % 11;
	}
	QuestionList(randQuestion);
}


bool QuestionPool::CheckAnswer(MyString userAnswer)
{
	MyString answer = userAnswer.ToLower();
	if (answer.GetString() == _mathAnswer.GetString())
	{
		_solved = true;
		return true;
	}
	else if (answer.FindSubString(_answer->ToLower()) != -1)
	{
		_solved = true;
		return true;
	}
	else if (_answer2 != nullptr && answer.FindSubString(_answer2->ToLower()) != -1)
	{
		_solved = true;
		return true;
	}
	else if (_answer3 != nullptr && answer.FindSubString(_answer3->ToLower()) != -1)
	{
		_solved = true;
		return true;
	}
	else
	{
		return false;
	}
}


bool QuestionPool::CheckSolved()
{
	return _solved;
}

char* QuestionPool::GetQuestion()
{
	if (_isMath)
	{
		return _mathQuestion.GetString();
	}
	else
	{
		return _question->GetString();
	}
}



void QuestionPool::Print()
{
	_question->PrintString();
	_answer->PrintString();
}

#include "Coloda.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>


using namespace std;

Coloda::Coloda()
{
	for (int i = 0; i <= 3; ++i)
		for (int j = 6; j <= 14; ++j)
		{
			try
			{
				coloda_.push_back(Card(i, j));
			}
			catch (char *err)
			{
				cout << err;
			}
		}
	Shuffle();
	trump_ = coloda_[rand() % 36 + 1].GetMast();   // выбор случайного козыря
}

Card Coloda::TakeCard()
{
	if (!isEmpty())
	{
		Card card = coloda_.back();		// взятие "верхней" карты из колоды
		coloda_.pop_back();				// удаление взятой карты из колоды
		return card;
	}
	else
		throw ("ERROR! Coloda is empty!\n");
}

void Coloda::Shuffle()
{
	if (!isEmpty())
		shuffle(coloda_.begin(), coloda_.end(), default_random_engine((unsigned)time(NULL)));
}

bool Coloda::isEmpty()
{
	return coloda_.empty();
}

short Coloda::GetTrump()
{
	return trump_;
}


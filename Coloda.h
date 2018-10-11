#pragma once

#include "Card.h" 
#include <vector>

using namespace std;

class Coloda
{
private:
	vector<Card> coloda_;
	short trump_;				// козырь
public:
	Coloda();
	Card TakeCard();			// взять карту из колоды
	void Shuffle();				// перетасовать колоду
	bool isEmpty();				// возвращает true, если колода пустая
	short GetTrump();			// возвращает козырь
};


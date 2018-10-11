#pragma once

#include <vector>

#include "CardSet.h"
#include "Coloda.h"

// Класс игрового стола
class Table
{
private:
	vector<CardSet> players_;			// Вектор игроков (наборов карт)
	Coloda coloda_;						// Колода карт
	const short cardsPerOneSet_ = 6;	// Количество карт, раздаваемых каждому игроку в начале

public:
	Table(short playersNumber = 2);
	short GetBestPlayer();				// Выдает номер "лучшего" игрока из вектора players_
	void ShowTable();
};


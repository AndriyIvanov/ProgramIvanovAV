#pragma once

#include <vector>
#include "Card.h"

using namespace std;

//Класс набора игровых карт (один игрок)
class CardSet
{
private:
	vector<vector<Card>> cards_;		// вектор векторов наборов карт cards_[0] -чирва....cards_[3] -пика

public:
	CardSet();
	void Add(Card card);				// добавление карты в набор
	bool Remove(Card card);				// удаление карты из набора, true - если карта была удалена
	void RemoveAll();					// удаление всех карт из набора
	void Print(short x, short y);		// печать набора карт в позиции (x, y)
	short GetWidth();					// получение ширина набора карт (при печати)
	short GetHeight();					// получение высоты набора карт (при печати)
	short GetMaxValue(short mast);		// получение старшей карты заданной масти (0 - чирва, 1 - бубна, 2 - трефа, 3 -пика)
};


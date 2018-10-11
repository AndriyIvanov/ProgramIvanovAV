#pragma once

class Card
{
private:
	short mast_;		// ЧИРВА=0, БУБНА=1, ТРЕФА=2, ПИКА=3
	short value_;		// 6...10, V-11, D-12, K-13, T-14
	short width_;		// Ширина карты
	short height_;		// Высота карты
	void PrintMast_();	// Печать масти карты

public:
	Card();
	Card(short mast, short value, short height = 8, short width = 8);
	Card& operator = (const Card& obj);
	bool operator == (const Card& obj);
	bool operator < (const Card& obj);
	void Print(short x, short y);		// печать карты в позиции (x, y)
	short GetMast();
	short GetValue();
	short GetWidth();
	short GetHeight();
};



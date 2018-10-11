#pragma once

class Card
{
private:
	short mast_;		// �����=0, �����=1, �����=2, ����=3
	short value_;		// 6...10, V-11, D-12, K-13, T-14
	short width_;		// ������ �����
	short height_;		// ������ �����
	void PrintMast_();	// ������ ����� �����

public:
	Card();
	Card(short mast, short value, short height = 8, short width = 8);
	Card& operator = (const Card& obj);
	bool operator == (const Card& obj);
	bool operator < (const Card& obj);
	void Print(short x, short y);		// ������ ����� � ������� (x, y)
	short GetMast();
	short GetValue();
	short GetWidth();
	short GetHeight();
};



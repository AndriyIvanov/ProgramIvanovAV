#include "Card.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>


using namespace std;

Card::Card() : mast_(0), value_(6), height_(8), width_(8) {}

Card::Card(short mast, short value, short height, short width)
{
	width_ = 8;
	height_ = 8;
	if ((mast >= 0) && (mast <= 3)) mast_ = mast;
	else {
		throw ("ERROR! Incorrect suit!\n");
	}
	if ((value >=6)&&(value<=14)) value_ = value;
	else {
		throw ("ERROR! Incorrect card value!\n");
	}
}

Card & Card::operator=(const Card & obj)
{
	mast_ = obj.mast_;
	value_ = obj.value_;
	return *this;
}

bool Card::operator==(const Card & obj)
{
	return (mast_ == obj.mast_ && value_ == obj.value_);
}

bool Card::operator<(const Card & obj)
{
	return value_ < obj.value_;
}

void Card::Print(short x, short y)
{
	SetConsoleOutputCP(866);
	SetConsoleCP(866);
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (WORD)((7 << 4) | 2));			//Установка цвета карты (зеленый шрифт на сером фоне)
	string Indication;
	if (value_<=10) Indication = to_string(value_);
	else if (value_ == 11) Indication = "J";
	else if (value_ == 12) Indication = "Q";
	else if (value_ == 13) Indication = "K";
	else if (value_ == 14) Indication = "A";
	SetConsoleCursorPosition(h, coord);
	cout << char(218) << setw(width_-1) << setfill(char(196)) << char(191);
	coord.Y += 1;
	SetConsoleCursorPosition(h, coord);
	if (value_ == 10)
	{
		cout << char('|'); 
		PrintMast_();
		cout << Indication << setw(width_ - 4) << setfill(' ') << char('|');
	}
	else
	{
		cout << char('|');
		PrintMast_();
		cout << Indication << setw(width_ - 3) << setfill(' ') << char('|');
	}
	for (int i = 0; i < height_-4; ++i)
	{
		coord.Y += 1;
		SetConsoleCursorPosition(h, coord);
		cout << char('|') << setw(width_-1) << setfill(' ') << char('|');
	}
	coord.Y += 1;
	SetConsoleCursorPosition(h, coord);
	if (value_ == 10)
	{
		cout << char('|') << setw(width_ - 3) << setfill(' ') << Indication;
		PrintMast_();
		cout << char('|');
	}
	else
	{
		cout << char('|') << setw(width_ - 3) << setfill(' ') << Indication;
		PrintMast_();
		cout << char('|');
	}
	coord.Y += 1;
	SetConsoleCursorPosition(h, coord);
	cout << char(192) << setw(width_-1) << setfill(char(196)) << char(217) << endl;

	SetConsoleTextAttribute(h, (WORD)((9 << 4) | 15));			//Возврат к цвету главного окна (белый шрифт на синем фоне)

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
}

short Card::GetMast()
{
	return mast_;
}

short Card::GetValue()
{
	return value_;
}

short Card::GetWidth()
{
	return width_;
}

short Card::GetHeight()
{
	return height_;
}

void Card::PrintMast_()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (mast_)
	{
		case (0):
		case (1):
		{
			SetConsoleTextAttribute(console, (WORD)((7 << 4) | 12));  //Установка цвета: красный шрифт на сером фоне
			break;
		}
		case (2):
		case (3):
		{
			SetConsoleTextAttribute(console, (WORD)((7 << 4) | 0));  //Установка цвета: черный шрифт на сером фоне
			break;
		}
	}
	cout << char(mast_+3);
	SetConsoleTextAttribute(console, (WORD)((7 << 4) | 2));  //Возврат к цветам карты (зеленый шрифт на сером фоне)
}


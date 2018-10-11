#include "Table.h"
#include "Window.h"
#include "ServiceWindow.h"
#include <string>
#include <iostream>

using namespace std;

Table::Table(short playersNumber)
{
	for (int i = 0; i < playersNumber; ++i)
	{
		CardSet temp;
		for (int j = 0; j < cardsPerOneSet_; ++j)
		{
			if (!coloda_.isEmpty()) temp.Add(coloda_.TakeCard());
			else throw ("ERROR! Coloda is empty!");
		}
		players_.push_back(temp);
		temp.RemoveAll();
	}
}

short Table::GetBestPlayer()
{
	short BestPlayerNumber = 0;
	bool FlagTrump = false;										//признак наличия козырей на руках

	for (unsigned int i = 0; i < players_.size(); ++i)
	{
		if (players_[i].GetMaxValue(coloda_.GetTrump()) > 0) FlagTrump = true;											//есть козыри на руках
		if (players_[i].GetMaxValue(coloda_.GetTrump()) > players_[BestPlayerNumber].GetMaxValue(coloda_.GetTrump()))
			BestPlayerNumber = i;
	}
	if (FlagTrump) return BestPlayerNumber;						// если козыри есть, определяем "лучшего игрока" по старшему козырю
	else														// если козырей нет, определяем "лучшего игрока" по сумме старших карт в мастях
	{
		short BestSum = 0;
		for (unsigned int i = 0; i < players_.size(); ++i)		// проход по игрокам
		{
			short tempSum = 0;
			for (unsigned int j = 0; j < 4; ++i)				// проход по мастям
				tempSum += players_[i].GetMaxValue(j);
			if (tempSum > BestSum)
			{
				BestSum = tempSum;
				BestPlayerNumber = i;
			}
			tempSum = 0;
		}
		return BestPlayerNumber;
	}
}

void Table::ShowTable()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// скрываем мигающий курсор
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(console, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(console, &structCursorInfo);

	Window window;
	window.PrintWindow();
	size_t current_X = 5;
	size_t current_Y = 5;
	
	// масштабирование наборов относительно окна
	size_t delta_X = 0;
	if (players_.size() > 1)
		delta_X = window.GetWidth() - players_[0].GetWidth() - 11;
	size_t delta_Y = 0;
	if (players_.size() > 2)
		delta_Y = (window.GetHeight() - players_[0].GetHeight()*((players_.size()-1)/2 + 1) - 10)/ ((players_.size() - 1) / 2) + players_[0].GetHeight();
	
	//печать наборов
	COORD coord = { 0, 0 };
	for (unsigned int i = 0; i < players_.size(); ++i)
	{
		players_[i].Print((short)(current_X+(i%2)*delta_X), short(current_Y+(i/2)*delta_Y));
		coord.X = (short)(current_X + (i % 2)*delta_X + 10);
		coord.Y = (short)(current_Y + (i / 2)*delta_Y - 2);
		SetConsoleCursorPosition(console, coord);
		cout << "Player " << i + 1;
	}

	//печать козыря 
	short servWidth = 15;
	short servHeight = 6;
	short serv_X = ((short)window.GetWidth() - servWidth) / 2;
	short serv_Y = 1;
	short servColor = 14;
	ServiceWindow servwind(serv_X, serv_Y, servHeight, servWidth, servColor); //печать окна желтого цвета
	servwind.PrintWindow();

	SetConsoleTextAttribute(console, (WORD)((14 << 4) | 2));				 //Установка основного цвета надписи (зеленый шрифт на желтом фоне)

	string text{ "Trump:" };

	coord = { (serv_X + (servWidth - (short)text.length())/2 - 1), (serv_Y + servHeight/2 - 1) };
	SetConsoleCursorPosition (console, coord);
	cout << text;

	SetConsoleOutputCP(866);
	SetConsoleCP(866);
	// печатаем масть
	switch (coloda_.GetTrump())
	{
		case (0):
		case (1):
		{
			SetConsoleTextAttribute(console, (WORD)((14 << 4) | 12));  //Установка цвета: красный шрифт на желтом фоне
			break;
		}
		case (2):
		case (3):
		{
			SetConsoleTextAttribute(console, (WORD)((14 << 4) | 0));  //Установка цвета: черный шрифт на желтом фоне
			break;
		}
	}
	cout << char(coloda_.GetTrump() + 3);
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	servWidth = 25;
	servHeight = 15;
	serv_X = ((short)window.GetWidth() - servWidth) / 2;
	serv_Y = ((short)window.GetHeight() - servHeight) / 2;
	servColor = 11;														// голубой цвет окна
	servwind = ServiceWindow(serv_X, serv_Y, servHeight, servWidth, servColor);
	servwind.PrintWindow();
	SetConsoleTextAttribute(console, (WORD)((11 << 4) | 12));			//установка цвета: красный шрифт на голубом фоне
	text = "Player #";
	coord = { (serv_X + (servWidth - (short)text.length()) / 2 - 1), (serv_Y + servHeight / 2 - 3) };	
	SetConsoleCursorPosition(console, coord);
	cout << text << GetBestPlayer() + 1;
	text = "has the best";
	coord.X = (serv_X + (servWidth - (short)text.length()) / 2);
	coord.Y += 2;
	SetConsoleCursorPosition(console, coord);
	cout << text;
	text = "card set";
	coord.X = (serv_X + (servWidth - (short)text.length()) / 2);
	coord.Y += 2;
	SetConsoleCursorPosition(console, coord);
	cout << text;
	
}

#include "Game.h"
#include "Window.h"
#include "Table.h"

#include <windows.h>
#include <locale>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

Game::Game()
{
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);

	int button = 0;
	Window window;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());    //очищаем буфер ввода
		window.PrintWindow();
		string text = "Input number of players (number from 1 to 6): ";
		COORD coord = { short((window.GetWidth() - (short)text.length()) / 2 - 1), short(window.GetHeight()/ 2 - 1) };
		SetConsoleCursorPosition(console, coord);
		cout << text;
		if ((!(cin >> playersNumber_)) || (playersNumber_ < 1 || playersNumber_ > 6)) continue;   //проверяем правильность ввода

		Table table(playersNumber_);
		table.ShowTable();
		
		text = "Press any key to continue or Esc to exit";
		SetConsoleTextAttribute(console, (WORD)((9 << 4) | 15));				 //Установка основного цвета надписи (белый шрифт на синем фоне)
		coord.X = (short)((window.GetWidth() - text.length()) / 2 - 1);
		coord.Y = (short) (window.GetHeight() - 3);
		SetConsoleCursorPosition(console, coord);
		cout << text;
		button = _getch();

	} while (button != 27);
}


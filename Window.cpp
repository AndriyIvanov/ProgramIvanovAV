#include "Window.h"

#include <string>
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

size_t Window::GetHeight()
{
	return Height_;
}

size_t Window::GetWidth()
{
	return Width_;
}

void Window::PrintWindow()
{
	system("color 9F");								//Установка основных цветов окна (белый шрифт на синем фоне)
	string WindowSize = "mode con cols=";
	WindowSize += to_string(Width_);
	WindowSize += " lines=";
	WindowSize += to_string(Height_);
	system(WindowSize.c_str());						//Установка размера окна

	SetConsoleOutputCP(866);
	SetConsoleCP(866);
	
	cout << char(201) << setw(Width_-2) << setfill(char(205)) << char(187) << endl;
	for (size_t i = 0; i<Height_-3; ++i)
		cout << char(186) << setw(Width_ - 2) << setfill(' ') << char(186) << endl;
	cout << char(200) << setw(Width_ - 2) << setfill(char(205)) << char(188) << endl;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
}




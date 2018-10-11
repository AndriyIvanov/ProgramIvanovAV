#pragma once

class Window
{
	size_t Height_;
	size_t Width_;
public:
	Window(size_t Height= 43, size_t Width=99) :  Height_(Height), Width_(Width)	{};
	size_t GetHeight();
	size_t GetWidth();
	void PrintWindow();
};


#pragma once

#include <vector>

#include "CardSet.h"
#include "Coloda.h"

// ����� �������� �����
class Table
{
private:
	vector<CardSet> players_;			// ������ ������� (������� ����)
	Coloda coloda_;						// ������ ����
	const short cardsPerOneSet_ = 6;	// ���������� ����, ����������� ������� ������ � ������

public:
	Table(short playersNumber = 2);
	short GetBestPlayer();				// ������ ����� "�������" ������ �� ������� players_
	void ShowTable();
};


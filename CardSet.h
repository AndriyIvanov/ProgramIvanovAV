#pragma once

#include <vector>
#include "Card.h"

using namespace std;

//����� ������ ������� ���� (���� �����)
class CardSet
{
private:
	vector<vector<Card>> cards_;		// ������ �������� ������� ���� cards_[0] -�����....cards_[3] -����

public:
	CardSet();
	void Add(Card card);				// ���������� ����� � �����
	bool Remove(Card card);				// �������� ����� �� ������, true - ���� ����� ���� �������
	void RemoveAll();					// �������� ���� ���� �� ������
	void Print(short x, short y);		// ������ ������ ���� � ������� (x, y)
	short GetWidth();					// ��������� ������ ������ ���� (��� ������)
	short GetHeight();					// ��������� ������ ������ ���� (��� ������)
	short GetMaxValue(short mast);		// ��������� ������� ����� �������� ����� (0 - �����, 1 - �����, 2 - �����, 3 -����)
};


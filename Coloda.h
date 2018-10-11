#pragma once

#include "Card.h" 
#include <vector>

using namespace std;

class Coloda
{
private:
	vector<Card> coloda_;
	short trump_;				// ������
public:
	Coloda();
	Card TakeCard();			// ����� ����� �� ������
	void Shuffle();				// ������������ ������
	bool isEmpty();				// ���������� true, ���� ������ ������
	short GetTrump();			// ���������� ������
};


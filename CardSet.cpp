#include <algorithm>
#include <windows.h>
#include "CardSet.h"

CardSet::CardSet()
{
	cards_.resize(4);
}

void CardSet::Add(Card card)
{
	cards_[card.GetMast()].push_back(card);
	sort(cards_[card.GetMast()].rbegin(), cards_[card.GetMast()].rend());
}

bool CardSet::Remove(Card card)
{
	for (int i = 0; i < 4; ++i)
	{
		for (unsigned int j = 0; j < cards_[i].size(); ++j)
			if (cards_[i].at(j) == card)
			{
				cards_[i].erase(cards_[i].begin() + j);
				cards_[i].shrink_to_fit();
				sort(cards_[i].rbegin(), cards_[i].rend());
				return true;
			}
	}
	return false;
}

void CardSet::RemoveAll()
{
	for (int i = 0; i < 4; ++i)
		cards_[i].clear();
}

void CardSet::Print(short x, short y)
{
	short current_x = x;
	for (int i = 0; i < 4; ++i)
	{
		if (!cards_[i].empty())
		{
			for (Card el : cards_[i])
			{
				el.Print(current_x, y);
				current_x += (el.GetWidth() / 2);
			}
		}
	}
}

short CardSet::GetWidth()
{
	if (cards_[0].empty() && cards_[1].empty() && cards_[2].empty() && cards_[3].empty())
		throw ("ERROR! Set is empty!");
	short cardsNumber = 0;
	short cardWidth = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (!cards_[i].empty())
		{
			cardWidth = cards_[i].front().GetWidth();
			cardsNumber += (short)cards_[i].size();
		}
	}
	return (cardWidth / 2)*(cardsNumber+1);
}

short CardSet::GetHeight()
{
	for (int i = 0; i < 4; ++i)
		if (!cards_[i].empty()) return cards_[i].front().GetHeight();
	throw ("ERROR! Set is empty!");
}

short CardSet::GetMaxValue(short mast)
{
	if (cards_[mast].empty()) return 0;
	return cards_[mast].front().GetValue();
}

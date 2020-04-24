#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <stack>
#include <time.h>

using namespace std;

//Student asked how to create a deck of playing cards without using vectors or arrays.

struct card
{
	string cardType;
	int cardValue;
	
	card() {}
	card(string name, int value)
	{
		cardType = name;
		cardValue = value;
	}
};

stack<card> shuDeck();
card drawCard(stack<card> &deck);

int main()
{
	stack<card> deck;
	deck = shuDeck();
	
	card myCard = drawCard(deck);

	return 0;
}

stack<card> shuDeck()
{
	unordered_map<int, card> newDeck;
	stack<card> doneDeck;
	srand(time(NULL));

	int counter = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			card newCard;

			switch (i)
			{
			case 0:
				newCard.cardType = "Spade";
				newCard.cardValue = j;
				break;
			case 1:
				newCard.cardType = "Clubs";
				newCard.cardValue = j;
				break;
			case 2:
				newCard.cardType = "Diamonds";
				if(j >= 10)
					newCard.cardValue = 10;
				else
					newCard.cardValue = j;
				break;
			case 3:
				newCard.cardType = "Hearts";
				newCard.cardValue = j;
				break;
			}

			newDeck.emplace(counter, newCard);
			counter++;
		}
	}

	while (newDeck.size() > 0)
	{
		unordered_map<int, card>::iterator random_it = newDeck.begin();
		advance(random_it, (rand() % newDeck.size()));
		doneDeck.push(random_it->second);
		newDeck.erase(random_it);
	}

	return doneDeck;
}

card drawCard(stack<card>& deck)
{
	card newCard = deck.top();
	deck.pop();
	return newCard;
}

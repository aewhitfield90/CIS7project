// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;

string deckDraw(bool cardAvailableCheck, int& elementHolder, string cardHolder, string deck[])
{
	while (cardAvailableCheck == true)
	{
	
		int random = (rand() % 52) - 1;
		if (random == -1)
			random = 0;
		if (deck[random] == "TAKEN")
		{
			cout << "card: " << deck[elementHolder] << " was taken already. \n";
			random = (rand() % 52) - 1;
		}
		else
		{
			
			elementHolder = random;
			cardHolder = deck[random];
			deck[random] = "TAKEN";
			cardAvailableCheck = false;
			return cardHolder;
		}
	}
}

int main()
{
	srand((unsigned)time(0));
	bool drawCheck = true;
	bool userCheck = true;
	bool dealerCheck = true;
	bool cardAvailableCheck = true;
	bool playerChoice = true;
	int elementHolder = 0;
	int playerTurn = 0;
	string cardHolder = "";
	string dealer = "";
	string player = "";
	int playerPoint = 0;
	int player1 = 0;
	int dealer1 = 0;
	string deck[52] = { "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS",
							"2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC",
							"2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH",
							"2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD" };
	int point[52] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
					2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
					2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
					2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

	//vector<string> d(deck, deck + 52);
	cout << "Hello! Welcome to the game of Black Jack!\n";

	while (drawCheck == true)
	{
		
		player += deckDraw(cardAvailableCheck, elementHolder, cardHolder, deck);
		player1 += point[elementHolder];
		dealer += deckDraw(cardAvailableCheck, elementHolder, cardHolder, deck);
		dealer1 += point[elementHolder];
		player += deckDraw(cardAvailableCheck, elementHolder, cardHolder, deck);
		player1 += point[elementHolder];
		dealer += deckDraw(cardAvailableCheck, elementHolder, cardHolder, deck);
		dealer1 += point[elementHolder];
		cout << "player1 points: " << player1 << endl;
		cout << "dealer1 points: " << dealer1 << endl;
		if (player1 == 21 && dealer1 != 21)
		{
			cout << "21! You Win!" << endl;
			system("pause");
			exit;
		}
		else if (player1 != 21 && dealer1 == 21)
		{
			cout << "Dealer has 21, you lose!" << endl;
			system("pause");
			exit;
		}
		else if (player1 == 21 && dealer1 == 21)
		{
			cout << "Black Jack Tie!" << endl;
			player = "";
			player1 = 0;
			dealer = "";
			dealer1 = 0;
		}
		else
			drawCheck =false;



	}
			while (playerChoice == true)
			{
			cout << "Player cards: " << player << endl;
			cout << "Dealer cards: " << dealer << endl;
			cout << "Would you like to: \n";
			cout << "  1 - Hit \n";
			cout << "  2 - Stand \n";
			cin >> playerTurn;
			cout << endl;
			
				switch (playerTurn)
				{
				case 1:
					{
						player += deckDraw(cardAvailableCheck, elementHolder, cardHolder, deck);
						player1 += point[elementHolder];
						cout << "player1 points: " << player1 << endl;
						if (player1 > 21)
						{
							cout << "Bust! You lose" << endl;
							system("pause");
						}
					}
					break;
				case 2:
					playerChoice = false;
					break;
				
				}
			}
			while (dealerCheck == true)
			{
				if (dealer1 < 17)
				{
					cout << "Dealer Hit" << endl;
					dealer += deckDraw(cardAvailableCheck, elementHolder, cardHolder, deck);
					dealer1 += point[elementHolder];
					cout << "Dealer points: " << dealer1 << endl;
					if (dealer1 > 21)
					{
						cout << "Dealer Busts! You Win!" << endl;
						system("pause");
						exit;
					}
				}
				else
				{
					if (dealer1 > player1)
					{
						cout << "You Lose!" << endl;
						dealerCheck = false;
					}
					else if (dealer1 < player1)
					{
						cout << "You Win!" << endl;
						dealerCheck = false;
					}
					else if (dealer1 == player1)
					{
						cout << "You Tie......." << endl;
						dealerCheck = false;
					}
				}
			}

	system("pause");
}



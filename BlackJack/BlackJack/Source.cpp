#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main() {

	string faces[13] = {"Ace","Two","Three","Four","Five" ,"Six" ,"Seven" ,"Eight" ,"Nine" ,"Ten" ,"Jack" ,"Queen","King"};
	int randomCard;
	int userTotal = 0;
	int dealerTotal = 0;
	int bust = 21;
	char play;
	char hit;
	char replay;
	bool game;


	cout << "WELCOME TO BLACKJACK: THE RULES OF THE GAME IS TO HAVE CARDS DEALT TO YOU WITH THE GOAL OF BEATING THE DEALER.\nADDITIONALLY, IF YOU REACH A NUMBER HIGHER THAN 21, YOU BUST AND LOSE THE GAME.\n"
		<< "Ready to play? [Y/N]...\n";
	cin >> play;

	if (play == 'Y') {
		game = true;
	}
	else {
		game = false;
		cout << "Coward";
	}

	while (game) {

		cout << "Drawing Cards...\n";
		srand(time(NULL));
		for (int userCards = 0; userCards < 2; userCards++) {
			randomCard = rand() % 13;
			cout << "You were dealt a(n) " << faces[randomCard] << ".\n";
			if (randomCard == 0) {
				cout << "Do you want this ace to count as the value of 1 or 11?...\n";
				cin >> randomCard;
			}
			else if (randomCard == 10 || randomCard == 11 || randomCard == 12) {
				randomCard = 9;
			}
			userTotal += randomCard + 1;
		}
		for (int dealerCards = 0; dealerCards < 2; dealerCards++) {
			randomCard = rand() % 13;
			cout << "The Dealer draws.\n";
			if (randomCard == 10 || randomCard == 11 || randomCard == 12) {
				randomCard = 9;
			}
			dealerTotal += randomCard + 1;
		}

		bool cont = true;
		while (cont) {
			cout << "Your total points are " << userTotal << ", would you like to hit? [Y/N]\n";
			cin >> hit;

			if (bust - dealerTotal >= 6) {
				randomCard = rand() % 13;
				if (randomCard == 10 || randomCard == 11 || randomCard == 12) {
					randomCard = 9;
				}
				dealerTotal += randomCard + 1;
			}

			if (hit == 'Y') {
				randomCard = rand() % 13;
				cout << "You were dealt a(n) " << faces[randomCard] << ".\n";
				if (randomCard == 0) {
					cout << "Would you like the ace to be the value of 1 or 11?...\n";
					cin >> randomCard;
				}
				else if (randomCard == 10 || randomCard == 11 || randomCard == 12) {
					randomCard = 9;
				}
				userTotal += randomCard + 1;
			}
			else if (hit == 'N') {
				cout << "Your total is " << userTotal << ", and the dealer got " << dealerTotal << ".\n";
				cont = false;
			}

		}
		if (userTotal == bust) {
			cout << "You got blackjack! You win! \n";
		}
		else if (userTotal > bust) {
			cout << "You've busted! You lose...\n";
		}
		else {
			if (userTotal > dealerTotal) {
				cout << "You got a higher score than the dealer, you win!\n";
			}
			else if (dealerTotal > userTotal) {
				cout << "The dealer got a higher score than you, you lose...\n";
			}
		}

		cout << "Would you like to play again? [Y/N]...";
		cin >> replay;
		if (replay == 'Y') {
			userTotal = 0;
			dealerTotal = 0;
			randomCard = 0;
		}
		else if (replay == 'N') {
			game = false;
		}
	}

	return 0;
}

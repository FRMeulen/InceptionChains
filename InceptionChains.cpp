	//Inclusions
#include "Chain.h"
#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

	//Definitions
#define activeChain chains.at(currentChain)

	//Namespace
using namespace std;

	//Fields
bool clearing = true;	//Set to false if you don't want the screen to clear
bool gameAlive = true;	//Will be set to false when player answers wrongly
vector<Chain> chains;	//Contains chains
int chainCounter = 0;	//Amount of chains
int currentChain = 0;	//Chain currently calculating on
int players;			//Amount of players
int activePlayer = 1;	//Player currently active
string input;			//Input from player

	//Methods
//Adds chain to chain vector
void addChain() {
	chainCounter++;
	Chain newChain(chainCounter);
	chains.push_back(newChain);
}

//Verifies input
void verifyInput(string userInput, Chain chain) {
	//Verify if BOOM first
	if (chain.checkBoom()) {
		if (chain.getNumber() == 7) {	//If first boom of chain
			addChain();	//Add new chain
		}

		currentChain++;
		activeChain.count();
		verifyInput(userInput, activeChain);
		currentChain = 0;
	}

	//Then for numbers
	else {
		if (userInput == to_string(chain.getNumber())) {
			if (clearing) {
				system("cls");
			}
			else {
				cout << endl;
				cout << "Chain: " << chain.getChainNumber() << " | Number: " << chain.getNumber() << endl;
				cout << "Your answer: " << userInput << " is correct!" << endl;
				cout << "---------------------------------------" << endl;
			}
		}
		else {
			cout << endl;
			cout << "---WRONG---WRONG---WRONG---" << endl;
			cout << "Chain: " << chain.getChainNumber() << " | Number: " << chain.getNumber() << endl;
			gameAlive = false;
		}
	}
}

//Plays a turn of the game
void playTurn() {
	activeChain.count();
	cout << "Player " << activePlayer << ", what will the next number be?" << endl;
	cout << "The next number is: ";
	getline(cin, input);
	verifyInput(input, activeChain);
	
	if (activePlayer == players) {
		activePlayer = 1;
	}
	else {
		activePlayer++;
	}
}

	//Main
int main()
{
	//Determine amount of players
	cout << "How many players intend to join? ";
	cin >> players;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("cls");
	
	//Set up game
	addChain();

	//Start
	while (gameAlive) {
		playTurn();
	}

	//Done
	system("Pause");
	return 0;
}
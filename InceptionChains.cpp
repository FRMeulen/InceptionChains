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
bool gameAlive = true;
vector<Chain> chains;
int chainCounter = 0;
int currentChain = 0;
int players;
int activePlayer = 1;
string input;

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
		if (userInput == "BOOM" || userInput == "boom" || userInput == "Boom") {
			system("cls");
		}
		else {
			cout << "WRONG! Should have said BOOM!" << endl;
			gameAlive = false;
		}
	}

	//Then for numbers
	else {
		if (userInput == to_string(chain.getNumber())) {
			system("cls");
		}
		else {
			cout << "WRONG! Should have said " << chain.getNumber() << "!" << endl;
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
//Inclusions
#include "Chain.h"
#include <math.h>
#include <iostream>

//Namespace
using namespace std;

//Constructor
Chain::Chain(int chainCount) {
	chainNumber = chainCount;
}

//Destructor
Chain::~Chain() {

}

//Methods
void Chain::count() {
	number++;
	if (checkBoom(number)) {
		cout << "Chain:\t" << chainNumber << endl;
		cout << "Number:\tBOOM (" << number << ")" << endl << endl;
	}
}

bool Chain::checkBoom(int i) {
	int number = i;	//Original number
	int toFind = 7;	//Number to find

	if (number % toFind == 0) {	//If multiple of seven
		return true;
	}

	int tempNumber = number;	//Number for calculation
	int tempDigit;	//Digit being checked

	while (tempNumber != 0) {	//While not at zero
		tempDigit = tempNumber % 10;	//Go to next digit
		tempNumber = tempNumber / 10;	//Divide by ten to remove first digit

		if (tempDigit == toFind) {	//If current digit is seven
			return true;
		}
	}
	return false;	//If no seven in number return false
}

int Chain::getNumber() {
	return number;
}

int Chain::getChainNumber() {
	return chainNumber;
}
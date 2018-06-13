	//Inclusions
#include "Chain.h"
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
//Counts up the number
void Chain::count() {
	number++;
}

//Checks if number contains 7 or is a multiple of 7
bool Chain::checkBoom() {
	int calcNumber = number;	//Original number
	int toFind = 7;	//Number to find

	if (calcNumber % toFind == 0) {	//If multiple of seven
		return true;
	}

	int tempNumber = calcNumber;	//Number for calculation
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

//Returns current number
int Chain::getNumber() {
	return number;
}

//Returns chain number
int Chain::getChainNumber() {
	return chainNumber;
}
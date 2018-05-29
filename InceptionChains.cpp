//Inclusions
#include "Chain.h"
#include <math.h>
#include <iostream>
#include <vector>

//Namespace
using namespace std;

//Fields
vector<Chain> chains;
int chainCounter = 0;

//Methods
void addChain() {
	chainCounter++;
	Chain newChain(chainCounter);
	chains.push_back(newChain);
}

//Main
int main()
{
	addChain();	//Initial chain

	for (int i = 0; i < 800; i++) {
		chains.at(0).count();
	}

	system("Pause");
	return 0;
}
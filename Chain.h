//Pragma
#pragma once

//Class
class Chain
{
private:
	int number = 0;
	int chainNumber;

public:
	Chain(int chainCount);	//Constructor
	~Chain();	//Destructor
	void count();	//Count
	bool checkBoom();	//Check if valid or BOOM
	int getNumber();	//Returns number
	int getChainNumber();	//Returns chain number
};
#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Dice{

private:
	int face;
	int value;

public:
	Dice() :face(1) {};
	Dice(int face) :face(face) {};
	Dice(Dice &other) : face(other.getFace()) {};
	Dice & operator=(Dice &rhs){
		if (this != &rhs){
			face = rhs.getFace();
		}
		return *this;
	};

	int roll() {
		face = rand() % 6 + 1;
		return face;
	}

	int getValue() { return value; }

	int getFace() { return face; }

};

#endif 

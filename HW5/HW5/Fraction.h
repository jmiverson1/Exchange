#ifndef  FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction {

private:
	int *numerator;
	int *denominator;
	
public:

	// AUXILARY FUNCTIONS 
	//Defining the greatest common denominator function. 
	//Finds the remainder of the numerator and denominator. 
	//Then the numerator and the first remainder. 
	//Loops with the subsequent remainders until the remainder equals zero and the value prior to that is the gcd.
	int gcd(int n, int m) {
		if (n == 0)
			return m;
		else
			gcd(m % n, n);
	}
	//The reduce function divides the numerator and denominator by the gcd. 
	void reduce() { 
		int great = gcd(*numerator, *denominator);
		*numerator = *numerator / great;
		*denominator = *denominator / great;
	} // simplify the fraction by removing the common factors between numerator and denominator, denominator always greater than 0.

	// constructors 

	Fraction() : numerator(new int(0)), denominator(new int(1)) {
		cout << "Default Constuctor for " << *this << endl;
	};    // default construcotr   0/1


	Fraction(int n) : numerator(new int(n)), denominator(new int(1)) {};  // Fraction  n/1


	Fraction(int n, int m) :numerator(new int(n)), denominator(new int(m)){};   // n/m  and must be simplified so that there is no common factor between numerator and denominator

	Fraction(Fraction & other){
		cout << "Copy Constructor for " << other << endl;
		numerator = new int;
		denominator = new int;
		*numerator = *other.numerator;
		*denominator = *other.denominator;
	}; // copy  constructor
	//Created get functions for logical checks of the uder inputs in the cpp file.
	const int& getNum() const { return *numerator; }

	const int& getDen() const { return *denominator; }

	// operators overloading 

	Fraction & operator = (Fraction & rhs){
		if (*this != rhs){
			cout << "Overloaded Assignment Operator for " << rhs << endl;
			delete numerator;
			delete denominator;
			numerator = new int;
			denominator = new int;
			*numerator = *(rhs.numerator);
			*denominator = *(rhs.denominator);
		}
		return *this;
	};   // overload assignment operator

	~Fraction() { cout << "Destructor for " << *this << endl; delete numerator; delete denominator; };     // destructor

	// relational operators < <= > >=   ==  !=

	bool operator < (Fraction & rhs){
		return ((float)(*numerator / *denominator) < (float)(*rhs.numerator / *rhs.denominator));
	};
			
	bool operator <= (Fraction & rhs){
		return !(*this > rhs);
	};

	bool operator > (Fraction & rhs){
		return rhs < *this;
	};

	bool operator >= (Fraction & rhs){
		return !(*this < rhs);
	};

	bool operator == (Fraction & rhs){
		return ((*numerator * *rhs.denominator) == (*denominator * *rhs.numerator));
	};

	bool operator !=(Fraction &rhs){
		return ((*numerator * *rhs.denominator) != (*denominator * *rhs.numerator));
	};

	// overload arithmetic operators

	Fraction & operator +(Fraction & rhs){
		Fraction* temp;
		temp = new Fraction((*numerator * *rhs.denominator) + (*denominator * *rhs.numerator), (*denominator * *rhs.denominator));
		return *temp;
	};   // addition

	Fraction & operator -(Fraction & rhs){   // subtraction
		Fraction* temp;
		temp = new Fraction((*numerator * *rhs.denominator) - (*denominator * *rhs.numerator), (*denominator * *rhs.denominator));
		return *temp;
	};

	Fraction & operator * (Fraction & rhs){
		Fraction* temp;
		temp = new Fraction((*numerator * *rhs.numerator), (*denominator * *rhs.denominator));
		return *temp;
	};  // multiplication

	Fraction & operator / (Fraction & rhs){
		Fraction* temp;
		temp = new Fraction((*numerator * *rhs.denominator), (*denominator * *rhs.numerator));
		return *temp;
	};   // division


	////////////////  increment and decrement

	Fraction & operator++(){
		*numerator += *denominator;
		return *this;
	};   // prefix increment

	Fraction operator ++ (int){
		Fraction temp(*this);
		++*this;
		return temp;
	};  // postfix increment

	Fraction & operator--(){
		*numerator -= *denominator;
		return *this;
	};      // prefix decrement

	Fraction operator -- (int){
		Fraction temp(*this);
		--*this;
		return temp;
	};  // postfix decrement

	Fraction & operator ^(int n){
		Fraction temp(*this);
		if (n == 0){
			*this = Fraction(1, 1);
		}
		else if (n > 0){
			for (int i = 0; i < (n - 1); i++)
				*this = *this * temp;
		}
		else if (n < 0){
			n = -n;
			for (int i = 0; i < (n - 1); i++){
				*this = *this * temp;
			}
			*this = Fraction(*denominator, *numerator);
		}
		else
			;
		return *this;
	};    //   exponentiation    : raise to the power n 


	////////////////////////////////////////////////////////////////////////////////////

	bool isZero() {
		return (*numerator == 0);
	}

	bool isNegative() {
		return  (*numerator < 0);
	}

	bool isPositive() {
		return (*numerator > 0);
	}

	bool isProper() {
		if (abs(*numerator) < *denominator) return true;
		else return false;
	}



	string toString(){
		string tmp;

		char buf[80];
		if (*denominator != 1)
			sprintf_s(buf, "%d/%d", *numerator, *denominator);
		else sprintf_s(buf, "%d", *numerator);
		tmp = string(buf);

		return tmp;
	}



	char *str() {

		int len = toString().length();
		char *tmp = new char[toString().length() + 1];


		strcpy_s(tmp, toString().length() + 1, toString().c_str());

		return tmp;


	}

	//Using the boolean functions to ensure the outputs are consistent with the assignment's requirements. 
	friend ostream & operator<<(ostream & out, Fraction & rhs){
		rhs.reduce();
		if (rhs.isZero())
			out << 0;
		else if (*rhs.denominator == 1){
			out << *rhs.numerator;
		}
		else if (*rhs.denominator == -1){
			out << -*rhs.numerator;
		}
		else if (*rhs.denominator < -1){
			out << -*rhs.numerator << "/" << -*rhs.denominator;
		}
		else{
			out << *rhs.numerator << "/" << *rhs.denominator;
		}
		return out;
	};

	friend istream & operator>>(istream & in, Fraction & f);

	friend istream & operator>>(istream & in, Fraction & f){

		char slash;
		int num, denom;
		in >> num;
		in >> slash;

		in >> denom;

		*(f.numerator) = num;
		*(f.denominator) = denom;;
		f.reduce();

		return in;

	}

};

#endif

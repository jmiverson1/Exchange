#include <iostream>
#include <string>
#include <iomanip>
#include "Fraction.h"

using namespace std;

//Declared a menu function and a function for each of the five demonstrations.

void menu(int choice, Fraction f1, Fraction f2, int n);

Fraction bigThree(Fraction f1, Fraction f2);

Fraction arithmetic(Fraction f1, Fraction f2);

Fraction prePost(Fraction f1, Fraction f2);

Fraction relational(Fraction f1, Fraction f2);

Fraction power(Fraction f1, int n);

Fraction & add1(Fraction & x, Fraction & y){
	Fraction *tmp = new Fraction(x + y);
	cout << "Last line of add1" << endl;
	return *tmp;
	cout << "End of add1" << endl;
}

Fraction  add2(Fraction  x, Fraction  y){
	Fraction tmp = (x + y);
	cout << "Last line of add2" << endl;
	return tmp;
	cout << "End of add2" << endl;
}

void p1() {
	cout << "p1 Construtors" << endl;
	Fraction f1(1, 2), f2(2, 3), f3;
	cout << "p1f3 Assignment" << endl;
	f3 = add1(f1, f2);
}

void p2() {
	cout << "p2 Constructors" << endl;
	Fraction f1(1, 2), f2(2, 3), f3;
	cout << "p2f3 Assignment" << endl;
	f3 = add2(f1, f2);
}


//The main function presents the user the options and then loops through inputs as long as the user wants. 
int main(){
	cout << "p1" << endl;
	p1();
	cout << "p2" << endl;
	p2();
	
	/*Fraction f1;
	Fraction f2;
	int n = 0;
	int choice;
	char resp[10];
	cout << "\n\tWelcome to CSC404 Fraction Number System\n";
	while (true){
		cout << "\n\t0: Testing Big-Three\n\n";
		cout << "\t1: Testing Arithmetic Operators (+ - * / )\n\n";
		cout << "\t2: Testing Prefix/Postfix Increment/Decrement Operators\n\n";
		cout << "\t3: Testing Relational Operators\n\n";
		cout << "\t4: Testing Power Function\n\n";
		cout << "\t5: To Quit\n\n";
		cout << "\n\tYour choice: ";
		cin >> choice;
		if (choice < 0 || choice > 5){
			cout << "\n\t Invalid choice!\n\n";
			cout << "\n\tPlease pick one of the six choices.\n\n";
			continue;
		}
		else
			menu(choice, f1, f2, n);
		cout << "\n\n\tWant to continue for more tests? (Y/N) : ";
		cin >> resp;
		if (resp[0] == 'Y' || resp[0] == 'y')
			continue;
		else
			exit(1);
	}*/
	return 0;
}

//Switch case used to call the functions.
//Logical checks in the main function prevent inputs less than zero or greater than five. 
void menu(int choice, Fraction f1, Fraction f2, int n){
	switch (choice){
	case 0:
		bigThree(f1, f2);
		break;
	case 1:
		arithmetic(f1, f2);
		break;
	case 2:
		prePost(f1, f2);
		break;
	case 3:
		relational(f1, f2);
		break;
	case 4:
		power(f1, n);
		break;
	case 5:
		exit(1);
	default :
		break;
	}
}

//Uses the copy constructor and the overloaded assignment operator. 
Fraction bigThree(Fraction f1, Fraction f2){
	cout << "\n\n\tPlease enter the first fraction : ";
	cin >> f1;
	if (f1.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tPlease enter the second fraction : ";
	cin >> f2;
	if (f2.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\n\tTesting Big 3:\n\n";
	cout << "\tInside a block : \n\n";
	cout << "\tf1 = (" << f1 << ") and f2 = (" << f2 << ")\n\n";
	Fraction f3(f1);
	cout << "\tFraction f3(f1) : ==> f3 = (" << f3 << ")\n\n";
	cout << "\tAfter f3 = f2 : f1 = (" << f1 << "), f2 = (" << f2 << ")";
	f3 = f2;
	cout << ", f3 = (" << f3 << ")\n\n";
	f1 = f3;
	cout << "\tf1 = f3 : f1 = (" << f1 << ")\n\n";
	cout << "\tOutside the block : \n\n";
	cout << "\tf1 = (" << f1 << ")\n\n\n";
	return 0;
}

//Demonstrates the basic mathematical operations. 
Fraction arithmetic(Fraction f1, Fraction f2){
	cout << "\n\n\tPlease enter the first fraction : ";
	cin >> f1;
	if (f1.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tPlease enter the second fraction : ";
	cin >> f2;
	if (f2.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tTesting Arithmetic Operations : ";
	Fraction temp;
	temp = f1 + f2;
	cout << "\n\n\t(" << f1 << ") + (" << f2 << ") = " << temp;
	cout << "\n\n\t(" << f1 << ") - (" << f2 << ") = " << (f1 - f2);
	cout << "\n\n\t(" << f1 << ") * (" << f2 << ") = " << (f1 * f2);
	cout << "\n\n\t(" << f1 << ") / (" << f2 << ") = " << (f1 / f2);
	return 0;
}

//Demonstrates the incriment and decriment operators.
//Actual incriment and decriments on separate cout lines so they display correctly. 
Fraction prePost(Fraction f1, Fraction f2){
	cout << "\n\n\tPlease enter the first fraction : ";
	cin >> f1;
	if (f1.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tPlease enter the second fraction : ";
	cin >> f2;
	if (f2.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tTesting Increment/Decrement :";
	cout << "\n\n\t++(" << f1 << ") + (" << f2 << ") = (";
	cout << ++f1 + f2 << ")";
	cout << "\n\n\tf1 = (" << f1 << ") , f2 = (" << f2 << ")";
	cout << "\n\n\t(" << f1 << ") + (" << f2 << ")++ = (";
	cout << f1 + f2++ << ")";
	cout << "\n\n\tf1 = (" << f1 << ") , f2 = (" << f2 << ")";
	cout << "\n\n\t--(" << f1 << ") * (" << f2 << ") = (";
	cout << --f1 * f2 << ")";
	cout << "\n\n\tf1 = (" << f1 << ") , f2 = (" << f2 << ")";
	cout << "\n\n\t(" << f1 << ") * (" << f2 << ")-- = (";
	cout << f1 * f2-- << ")";
	cout << "\n\n\tf1 = (" << f1 << ") , f2 = (" << f2 << ")";
	return 0;
}

//If-Then statements used to demonstrate the relational operators.
Fraction relational(Fraction f1, Fraction f2){
	cout << "\n\n\tPlease enter the first fraction : ";
	cin >> f1;
	if (f1.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tPlease enter the second fraction : ";
	cin >> f2;
	if (f2.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	cout << "\n\n\tTesting Relational Operations :";
	cout << "\n\n\t(" << f1 << ") >  (" << f2 << ") is ";
	if (f1 > f2)
		cout << "true";
	else
		cout << "false";
	cout << "\n\n\t(" << f1 << ") >= (" << f2 << ") is ";
	if (f1 >= f2)
		cout << "true";
	else
		cout << "false";
	cout << "\n\n\t(" << f1 << ") <  (" << f2 << ") is ";
	if (f1 < f2)
		cout << "true";
	else
		cout << "false";
	cout << "\n\n\t(" << f1 << ") <= (" << f2 << ") is ";
	if (f1 <= f2)
		cout << "true";
	else
		cout << "false";
	cout << "\n\n\t(" << f1 << ") == (" << f2 << ") is ";
	if (f1 == f2)
		cout << "true";
	else
		cout << "false";
	cout << "\n\n\t(" << f1 << ") != (" << f2 << ") is ";
	if (f1 != f2)
		cout << "true";
	else
		cout << "false";
	return 0;
}

//Temporary Fraction object used to demonstrate the overloaded ^ operator. 
Fraction power(Fraction f1, int n){
	Fraction temp;
	cout << "\n\n\tPlease enter the first fraction : ";
	cin >> f1;
	if (f1.getDen() == 0){
		cout << "\n\n\tYou cannot divide by zero, it is undefined.";
		cout << "\n\n\tPlease enter the first fraction : ";
		cin >> f1;
	}
	temp = f1;
	cout << "\n\n\tPlease enter an integer for power : ";
	cin >> n;
	cout << "\n\n\tTesting Overload ^ :";
	cout << "\n\n\t(" << f1 << ")^(" << n << ") = (";
	cout << (f1 ^ n) << ")";
	cout << "\n\n\t(" << temp << ")^(" << -n << ") = (";
	cout << (temp ^ -n) << ")";
	return 0;
}
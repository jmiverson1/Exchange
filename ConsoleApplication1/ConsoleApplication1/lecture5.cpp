#include<iostream>
#include<string>
#include "lecture5.h"
#include "Numbers.h"



using namespace std;

void f1();

int times2(int x){
	int result = 2 * x;
	return result;
}

int &times(int x, int n){
	int *result = new int(x*n);
	return *result;
}

void printAge(const Person& P){ //By using a call-by-reference (&), you do not need to make a copy, but without the const, you could inadvertently overwrite
								//other values stored in memory.
	cout << P.getAge() << endl; //Cannot call age here by saying p.age because the value of age is private. We must use the public function, getAge().
								//The getAge() function has to set the age variable as a constant for this to work. 
}

int main(){

	Number n1;
	Number n2(200);
	Number n3(300);
	
	n1.display();
	n2.display();
	n3.display();

	n1 = n2;
	n1.display();

	for (int i = 0; i < 10; i++)
		f1();
	cout << endl;

	int n = 10;
	int x = 5;
	cout << times2(x) << "\n" << endl;
	cout << times(x, n) << "\n" << endl;

	Person John;
	John.setName("John");
	John.setAge(21);
	John.display();
	cout << "John's Name: " << John.getName() << "\n" << endl;
	{
	Person noname; //Using the constructor file and the default values. 
	noname.display(); //The brackets cause John Doe to be affected by Deconstructor immediately after everything in the brackets is completed. 
	}
	Person Jack("Jack", 31); //Using the constructor function in the header file.
	//If you want to use the default constructor, do not be tempted to say, Person Name();.
	//The compiler will think you are trying to call a function, Name(), that has no parameters.
	Person Tom(Jack); //Uses the copy compiler to create a copy of Jack, called Tom.
	Person Will(Tom); //Uses the copy compiler to create a copy of Tom, which is a copy of Jack, called Will.
	Jack.display();
	Tom.display();
	Tom.setName("Tom"); //Tom keeps Will's age, which is Jack's age, but now is named Tom.
	Tom.display();
	Will.display();
	
	printAge(Tom);
	printAge(Will);

	Jack = Tom;
	Jack.display();

	return 0;
}

void f1(){
	static int n = 0; //If this were not a static variable, but rather a dyanmic variable, this would return 10 1's when called by main. 
	n++;
	cout << n << endl;
}
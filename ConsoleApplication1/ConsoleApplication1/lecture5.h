#ifndef PERSON_H
#define PERSON_H
#endif
#include <string>
#include <iostream>

using namespace std;

class Person{
private:
	int age;
	string name; 
public:
	int getAge() const{ return age; }
	string getName() { return name; }
	void setAge(int age){ this->age = age; }
	void setName(string name){ this->name = name; }
	void display() {
		cout << "Name: " << name << " Age: " << age << endl;
	}

	//constructors
	Person() :name("John Doe"), age(18){
		cout << "Default Consturctor involved." << endl;
	}; //Default Constructor
	Person(string name, int age) :name(name), age(age){}; //Parameter Constructor
	Person(Person & other) :name(other.getName()), age(other.getAge()){
		cout << "Copy Constructor involved.";
	};

	~Person(){
		cout << name << " is dying..." << endl;
		//The Deconstructor will purge the objects (people) in reverse order.
		//The objects are stored in a stack, so are dealt with on a FIFO basis. 
	}

	//Overload Assignment Operator
	Person & operator=(Person & rhs){
		cout << "Overload Assignment Operator" << endl;
		if (this != &rhs){ //"this" is the pointer.
			name = rhs.getName();
			age = rhs.getAge();
		}
		return *this;
	}
};
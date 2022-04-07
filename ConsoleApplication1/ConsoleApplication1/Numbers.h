#ifndef NUMBER_H
#define NUMBER_H

class Number {
private:
	int *value;
public:
	int getValue() { return *value; }
	void setValue(int val) { *value = val; }
	Number() :value(new int(0)) {};
	Number(int n) :value(new int(n)){};

	void display(){
		cout << *value << endl;
	}
	
	~Number(){
		if (value) delete value;
		value = 0; //This destructor will cause an error because n1 = n2 has n1 point to the reference of n2, which has already been destroyed. 
	}

	Number &operator=(Number & rhs){
		if (this != &rhs){
			delete value;
			value = new int(rhs.getValue());
		}
		return *this; //By overloading "=" thiis allows the destrutor to work because 
	}
};

#endif
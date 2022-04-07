#include <iostream>
#include <string>

using namespace std;

void incriment(){
	static int value = 1;
	++value;
	cout << value << endl;

}

int main(){
	incriment();
	incriment();
	incriment();

	int x = 0;
	int n = 2;
	int m = n >> 10;
	cout << m << endl;
	cout << static_cast<bool>(!!n) << endl;
	cout << static_cast<bool>(!!x) << endl;

	string greeting = "Hello there!";
	cout << greeting + " Hey!" << endl;
	cout << greeting.c_str() << endl;
	char greeting1[6] = { 'H', 'e', 'l', 'l', 'o'};
	cout << greeting1 << endl;
}
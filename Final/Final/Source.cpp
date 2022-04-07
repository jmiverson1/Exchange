#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif
#include <string>
#include <iostream>

using namespace std;

int& main(){
	char cstr[6] = "apple";
	string quest;
	quest = cstr;
	cout << quest << endl;

	double* p1[10];
	double v1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int& a = *new int;
	a = 10;
	cout << a << endl;
	cout << ARRAY_SIZE(p1) << endl;
	cout << ARRAY_SIZE(*p1) << endl;
	cout << sizeof(p1) << endl;
	cout << sizeof(*p1) << endl;
	for (int i = 0; i < 10; i++){
		p1[i] = &v1[i];
		cout << *p1[i] << endl;
	}
 	cout << ARRAY_SIZE(p1) << endl;
	cout << ARRAY_SIZE(*p1) << endl;
	cout << sizeof(p1) << endl;
	cout << sizeof(*p1) << endl;
	return a;
}
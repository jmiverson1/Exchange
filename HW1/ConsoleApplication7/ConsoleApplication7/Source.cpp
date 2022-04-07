/************************************************************************************************/
/*   CSC309/404  Homework Assignment #1                                                         */
/*   Name :  Joshua Iverson                                                                     */
/*   Due Date :   April 19, 2014                                                                */
/*   Compiler : Miscrosoft Visual Studio 2013 C++               				                */
/*                                                                                              */
/************************************************************************************************/

/************************************************************************************************/
/*  (1) Determine the size (in number of bytes) of different data types on your host machine    */
/*  (2) Find out those constants defined in files : <cfloat> , <climits>                        */
/*  (3) display the addresses of the variables declared in the function.                        */
/*                                                                                              */
/************************************************************************************************/



#include <string>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iomanip>
using namespace std;
void greeting();
void p1();
void p2();  // do exactly what p1() will do, except using iomanip  instead of printf
string draw(int n, char c = '-');
void p222();
int main()
{
	greeting();
	p1();
	p2();
	return 0;
}

void greeting() {

	cout << "\n\tHello, my name is Josh . I am in CSC404 section 901.\n";  // replace ???? by your name
	// replace XXX by your course/section 

}

void p1() {
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  the following printf statements display the size of different numeric data types, pointers ,chars //
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("Size of different basic C++ data type in number of bytes\n\n");
	printf("size of int           = %d \n", sizeof (int));
	printf("size of long          = %d \n", sizeof (long));
	printf("size of short         = %d \n", sizeof (short));
	printf("size of unsigned int  = %d \n", sizeof (unsigned int));
	printf("size of char          = %d \n", sizeof (char));
	printf("size of wchar_t       = %d \n", sizeof (wchar_t));
	printf("size of bool          = %d \n", sizeof (bool));
	printf("size of float         = %d \n", sizeof (float));
	printf("size of double        = %d \n", sizeof (double));
	printf("size of long double   = %d \n", sizeof (long double));
	printf("size of int ptr       = %d \n", sizeof (int *));
	printf("size of double ptr    = %d \n", sizeof (double *));
	printf("size of char ptr      = %d \n", sizeof (char *));

	printf("====================================\n\n");

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// the following printf statements display some of the constants defined  in <cfloat> header file //
	////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("Some constants in cfloat header file\n\n");
	printf("FLT_DIG               = %d\n", FLT_DIG);
	printf("DBL_DIG               = %d\n", DBL_DIG);
	printf("LDBL_DIG              = %d\n", LDBL_DIG);
	printf("FLT_EPSILON           = %e\n", FLT_EPSILON);
	printf("DBL_EPSILON           = %e\n", DBL_EPSILON);
	printf("LDBL_EPSILON          = %e\n", LDBL_EPSILON);
	printf("FLT_MAX               = %e\n", FLT_MAX);
	printf("DBL_MAX               = %e\n", LDBL_MAX);
	printf("LDBL_MAX              = %e\n", LDBL_MAX);
	printf("FLT_MAX_10_EXP        = %d\n", FLT_MAX_10_EXP);
	printf("DBL_MAX_10_EXP        = %d\n", DBL_MAX_10_EXP);
	printf("LDBL_MAX_10_EXP       = %d\n", LDBL_MAX_10_EXP);
	printf("====================================\n\n");

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// the following printf statements display some of the constants defined  in <climits> header file//
	////////////////////////////////////////////////////////////////////////////////////////////////////




	printf("Some constants in climits header file\n\n");

	printf("CHAR_BIT              = %d \n", CHAR_BIT);
	printf("SCHAR_MAX             = %d \n", SCHAR_MAX);
	printf("SCHAR_MIN             = %d \n", SCHAR_MIN);
	printf("UCHAR_MAX             = %d \n", UCHAR_MAX);
	printf("CHAR_MIN              = %d \n", CHAR_MIN);
	printf("CHAR_MAX              = %d \n", CHAR_MAX);
	printf("SHRT_MIN              = %d \n", SHRT_MIN);
	printf("SHRT_MAX              = %d \n", SHRT_MAX);
	printf("USHRT_MAX             = %d \n", USHRT_MAX);
	printf("INT_MIN               = %d \n", INT_MIN);
	printf("INT_MAX               = %d \n", INT_MAX);
	printf("UINT_MAX              = %d ***#@!\n", UINT_MAX);
	printf("UINT_MAX              = %u \n", UINT_MAX);
	printf("LONG_MIN              = %d \n", LONG_MIN);
	printf("LONG_MAX              = %d \n", LONG_MAX);
	printf("ULONG_MAX             = %d ***#@! \n", ULONG_MAX);
	printf("ULONG_MAX             = %u \n", ULONG_MAX);
	printf("====================================\n\n");


	////////////////////////////////////////////////////////////////////////////////////////////////////
	// the following  statements display the addresses of variables                                   //
	////////////////////////////////////////////////////////////////////////////////////////////////////


	int n = 100;
	double d = 123.456;
	float f = 3.1415f;
	int *nptr;
	double *dptr;
	float *fptr;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char str[] = "hello world";
	char *cptr;



	printf("address of n          =  %p  \n", &n);
	printf("address of d          =  %p  \n", &d);
	printf("address of f          =  %p  \n", &f);
	printf("address of nptr       =  %p  \n", &nptr);
	printf("address of dptr       =  %p  \n", &dptr);
	printf("address of fptr       =  %p  \n", &fptr);
	printf("address of arr        =  %p  \n", arr);
	printf("address of str        =  %p  \n", str);
	printf("====================================\n\n");
	cptr = &str[10];
	nptr = &arr[9];
	printf("cptr = &str[10] ; cptr - str = %d  \n", (cptr - str));
	printf("nptr = &arr[9] ;  nptr - arr = %d  \n", (nptr - arr));
	printf("size of arr (in bytes)       = %d \n", sizeof(arr));
	printf("size of arr (in # of cells)  = %d\n", sizeof(arr) / sizeof(int));
	printf("size of str (in bytes)       = %d \n", sizeof(str));
	printf("strlen of str \"hello world\"  = %d \n", strlen(str));

	printf("====================================\n\n");


	//////////////////////////////////////////////////////////////////

	printf("\n\n\tMultiplication Table :\n\n");

	printf("%3s | ", "  *");

	for (int i = 1; i < 11; i++) printf("%4d", i);
	printf("\n%50s", draw(50).c_str());
	for (int i = 0; i < 10; i++){

		printf("\n%3d | ", i + 1);
		for (int j = 1; j < 11; j++) printf("%4d", (i + 1)*j);

	}
	printf("\n\n");
}


///////////////////////////////////////////////////////////////////////
//  string   function draw(int n , char c )   recursive version
//   returns a string object that repeats character c for n times
//   if n is <= 0 , then an empty string is returned
///////////////////////////////////////////////////////////////////////


string draw(int n, char c) {
	if (n <= 0) return "";
	return c + draw(n - 1, c);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//    p2() : do exactly what p1(0 is doing except using cout with iomanip instead of printf
/////////////////////////////////////////////////////////////////////////////////////////////////////


void p2() {
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  the following printf statements display the size of different numeric data types, pointers ,chars //
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Size of different basic C++ data type in number of bytes\n\n";
	cout << left << setw(24) << "size of int           =" << sizeof (int) << "\n";
	cout << left << setw(24) << "size of long          =" << sizeof (long) << "\n";
	cout << left << setw(24) << "size of short         =" << sizeof (short) << "\n";
	cout << left << setw(24) << "size of unsigned int  =" << sizeof (unsigned int) << "\n";
	cout << left << setw(24) << "size of char          =" << sizeof (char) << "\n";
	cout << left << setw(24) << "size of wchar_t       =" << sizeof (wchar_t) << "\n";
	cout << left << setw(24) << "size of bool          =" << sizeof (bool) << "\n";
	cout << left << setw(24) << "size of float         =" << sizeof (float) << "\n";
	cout << left << setw(24) << "size of double        =" << sizeof (double) << "\n";
	cout << left << setw(24) << "size of long double   =" << sizeof (long double) << "\n";
	cout << left << setw(24) << "size of int *         =" << sizeof (int *) << "\n";
	cout << left << setw(24) << "size of double *      =" << sizeof (double *) << "\n";
	cout << left << setw(24) << "size of char *        =" << sizeof (char *) << "\n";

	cout << "====================================\n\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// the following printf statements display some of the constants defined  in <cfloat> header file //
	////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Some constants in cfloat header file\n" << "\n";
	cout << left << setw(24) << "FLT_DIG               =" << FLT_DIG << "\n";
	cout << left << setw(24) << "DBL_DIG               =" << DBL_DIG << "\n";
	cout << left << setw(24) << "LDBL_DIG              =" << LDBL_DIG << "\n";
	cout << left << setw(24) << "FLT_EPSILON           =" << FLT_EPSILON << "\n";
	cout << left << setw(24) << "DBL_EPSILON           =" << DBL_EPSILON << "\n";
	cout << left << setw(24) << "LDBL_EPSILON          =" << LDBL_EPSILON << "\n";
	cout << left << setw(24) << "FLT_MAX               =" << FLT_MAX << "\n";
	cout << left << setw(24) << "DBL_MAX               =" << DBL_MAX << "\n";
	cout << left << setw(24) << "LDBL_MAX              =" << LDBL_MAX << "\n";
	cout << left << setw(24) << "FLT_MAX_10_EXP        =" << FLT_MAX_10_EXP << "\n";
	cout << left << setw(24) << "DBL_MAX_10_EXP        =" << DBL_MAX_10_EXP << "\n";
	cout << left << setw(24) << "LDBL_MAX_10_EXP       =" << LDBL_MAX_10_EXP << "\n";
	cout << "====================================\n\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// the following printf statements display some of the constants defined  in <climits> header file//
	////////////////////////////////////////////////////////////////////////////////////////////////////




	cout << "Some constants in climits header file\n\n";

	cout << left << setw(24) << "CHAR_BIT              =" << CHAR_BIT << "\n";
	cout << left << setw(24) << "SCHAR_MAX             =" << SCHAR_MAX << "\n";
	cout << left << setw(24) << "SCHAR_MIN             =" << SCHAR_MIN << "\n";
	cout << left << setw(24) << "UCHAR_MAX             =" << UCHAR_MAX << "\n";
	cout << left << setw(24) << "CHAR_MIN              =" << CHAR_MIN << "\n";
	cout << left << setw(24) << "CHAR_MAX              =" << CHAR_MAX << "\n";
	cout << left << setw(24) << "SHRT_MIN              =" << SHRT_MIN << "\n";
	cout << left << setw(24) << "SCHAR_MAX             =" << SHRT_MAX << "\n";
	cout << left << setw(24) << "USHRT_MAX             =" << USHRT_MAX << "\n";
	cout << left << setw(24) << "INT_MIN               =" << INT_MIN << "\n";
	cout << left << setw(24) << "INT_MAX               =" << INT_MAX << "\n";
	cout << left << setw(24) << "UINT_MAX              =" << (int)UINT_MAX << "***#@! \n";
	cout << left << setw(24) << "UINT_MAX              =" << UINT_MAX << "\n";
	cout << left << setw(24) << "LONG_MIN              =" << LONG_MIN << "\n";
	cout << left << setw(24) << "LONG_MAX              =" << LONG_MAX << "\n";
	cout << left << setw(24) << "ULONG_MAX             =" << (int)ULONG_MAX << "***#@! \n";
	cout << left << setw(24) << "ULONG_MAX             =" << ULONG_MAX << "\n";
	cout << "====================================\n\n";


	////////////////////////////////////////////////////////////////////////////////////////////////////
	// the following  statements display the addresses of variables                                   //
	////////////////////////////////////////////////////////////////////////////////////////////////////


	int n = 100;
	double d = 123.456;
	float f = 3.1415f;
	int *nptr;
	double *dptr;
	float *fptr;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char str[] = "hello world";
	char *cptr;



	cout << left << setw(24) << "address of n          = " << &n << "\n";
	cout << left << setw(24) << "address of d          = " << &d << "\n";
	cout << left << setw(24) << "address of f          = " << &f << "\n";
	cout << left << setw(24) << "address of nptr       = " << &nptr << "\n";
	cout << left << setw(24) << "address of dptr       = " << &dptr << "\n";
	cout << left << setw(24) << "address of fptr       = " << &fptr << "\n";
	cout << left << setw(24) << "address of arr        = " << &arr << "\n";
	cout << left << setw(24) << "address of str        = " << &str << "\n";
	cout << "====================================\n\n";
	cptr = &str[10];
	nptr = &arr[9];
	cout << left << setw(31) << "cptr = &str[10] ; cptr - str =" << (cptr - str) << "\n";
	cout << left << setw(31) << "nptr = &arr[9] ;  nptr - arr =" << (nptr - arr) << "\n";
	cout << left << setw(31) << "size of arr (in bytes)       =" << sizeof(arr) << "\n";
	cout << left << setw(31) << "size of arr (in # of cells)  =" << sizeof(arr) / sizeof(int) << "\n";
	cout << left << setw(31) << "size of str (in bytes)       =" << sizeof(str) << "\n";
	cout << left << setw(31) << "strlen of str \"hello world\"  =" << strlen(str) << "\n";

	cout << "====================================\n\n";


	//////////////////////////////////////////////////////////////////

	cout << "\n\n\tMultiplication Table :\n\n";

	cout << setw(6) << "  * | ";

	for (int i = 1; i < 11; i++) cout << right << setw(4) << i;
	cout << "\n" << draw(50).c_str();
	for (int i = 0; i < 10; i++){

		cout << "\n" << setw(3) << i + 1 << setw(3) << " | ";
		for (int j = 1; j < 11; j++) cout << setw(4) << (i + 1)*j;

	}
	cout << "\n\n";
}
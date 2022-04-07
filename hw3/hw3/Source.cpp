/*/************************************************************************************************/
/*   CSC309/404  Homework Assignment #3                                                           */
/*   Name :  Joshua Iverson                                                                       */
/*   Due Date :   May 3, 2014                                                                     */
/*   Compiler : Miscrosoft Visual Studio 2013 C++												  */ 
/**************************************************************************************************/ 

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <math.h>

using namespace std;

typedef int* IntPtr;
void print(int score[], int n, char resp[10]);
void sort(int score[], int n, char resp[10]);
void swap(int score[], int j, int k);
void createUnique(int score[], int n, int unique[], int count[], char resp[10]);
void summary(int unique[], int n, double& avg, double& var, double& stdev, double& med, int score[]);

//The main function, which calls the functions that generate each of the four reports. 

int main(){
	
	char resp[10];
	char repeat[10];
	int n;
	double avg = 0.0, var = 0.0, stdev = 0.0, med = 0.0;
	int max = 0, min = 0;

//Obtains the size of the desired array from the user. 

	while (true){
		cout << "\nPlease enter a positive integer less than or equal to 500: ";
		cin >> n;
		if (n < 0 || n > 500){
			cout << "\nYour entry must be positive and less than or equal to 500!";
			continue;
		}

		IntPtr score;
		score = new int [n];		

//Gives the user the option to see each of the four reports. 

		cout << "Do you want to see the random numbers being generated? (Y/N) ";
		cin >> resp;

		print(score, n, resp);
		
		cout << "\nDo you want to see the array sorted? (Y/N) ";
		cin >> resp;

		sort(score, n, resp);

		int unique[500];
		int count[500];
		
		cout << "\nDo you want to see a histogram of the array? (Y/N) ";
		cin >> resp;

		createUnique(score, n, unique, count, resp);

//For the last report, whether the user wants to see it or not, he/she is prompted to run it again.

		cout << "\nDo you want to see the statistics of the array? (Y/N) ";
		cin >> resp;

		if (resp[0] == 'Y' || resp[0] == 'y'){
			summary(unique, n, avg, var, stdev, med, score);
			cout << "Do you want to run another test? (Y/N) ";
			cin >> repeat;
			if (repeat[0] == 'Y' || repeat[0] == 'y')
				continue;
			else
				break;
		}
		else
			cout << "Do you want to run another test? (Y/N) ";
			cin >> repeat;
			if (repeat[0] == 'Y' || repeat[0] == 'y')
				continue;
			else
				break;
	}

}

//The first function generates the array of size determined by the user with values of 1 to 100. 

void print(int score[], int n, char resp[10])
{	
	srand((unsigned)time(NULL));
	
	if (resp[0] == 'Y' || resp[0] == 'y'){
		for (int i = 0; i < n; i++){
			score[i] = rand() % 100 + 1;
			if ((i + 1) % 5 == 0)
				cout << setw(3) << score[i] << "\n";
			else
				cout << setw(3) << score[i] << " ";
		}
	}
	else{
		cout << "\nNo score being generated.\n\n";
		for (int i = 0; i < n; i++)
			score[i] = rand() % 100 + 1;

	}
}

//This function sorts the array by switch each subsequent value in the array until the array is sorted lowest to highest. 

void sort(int score[], int n, char resp[10]){
	for (int j = 0; j < (n - 1); j++){
		for (int k = (j + 1); k < n; k++){
			if (score[k] < score[j]){
				swap(score, j, k);
			}
		}
	}
	if (resp[0] == 'Y' || resp[0] == 'y'){
		for (int i = 0; i < n; i++){
			if ((i + 1) % 5 == 0)
				cout << setw(3) << score[i] << "\n";
			else
				cout << setw(3) << score[i] << " ";
		}
	}
	else 
		cout << "\nNo sort being generated.\n\n";
}

//This is the function that is called by the sort function to swap values if they are not originally in the correct order. 

void swap(int score[], int j, int k){
	int temp;
	temp = score[k];
	score[k] = score[j];
	score[j] = temp;
}

//This function creates a unique array by assigning a null value to non-unique values. 
//With the unique array, the sum of non-unique values is determined by comparing the original sorted array to the new unique array. 
//The count array that counted the non-unque values and assigned a 1 to unique values prints an asterisk for each of those numbers. 
//By printing non-zero values in the unique array and the count array with asterisks in place of the numbers, you get a histogram. 


void createUnique(int score[], int n, int unique[], int count[], char resp[10]){
	int uniquesum = 1;
	char ast = '*';
	
	cout << "\n";

	for (int i = 0; i < n; i++){
		if (score[i] != score[i + 1])
			unique[i] = score[i];
		else
			unique[i] = NULL;
	}

	for (int i = 0; i < n; i++){
		if (score[i] != unique[i])
			uniquesum +=1;
		else{
			count[i] = uniquesum;
			uniquesum = 1;
		}
	}

	if (resp[0] == 'Y' || resp[0] == 'y'){
		for (int i = 0; i < n; i++){
			if (unique[i] == 0)
				;
			else{
				cout << right << setw(3) << unique[i] << ": ";
				for (int f = 1; f <= count[i]; f++)
					cout << left << "*";
				cout << "\n";
			}
		}
	}
	else 
		cout << "\nNo histogram being generated.\n\n";
	
}

//The summary function just determines the values required by the assignment. 
//Finally, the dynamic array is deleted to free up memory. 

void summary(int unique[], int n, double& avg, double& var, double& stdev, double& med, int score[]){
	double sum = 0.0;
	int min = 0;
	cout << "\n\n\n\tSummary:\n\n";
	cout << setw(30) << "\tTotal Number of Data : " << left << setw(10) << n << "\n" << endl;
	cout << setw(30) << "\tMaximum : " << left << setw(10) << score[n - 1] << "\n" << endl;
	cout << setw(30) << "\tMinimum : " << left << setw(10) << score[0] << "\n" << endl;
	for (int i = 0; i < n; i++)
		sum = sum + score[i];
	cout << setw(30) << "\tAverage : " << left << setw(10) << setprecision(4) << (double)(sum / n) << "\n" << endl;
	for (int i = 0; i < n; i++)
		var = var + pow(score[i] - (sum / n), 2) / n;
	cout << setw(30) << "\tVariance : " << left << setw(10) << setprecision(5) << var << "\n" << endl;
	stdev = sqrt(var);
	cout << setw(30) << "\tStandard Deviation : " << left << setw(10) << setprecision(4) << stdev << "\n" << endl;
	if (n % 2 == 0)
		cout << setw(30) << "\tMedian : " << left << setw(10) << setprecision(4) << score[n / 2] << "\n" << endl;
	else 
		cout << setw(30) << "\tMedian : " << left << setw(10) << setprecision(4) << 0.5*(score[n / 2] + score[n/2 - 1]) << "\n" << endl;
	
	delete[] score;

	return;
}

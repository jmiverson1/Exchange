/*/************************************************************************************************/
/*   CSC309/404  Homework Assignment #4                                                           */
/*   Name :  Joshua Iverson                                                                       */
/*   Due Date :   May 17, 2014                                                                    */
/*   Compiler : Miscrosoft Visual Studio 2013 C++												  */
/**************************************************************************************************/

#include <iostream>
#include <string>
#include "Dice.h"
#include <iomanip>

using namespace std;

int rollAll(Dice cup[], int n, int sum);

double getBet(double& bet, double balance);

double getPayoff(int total, double bet, double& status);

void summary(double status, double& bet, double payoff, double balance);

void gameSummary(double stake, double balance);

//The menu function gives the instructions of the game, confirms the player wants to play and that they are over 21. 
void menu() {
	char resp[10];
	int age = 0;
	cout << "\n\tWelcome to \"Simplified\" Craps Game\n\n";
	cout << "***Warning : You must be 21 years or older in order to play.\n\n\n";
	cout << "To begin the game, enter the stake you will be betting with.\n";
	cout << "To play a round, you must enter a bet from your stake.\n";
	cout << "Once your bet is entered, two dice will be rolled.\n";
	cout << "If the sum of the two dice is 2, 3, 4, 10, 11, or 12, you win.\n";
	cout << "The payouts are made according to the following payoff table:\n\n";
	cout << setw(20) << left << "\tTotal" << right << "Payoff" << endl;
	cout << setw(20) << left << "\t=====" << right << "======\n\n";
	cout << setw(20) << left << "\t2" << right << "3 to 1\n";
	cout << setw(20) << left << "\t3 or 4" << right << "1 to 1 (even)\n";
	cout << setw(20) << left << "\t10 or 11" << right << "2 to 1\n";
	cout << setw(20) << left << "\t12" << right << "5 to 1\n\n\n\n";
	cout << "Are you ready to play (Y/N) ";
	cin >> resp;
	if (resp[0] == 'Y' || resp[0] == 'y'){
		cout << "\nPlease enter your age: ";
		cin >> age;
		if (age < 21){
			cout << "\nSorry, your are not old enough to play.\n\n";
			exit(1);
		}
		else
			cout << "\nLet's start to play...\n\n";
	}
	else{
		cout << "\nOkay, goodbye.\n\n";
		exit(1);
	}
}

//The main function initializes the srand used in the roll function in the header file.
//The cup array is initialized with two Dice, win and lose, in the first two positions of the array.
//The arguments in the main function are all wrapped in a while loop that continues when the balance is greater than zero.
int main(){
	srand((unsigned)time(NULL));
	char betResp[10];
	double payoff = 0;
	double bet = 0;
	double balance = 0;
	double stake = 0;
	static Dice cup[2];
	Dice win(1);
	Dice lose(2);
	cup[0] = win;
	cup[1] = lose;
	int total = 0;
	double status = 0;
	int sum = 0;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	menu();

	cout << "Please enter your stake: ";
	cin >> stake;
	balance = stake;

	while (balance > 0){
		bet = getBet(bet, balance);
		balance -= bet;
		if (bet == 0){
			cout << "If you do not bet, you must leave the table. Are you sure? (Y/N) ";
			cin >> betResp;
			if (betResp[0] == 'Y' || betResp[0] == 'y')
				exit(1);
			else
				continue;
		}
		total = rollAll(cup, 2, sum);
		cout << "You rolled a " << total << " (" << cup[0].getFace() << " " << cup[1].getFace() << ")\n" << endl;
		cout << "Your bet was $" << setprecision(2) << bet << endl;
		payoff = getPayoff(total, bet, status);
		balance += payoff;
		summary(status, bet, payoff, balance);
		cout << "\n\nDo you want to continue? (Y/N) ";
		cin >> betResp;
		if (betResp[0] == 'Y' || betResp[0] == 'y')
			continue;
		else{
			gameSummary(stake, balance);
			exit(1);
		}
		return 0;
	}

}

//The getBet function retrieves the bet from the user and confirms it is less than the user's balance. 
double getBet(double& bet, double balance){
	cout << "\n\tPlease enter your bet: ";
	cin >> bet;
	if (bet > balance){
		cout << "You cannot bet more than you have.\n";
		getBet(bet, balance);
	}
	return bet;
}

//This function rolls both dice and returns the results of the rolls as the sum variable. 
int rollAll(Dice cup[], int n, int sum){
	for (int i = 0; i < n; i++){
		cup[i].roll();
		sum += cup[i].getFace();
	}
	return sum;
}

//This is the fucntion that returns the status variable as the amount won or if lost a zero balance.
//The main function takes the amount that is returned by this function and sets it equal to payoff. 
//The main function then adds it to the balance after the bet was removed from the balance earlier in the main function. 
double getPayoff(int total, double bet, double& status){
	switch (total)
	{
	case 2:
		status = bet * 3;
		break;
	case 3:
	case 4:
		status = bet;
		break;
	case 10:
	case 11:
		status = bet * 2;
		break;
	case 12:
		status = bet * 5;
		break;
	default:
		status = 0;
	}
	return status;
}

//The summary function uses an if, then statement to give the outcome of the roll, the status based on the roll, and the user's new balance. 
void summary(double status, double& bet, double payoff, double balance){
	if (payoff > bet){
		cout << "You win! The payoff is $" << setprecision(2) << status << endl;
		cout << "Your current balance is $" << setprecision(2) << balance << endl;
	}
	else if (payoff == bet){
		cout << "You pushed. The payoff is $" << setprecision(2) << status << endl;
		cout << "Your current balance is $" << setprecision(2) << balance << endl;
	}
	else{
		cout << "You lose." << endl;
		cout << "Your current balance is $" << setprecision(2) << balance << endl;
	}
}

//This function comapares the stake variable as entered by the user at the beginning of the main function to the current balance. 
//Whether the two variables are greater than, equal to, or less than each other will determine the output. 
void gameSummary(double stake, double balance){
	cout << "\nYou started with $" << setprecision(2) << stake << ", now your balance is $" << setprecision(2) << balance << endl;
	if (stake > balance)
		cout << "\nYou lost $" << setprecision(2) << fabs(balance - stake) << ".\n\n";
	else if (stake == balance)
		cout << "\nYou pushed!\n\n" << endl;
	else{
		cout << "\nYou won $" << setprecision(2) << balance - stake << "!\n";
		cout << "\n***Remember to report your gambling gains to the IRS\n while filing your 2014 tax return.\n\n";
	}
}
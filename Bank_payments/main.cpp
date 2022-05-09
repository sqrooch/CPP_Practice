#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "This algorithm accepts from the user a cash deposit in euros and annual percentage,\n\
and then outputs the amount of monthly bank payments." << endl;

	float deposit, percent;
	string inputDeposit, inputPercent;

	while (true) // The loop checks the validity of the user input type.
	{
		cout << endl << "Enter your preferred deposit amount (in EUR): ";
		cin >> inputDeposit;

		cout << "Enter your preferred interest rate: ";
		cin >> inputPercent;

		try
		{
			deposit = stof(inputDeposit);
			percent = stof(inputPercent);
		}
		catch (invalid_argument)
		{
			cout << endl << "You can only enter numbers." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}

		if (deposit < 0 || percent <= 0 || percent > 30)
		{
			cout << endl << "!!!You have entered incorrect data!!!" << endl;
			cout << "The deposit must be greater than zero, and the interest percent must be in range from 0.01 to 30." << endl;
			continue;
		}

		break;
	}

	cout << endl << "Your deposit is: " << deposit << " EUR" << endl;
	cout << "Your interest rate is: " << percent << " %" << endl;
	cout << "Your monthly payments will be: " << round(deposit * percent / 12) / 100 << " EUR" << endl;
	return 0;
}
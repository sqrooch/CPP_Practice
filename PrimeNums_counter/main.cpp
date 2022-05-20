/*
  This module uses the "Sieve of Eratosthenes" algorithm to calculate and display all prime numbers
  that are in a series of natural numbers in the range from 1 to the user entered.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int primesCounter = 0;
	int n;
	string input_n;

	do
	{
		system("cls");

		cout << "Enter a natural number here: ";
		cin >> input_n;

		try
		{
			n = stoi(input_n);
		}
		catch (invalid_argument)
		{
			continue;
		}
	} while (n <= 0);
	
	// We must remember that the series of primes starts with "2".
	for (n; n > 1; n--) 
	{
		for (int i = (n - 1); i > 1; i--)
		{
			if (n % i == 0)
			{
				primesCounter--;
				break;
			}
		}
		primesCounter++;
	}

	cout << "There are " << primesCounter << " prime numbers in the proposed series of numbers." << endl;
	return 0;
}
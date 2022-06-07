/*
  This module uses the "Sieve of Eratosthenes" algorithm to calculate and display all prime numbers
  that are in a series of natural numbers in the range from 1 to the user entered.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int primes_counter = 0;
	int natural;
	string input_natural;

	do
	{
		system("cls");

		cout << "Enter a natural number here: ";
		cin >> input_natural;

		try
		{
			natural = stoi(input_natural);
		}
		catch (invalid_argument)
		{
			continue;
		}
	} while (natural <= 0);
	

	bool* sieve = new bool[natural+1];

	for (int i = 2; i <= natural; i++)
	{
		if (sieve[i])
		{
			primes_counter++;
			cout << i << "\t";
			for (int j = i * i; j <= natural; j += i)
			{
				if (j % i == 0)
				{
					sieve[j] = false;
				}
			}
		}
	}
	cout << endl;
	cout << "\nThere are " << primes_counter << " prime numbers in the proposed series of numbers.\n\n";

	delete[] sieve;
	sieve = nullptr;
	return 0;
}
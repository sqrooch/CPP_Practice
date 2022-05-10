// This algorithm counts the number of primes in the series of natural numbers in range from "1" to a number entered by user.

#include <iostream>
using namespace std;

int main()
{
	int counter = 0;

	unsigned int n;
	cout << "Enter a natural number here: ";
	cin >> n;

	// We must remember that the series of primes starts with "2".
	// let's try the usual linear enumeration.
	for (n; n > 1; n--) 
	{
		for (int i = (n - 1); i > 1; i--)
		{
			if (n % i == 0)
			{
				counter--;
				break;
			}
		}
		counter++;
	}

	cout << "There are " << counter << " prime numbers in the proposed series of numbers." << endl;
	return 0;
}
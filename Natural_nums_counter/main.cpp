//This algorithm counts the number of primes in a row of natural numbers.

#include <iostream>
using namespace std;

int main()
{
	int counter = 0;

	unsigned int n;
	cout << "Enter a natural number here: ";
	cin >> n;


	for (n; n > 1; n--) // 1 is not a prime number. The prime numbers row starts with 2.
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
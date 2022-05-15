/*
Brute force algorithm. It tests a number for inclusion in the category of prime numbers.
*/

# include <iostream>
# include <stdlib.h>

bool primeNumberTest(int n);

int main()
{
	using namespace std;
	cout << boolalpha;

	int inputNum = 1;
	while (inputNum < 2)
	{
		system("cls");
		cout << "Enter an integer >= 2: ";
		cin >> inputNum;
	}

	cout << "Is the number " << inputNum << " prime? - " << primeNumberTest(inputNum) << ".\n";

	return 0;
}

bool primeNumberTest(int n)
{
	bool isPrime = true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}
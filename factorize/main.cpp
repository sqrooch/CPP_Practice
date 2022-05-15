/*
The algorithm decomposes the number into factors.
*/

# include <iostream>

void factorize(int n);

int main()
{
	factorize(105);
	return 0;
}

void factorize(int n)
{
	using namespace std;

	int divider = 2;
	while ((n != 1) && (n != -1))
	{
		if (n % divider == 0)
		{
			cout << divider << "  ";
			n /= divider;
		}
		else
		{
			divider++;
		}
	}
}
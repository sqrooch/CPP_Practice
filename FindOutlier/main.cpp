/*
The function takes an array (which will be at least 3 long, but can be very large) containing integers.
The array either consists entirely of odd integers, or consists entirely of even integers, with the exception of one integer N.
The function returns this "outlier" N.

Examples:
{2, 4, 0, 100, 4, 11, 2602, 36}
Should return: 11

{160, 3, 1719, 19, 11, 13, -21}
Should return: 160
*/

# include <iostream>
# include <vector>

using namespace std;

int FindOutlier(vector<int> arr);

int main()
{
	vector<int> array = { 2, 4, 0, 100, 4, 11, 2602, 36 };
	cout << FindOutlier(array) << endl;

	array = { 160, 3, 1719, 19, 11, 13, -21 };
	cout << FindOutlier(array) << endl;

	array = { 2, 3, 4 };
	cout << FindOutlier(array) << endl;

	array = { 1, 2, 3 };
	cout << FindOutlier(array) << endl;

	array = { 4, 1, 3, 5, 9 };
	cout << FindOutlier(array) << endl;

	return 0;
}

// My solution:
int FindOutlier(vector<int> arr)
{
	int odd{}, oddCounter{}, even{}, evenCounter{};

	for (auto el : arr)
	{
		el % 2 == 0 ? (evenCounter++, even = el) : (oddCounter++, odd = el);
	}

	return (evenCounter > 1) ? odd : even;
}
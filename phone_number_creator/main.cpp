/*
An algorithm takes an array of 10 integers (from 0 to 9)
And returns a string of these numbers as a phone number in the format, shown in the example below.

Example:
createPhoneNumber(int array[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // will return "(123) 456-7890"
There is a space after the closing bracket!
*/

#include <iostream>
#include <string>

using namespace std;

string createPhoneNumber(const int arr[10]);

int main()
{
	const int inputNumbers[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << createPhoneNumber(inputNumbers) << endl;
}

// My solution:
/*
string createPhoneNumber(const int arr[10])
{
	string phoneFormat = "(xxx) xxx-xxxx";

	for (int i = 0, j = 0; i < phoneFormat.size(); i++)
	{
		if (phoneFormat[i] == 'x')
		{
			phoneFormat[i] = to_string(arr[j++])[0];
		}
	}
	return phoneFormat;
}
*/


// Best solution:
string createPhoneNumber(const int arr[10]) {
	char buf[15];
	snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
	return buf;
}
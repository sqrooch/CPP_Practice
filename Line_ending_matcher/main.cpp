/*
The algorithm returns "true" if the first argument passed(a string) ends with the second argument(also a string).
Otherwise, it returns "false". If the second string is empty (""), then it returns "true".

Examples:
solution("abc", "bc") // returns true
solution("abc", "d") // returns false
solution("abc", "") // returns true
*/

#include <iostream>
#include <string>

using namespace std;

bool line_ending_matcher(string const& str, string const& ending);

int main()
{
	cout << line_ending_matcher("abc", "bc") << endl;
	cout << line_ending_matcher("abc", "d") << endl;
	cout << line_ending_matcher("abcde", "cde") << endl;
	cout << line_ending_matcher("abcde", "abc") << endl;
	cout << line_ending_matcher("abc", "") << endl;
	cout << line_ending_matcher("abc", "abcabc") << endl;
	return 0;
}

// My solution.
/*
bool line_ending_matcher(string const& str, string const& ending)
{
	cout << boolalpha;

	if (ending.empty())
	{
		return true;
	}
	else if (str.length() < ending.length())
	{
		return false;
	}

	for (int i = ending.length() - 1; i >= 0; i--)
	{
		if (str[i + str.length() - ending.length()] != ending[i])
		{
			return false;
		}
	}
	return true;
}
*/


// Best solution.
bool line_ending_matcher(string const& str, string const& ending)
{
	cout << boolalpha;
	return str.size() >= ending.size() && str.compare(str.size() - ending.size(), std::string::npos, ending) == 0;
}
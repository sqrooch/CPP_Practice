/*
The function takes a string and return a new string with all vowels removed.
Example: The string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!"
WARNING: In this algorithm "Y" isn't considered a vowel.
*/

# include <iostream>
# include <string>
# include <regex>

using namespace std;

string disemvowel(string str);

int main()
{
    string inputStr = "This website is for losers LOL!";
    cout << disemvowel(inputStr) << endl;

    return 0;
}

// My solution:
/*
string disemvowel(string str)
{
    string vowels = "AaEeIiOoUu";

    for (int i = 0; i < str.length(); i++)
    {
        if (vowels.find(str[i], 0) != string::npos)
        {
            str.erase(i--, 1);
        }
    }
    return str;
}
*/


// Alternative solution:
/*
string disemvowel(string str)
{
    for (auto letter : "AEIOUaeiou")
    {
        str.erase(remove(str.begin(), str.end(), letter), str.end());
    }

    return str;
}
*/


// The Best solution:
string disemvowel(string str)
{
    regex vowels("[aeiouAEIOU]");
    return regex_replace(str, vowels, "");
}
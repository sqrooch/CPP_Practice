/*
The rgb method accepts RGB decimal values and returns their hexadecimal representations.
Valid decimal values for RGB: 0-255. Any values outside this range are rounded up to the nearest valid value.

Note: The result is always returned as 6 characters, reduction will not work.
*/

#include <iostream>
#include <string>

using namespace std;

class RGBToHex
{
public:
	static string rgb(int r, int g, int b)
	{
		string hex_dict = "0123456789ABCDEF";
		string hex = "";
		for (int arg : {r, g, b})
		{
			arg > 255 ? arg = 255 : arg;
			arg < 0 ? arg = 0 : arg;
			hex.push_back(hex_dict[arg / 16]);
			hex.push_back(hex_dict[arg % 16]);
		}

		return hex;
	};
};


int main()
{
	cout << RGBToHex::rgb(255, 255, 255) << endl;
	cout << RGBToHex::rgb(255, 255, 300) << endl;
	cout << RGBToHex::rgb(0, 0, 0) << endl;
	cout << RGBToHex::rgb(148, 0, 211) << endl;
	cout << RGBToHex::rgb(1, 2, 3) << endl;
	cout << RGBToHex::rgb(254, 253, 252) << endl;
	cout << RGBToHex::rgb(-20, 275, 125) << endl;

	return 0;
}
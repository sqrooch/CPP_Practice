#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int Task1() // Task 1 function.
{
	cout << "You were given two integers." << endl;
	cout << "The Console should returns \"1\" if the first number is greater second," << endl;
	cout << "returns \"2\", if the second is greater than the first or returns \"0\" if they are equal." << endl << endl;

	int firstVal, secondVal, result = 0;
	string firstInput, secondInput;

	while (true) // The loop checks the validity of the user input type.
	{
		cout << "Enter first number here: ";
		cin >> firstInput;

		cout << "Enter second number here: ";
		cin >> secondInput;

		try
		{
			firstVal = stoi(firstInput);
			secondVal = stoi(secondInput);
		}
		catch (invalid_argument)
		{
			cout << endl << "You can only enter numbers." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}
		break;
	}

	// Logic for the task 1.
	if (firstVal > secondVal)
	{
		result = 1;
	}
	else if (firstVal < secondVal)
	{
		result = 2;
	}

	cout << endl << "The answer is " << result << '.' << endl;
	return result;
}

int Task2() // Task 2 function.
{
	cout << "Three integers are given." << endl;
	cout << "Find the largest number which is not less of any other." << endl;
	cout << "The console should returns exactly one the largest number." << endl << endl;

	int firstVal, secondVal, thirdVal, maxVal;
	string firstInput, secondInput, thirdInput;

	while (true) // The loop checks the validity of the user input type.
	{
		cout << "Enter first number here: ";
		cin >> firstInput;

		cout << "Enter second number here: ";
		cin >> secondInput;

		cout << "Enter third number here: ";
		cin >> thirdInput;

		try
		{
			firstVal = stoi(firstInput);
			secondVal = stoi(secondInput);
			thirdVal = stoi(thirdInput);
		}
		catch (invalid_argument)
		{
			cout << endl << "You can only enter numbers." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}
		break;
	}

	// Max number finding algorithm.
	maxVal = thirdVal; // By default, the branch returns third number value.
	if (firstVal >= secondVal)
	{
		if (firstVal >= thirdVal)
		{
			maxVal = firstVal;
		}
	}
	else
	{
		if (secondVal >= thirdVal)
		{
			maxVal = secondVal;
		}
	}

	// An alternative solution with sorting vectors.
	/*
	vector<int> valluesArr = { firstVal, secondVal, thirdVal };
	sort(valluesArr.begin(), valluesArr.end());
	reverse(valluesArr.begin(), valluesArr.end());
	maxVal = valluesArr[0];
	*/

	cout << endl << "The largest number is " << maxVal << '.' << endl;
	return maxVal;
}

string Task3() // Function that performs task 3.
{
	cout << "You were given three natural numbers A, B, C." << endl;
	cout << "If a the triangle with these side lenghts is exists, must be returned \"YES\" word, otherwise \"NO\"." << endl << endl;

	int a, b, c;
	string aInput, bInput, cInput, isTriangle;

	while (true) // A loop that checks the user input against the type <int> and correct length of the sides of a triangle.
	{
		cout << "Enter first side length here: ";
		cin >> aInput;

		cout << "Enter second side length here: ";
		cin >> bInput;

		cout << "Enter third side length here: ";
		cin >> cInput;

		try
		{
			a = stoi(aInput);
			b = stoi(bInput);
			c = stoi(cInput);
		}
		catch (invalid_argument)
		{
			cout << endl << "You can only enter numbers." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}

		if (a > 0 && b > 0 && c > 0)
		{
			break;
		}
		else
		{
			cout << endl << "You can only enter positive numbers greater than zero." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}
	}

	// Triangle Validity Algorithm.
	if ((a < (b + c)) && (b < (a + c)) && (c < (a + b)))
	{
		isTriangle = "YES";
	}
	else
	{
		isTriangle = "NO";
	}

	cout << endl << "Is it triangle? - " << isTriangle << '.' << endl;
	return isTriangle;
}

int Task4() // Function that performs task 4.
{
	cout << "The length of the Moscow Ring Highway - 109 kilometers." << endl;
	cout << "Rider Vadim starts from the zero kilometer of the Moscow Ring Road and moves at a speed of V kilometers per hour." << endl;
	cout << "At what point will he stops after T hours?" << endl;
	cout << "The program receives integers V and T as input." << endl;
	cout << "If V > 0, then Vadim is moving in a positive direction along the Moscow Ring Road, if the value of V < 0, then it is negative." << endl;
	cout << "-1000 <= V <= 1000, 0 <= T <= 1000.\nOutput mark must be in range from 0 to 108" << endl << endl;

	const int ROAD_LENGHT = 109;
	int v, t, finalMark = 0;
	string vInput, tInput;

	while (true) // A loop that checks the user for the correctness of data input and its compliance with the conditions of the task.
	{
		cout << "Enter the rider's speed: ";
		cin >> vInput;

		cout << "Enter the ride time (in hours): ";
		cin >> tInput;

		try
		{
			v = stoi(vInput);
			t = stoi(tInput);
		}
		catch (invalid_argument)
		{
			cout << endl << "You can only enter numbers." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}

		if ((t >= 0 && t <= 1000) && (v >= -1000 && v <= 1000))
		{
			break;
		}
		else
		{
			cout << endl << "Speed and time of the ride must be in range -1000 <= V <= 1000, 0 <= T <= 1000." << endl;
			cout << "Try again and be careful this time." << endl << endl;
			continue;
		}
	}

	// Algorithm for finding the coordinates of the end point on the ring road.
	finalMark = v * t % ROAD_LENGHT;
	if (finalMark < 0 && finalMark > -ROAD_LENGHT)
	{
		finalMark += ROAD_LENGHT;
	}

	cout << endl << "Final mark of the ride is " << finalMark << " km." << endl;
	return finalMark;
}

int main() // Main function. Program entry point.
{
	cout << "Hey everyone! This is my first experience in C++.\nThere are 4 tasks in it, numbered from 1 to 4.";
	char exerciseNum = '0';
	char moreSolutions = 'y';

	// Main menu of the user interface.
	// Here the user enters the number of the task he wants to check.
	// In case of incorrect input, additional attempts are offered.
	while (moreSolutions == 'y')
	{
		cout << endl << "If you want to see The Solution, please enter the task number here: ";
		cin >> exerciseNum;
		cout << endl << string(100, '*');
		switch (exerciseNum)
		{
		case '1':
			cout << endl << "You can see exercise 1 down there." << endl << endl;
			Task1();
			break;
		case '2':
			cout << endl << "You can see exercise 2 down there." << endl << endl;
			Task2();
			break;
		case '3':
			cout << endl << "You can see exercise 3 down there." << endl << endl;
			Task3();
			break;
		case '4':
			cout << endl << "You can see exercise 4 down there." << endl << endl;
			Task4();
			break;
		default:
			cout << endl << "No such task number exists. Try again?" << endl << "Enter \'y\' for yes or any symbol for quit: ";
			cin >> moreSolutions;
			if (moreSolutions == 'y')
			{
				continue;
			}
		}

		// In this block, the user is prompted to go to the next task, or repeat the previous one.
		if (moreSolutions == 'y')
		{
			cout << endl << "Want to see more solutions?" << endl << "Enter \'y\' for yes or any symbol for quit: ";
			cin >> moreSolutions;
		}
	}
	cout << endl << endl << endl << "Was glad to see you. Good bye!!!" << endl << endl << endl;
	return 0;
}
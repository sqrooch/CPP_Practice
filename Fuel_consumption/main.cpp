#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "A plane must fly with cargo from point A to point C through point B.The capacity of the aircraft's fuel tank is 300 liters.\n\
Fuel consumption per 1 km depending on from the weight of the cargo on the aircraft the following:\n\
- up to 500 kg - 1 liter / km;\n\
- up to 1000 kg - 4 liters / km;\n\
- up to 1500 kg - 7 liters / km;\n\
- up to 2000 kg - 9 liters / km;\n\
- more than 2000 kg - the aircraft does not lift.\n\n\
The user enters the distance between points A and B, and the distance between points Band C, as well as the weight of the cargo.\n\
The program must calculate what is the minimum number fuel is needed to refuel the aircraft at point B, to fly from point A to point C.\n\
If it is impossible to overcome any of the distances, the program must display a message about the impossibility of flying according to the entered route." << endl << endl;

	const float fullTank = 300.0;
	float fromAtoB, fromBtoC, weight, fuelConsumption, needFuelFromAtoB, needFuelFromBtoC;
	string inputFromAtoB, inputFromBtoC, inputWeight;

	while (true)
	{
		cout << "Enter distance from A to B, km: ";
		cin >> inputFromAtoB;

		cout << "Enter distance from B to C, km: ";
		cin >> inputFromBtoC;

		cout << "Enter weight of cargo, kg: ";
		cin >> inputWeight;

		try
		{
			fromAtoB = stof(inputFromAtoB);
			fromBtoC = stof(inputFromBtoC);
			weight = stof(inputWeight);
		}
		catch (invalid_argument)
		{
			cout << endl << "You entered incorrect data.\nTry again and be careful this time." << endl << endl;
			continue;
		}

		if (fromAtoB <= 0 || fromBtoC <= 0 || weight <= 0)
		{
			cout << endl << "You entered incorrect data. Distance or weight must be more than zero.\nPlease, try again and be careful this time." << endl << endl;
			continue;
		}

		if (weight < 500)
		{
			fuelConsumption = 1;
		}
		else if (weight < 1000)
		{
			fuelConsumption = 4;
		}
		else if (weight < 1500)
		{
			fuelConsumption = 7;
		}
		else if (weight < 2000)
		{
			fuelConsumption = 9;
		}
		else
		{
			cout << endl << "!!!Too heavy load. The plane won't take off!!!\nTry to enter a load up to 2000 kg." << endl << endl;
			continue;
		}

		needFuelFromAtoB = fromAtoB * fuelConsumption;
		needFuelFromBtoC = fromBtoC * fuelConsumption;

		if (needFuelFromAtoB > fullTank || needFuelFromBtoC > fullTank)
		{
			cout << endl << "!!!Too heavy or too far.\nTry to reduce weight or distance." << endl << endl;
			continue;
		}

		cout << endl << "Everything is good. I wish you a successful flight!" << endl << endl;
		break;
	}
	return 0;
}
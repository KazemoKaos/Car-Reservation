//============================================================================
// Name        : Car.cpp
// Author      : Tyler Nguyen
// Version     : 10/01/20
// Description : Program 1
//============================================================================

#include "Car.hpp"
using namespace std;

Car::Car() 
{
	plateNumber = "";
	make = "";
	model = "";
	vehicleT = sedan;
	pricePerDay = 0.0;
	isAvailable = true;
}

Car::Car(string x, string y, string z, vehicleType vt)
{
	plateNumber = x;
	make = y;
	model = z;
	vehicleT = vt;
	pricePerDay = vt;
	isAvailable = true;
}

int Car::menu()
{
	int x;
	cout << "\n-------------------------------\n\tXYZ Car Rental\n------------------------------- " << endl;
	cout << "1. List all cars\n2. Add car to inventory\n3. Remove car from inventory\n4. List all reservations\n5. Add a reservations\n6. Cancel reservation\n7. Exit" << endl;
	cout << "\nPlease enter a number: ";
	cin >> x;
	return x;
}

string Car::getPlateNumber() { return plateNumber; }

string Car::getMake() { return make; }

string Car::getModel() { return model; }

vehicleType Car::getVehicleType() { return vehicleT; }

bool Car::getIsAvailable() { return isAvailable; }

double Car::getPricePerDay() { return pricePerDay; }

void Car::setPlateNumber(string x)
{
	plateNumber = x;
}

void Car::setMake(string y)
{
	make = y;
}

void Car::setModel(string z)
{
	model = z;
}

void Car::setVehicleType(vehicleType vt)
{
	vehicleT = vt;
}

void Car::setIsAvailable(bool av)
{
	isAvailable = av;
}

void Car::setPricePerDay(double ppd)
{
	pricePerDay = ppd;
}

void Car::listCars(Car car[], int lenC)
{
	if (lenC == 0)
		cout << "\nCar list empty.\n";
	else
	{
		cout << "\n\n************* Car Information ************* ";
		for (int i = 0; i < lenC; i++)
			cout << car[i] << endl;
	}
}

void Car::addCar(Car car[], int& lenC)
{
	string x;
	string y;
	string z;
	string vehT;

	cout << "\nEnter Plate Number: ";
	cin >> x;
	car[lenC].setPlateNumber(x);
	cout << "\nEnter Make: ";
	cin >> y;
	car[lenC].setMake(y);
	cout << "\nEnter Model: ";
	cin >> z;
	car[lenC].setModel(z);

	do
	{
		cout << "\nEnter Vehicle Type (sedan, suv, exotic): ";
		cin >> vehT;

		if (vehT.compare("sedan") == 0)
		{
			car[lenC].setVehicleType((vehicleType)sedan);
			car[lenC].setPricePerDay((vehicleType)sedan);
			break;
		}

		else if (vehT.compare("suv") == 0)
		{
			car[lenC].setVehicleType((vehicleType)suv);
			car[lenC].setPricePerDay((vehicleType)suv);
			break;
		}

		else if (vehT.compare("exotic") == 0)
		{
			car[lenC].setVehicleType((vehicleType)exotic);
			car[lenC].setPricePerDay((vehicleType)exotic);
			break;
		}

		else
			continue;
	} while (1);

	car[lenC].setIsAvailable(true);

	lenC++;
}

int Car::searchCar(Car car[], int lenC, string plNum)
{
	if (lenC == 0)
		cout << "\nCar list empty.\n";
	else
	{
		for (int i= 0; i < lenC; i++)
			if (plNum.compare(car[i].getPlateNumber()) == 0)
				return i;
	}
	return -1;
}

void Car::removeCar(Car car[], int& lenC)
{
	string plNum;
	if (lenC == 0)
		cout << "\nCar list empty.\n";
	else
	{
		int found = searchCar(car, lenC, plNum);

		cout << "\nEnter Plate Number to remove the car: ";
		cin >> plNum;

		if (found == -1)
			cout << "\nERROR: No car found on Plate Number: " << plNum << "\n";
		else
		{
			for (int c = found; c < lenC; c++)
				car[c] = car[c + 1];
			lenC--;
			cout << "\nCar with plate number " << plNum << " removed.\n";
		}
	}
}

void Car::listAvailableCars(Car car[], int lenC, string plNum)
{
	if (lenC == 0)
		cout << "\nCar list empty.\n";
	else
	{
		int i = 0;
		cout << "\n\n************* Car Information *************\n";
		for (int c = 0; c < lenC; c++)
			if (car[c].getPlateNumber().compare(plNum) == 0 && car[c].getIsAvailable())
				cout << i++ << " " << car[c] << endl;
	}
}

ostream& operator <<(ostream& os, Car& car)
{
	os << "\nPlate Number: " << car.plateNumber << "\nMake: " << car.make << "\nModel: " << car.model;
	os << "\nVehicle Type: ";

	if (car.pricePerDay == 10)
		os << "Sedan";
	else if (car.pricePerDay == 20)
		os << "Suv";
	else
		os << "Exotic";
	os << "\nPrice Per Day: " << car.pricePerDay;
	os << "\nAvailable Status: ";
	if (car.isAvailable)
		os << "Available";
	else
		os << "Not Available";
	return os;
}
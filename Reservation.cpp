//============================================================================
// Name        : Reservation.cpp
// Author      : Tyler Nguyen
// Version     : 10/01/20
// Description : Program 1
//============================================================================

#include "Reservation.hpp"
using namespace std;

Reservation::Reservation()
{
	name = "";
	vehicleRented = "";
}

Reservation::Reservation(string x, string y)
{
	name = x;
	vehicleRented = y;
}

string Reservation::getName() { return name; }

string Reservation::getVehicleRented() { return vehicleRented; }

void Reservation::setName(string x)
{
	name = x;
}

void Reservation::setVehicleRented(string y)
{
	vehicleRented = y;
}

void Reservation::listReservation(Reservation res[], int lenR)
{
	if (lenR == 0)
		cout << "\nReservation list empty.\n";
	else
	{
		cout << "\n\n************* Reservation Information ************* ";
		for (int i = 0; i < lenR; i++)
			cout << res[i] << endl;
	}
}

void Reservation::addReservation(Reservation res[], int& lenR, Car car[], int lenC)
{
	string name;
	string plNum;
	Car c;
	int ch;

	if (lenC == 0)
		cout << "\nCar list empty.\n";
	else
	{
		cout << "\nEnter customer name: ";
		cin >> name;
		cout << "\nEnter plate number: ";
		cin >> plNum;
		c.listAvailableCars(car, lenC, plNum);
		cout << "\nEnter your choice: ";
		cin >> ch;
		res[lenR].setName(name);
		res[lenR].setVehicleRented(car[ch].getPlateNumber());
		car[ch].setIsAvailable(false);
		lenR++;
	}
}

int Reservation::searchReservation(Reservation res[], int lenR, string plNum)
{
	if (lenR == 0)
		cout << "\nReservation list empty.\n";
	else
	{
		for (int i = 0; i < lenR; i++)
			if (plNum.compare(res[i].getVehicleRented()) == 0)
				return i;
	}
	return -1;
}

void Reservation::cancelReservation(Reservation res[], int& lenR, Car car[], int lenC)
{
	string plNum;
	if (lenR == 0)
		cout << "\nReservation list empty.\n";
	else
	{
		int found = searchReservation(res, lenR, plNum);

		cout << "\nEnter plate number: ";
		cin >> plNum;

		if (found == -1)
			cout << "\nERROR: No reservation found on plate number: " << plNum;
		else
		{
			for (int i = found; i < lenR; i++)
				res[i] = res[i + 1];

			car[found].setIsAvailable(true);
			lenR--;
			cout << "\nReservation of vehicle number " << plNum << " canceled successfully.\n";
		}
	}
}

ostream& operator <<(ostream& os, Reservation& rev)
{
	os << "\nName: " << rev.name << "\nVehicle Rented: " << rev.vehicleRented;
	return os;
}
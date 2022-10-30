//============================================================================
// Name        : Reservation.hpp
// Author      : Tyler Nguyen
// Version     : 10/01/20
// Description : Program 1
//============================================================================

#ifndef Reservation_hpp
#define Reservation_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include "Car.hpp"
using namespace std;

class Reservation : public Car
{
	string name;
	string vehicleRented;

public:
	
	Reservation();

	Reservation(string x, string y);

	string getName();

	string getVehicleRented();

	void setName(string x);

	void setVehicleRented(string y);

	void listReservation(Reservation res[], int lenR);

	void addReservation(Reservation res[], int& lenR, Car car[], int lenC);

	int searchReservation(Reservation res[], int lenR, string plNum);

	void cancelReservation(Reservation res[], int& lenR, Car car[], int lenC);

	friend ostream& operator <<(ostream& os, Reservation& rev);
};

#endif /* Reservation_hpp */
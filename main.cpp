//============================================================================
// Name        : main.cpp
// Author      : Tyler Nguyen
// Version     : 10/01/20
// Description : Program 1
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Car.hpp"
#include "Reservation.hpp"
#define MAX 100
using namespace std;
Car car[MAX];
Reservation res[MAX];

Car c1;
Reservation c2;

int main()
{
	int lenC = 0;
	int lenR = 0;

	do
	{
		switch (c1.menu())
		{
		case 1:
			c1.listCars(car, lenC);
			break;
		case 2:
			c1.addCar(car, lenC);
			break;
		case 3:
			c1.removeCar(car, lenC);
			break;
		case 4:
			c2.listReservation(res, lenR);
			break;
		case 5:
			c2.addReservation(res, lenR, car, lenC);
			break;
		case 6:
			c2.cancelReservation(res, lenR, car, lenC);
			break;
		case 7:
			cout << "Exiting ..." << endl;
			exit(0);
		default:
			cout << "\nError: Invalid Input";
		}
	} while (1);
	return 0;
}

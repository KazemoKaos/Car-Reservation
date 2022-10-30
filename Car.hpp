//============================================================================
// Name        : Car.hpp
// Author      : Tyler Nguyen
// Version     : 10/01/20
// Description : Program 1
//============================================================================

#ifndef Car_hpp
#define Car_hpp
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
enum vehicleType {sedan = 10, suv = 20, exotic = 30};

class Car
{
	string plateNumber;
	string make;
	string model;
	vehicleType vehicleT;
	double pricePerDay;
	bool isAvailable;

public:

	Car();

	Car(string x, string y, string z, vehicleType vt);

	int menu();

	string getPlateNumber();

	string getMake();

	string getModel();

	vehicleType getVehicleType();

	bool getIsAvailable();

	double getPricePerDay();

	void setPlateNumber(string x);

	void setMake(string y);

	void setModel(string z);

	void setVehicleType(vehicleType vt);

	void setIsAvailable(bool av);

	void setPricePerDay(double ppd);

	void listCars(Car car[], int lenC);

	void addCar(Car car[], int& lenC);

	int searchCar(Car car[], int lenC, string plNum);

	void removeCar(Car car[], int& lenC);

	void listAvailableCars(Car car[], int lenC, string plNum);

	friend ostream& operator <<(ostream& os, Car& car);
};

#endif /* Car_hpp */
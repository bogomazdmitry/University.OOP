#pragma once
#include <iostream>
#include <iomanip>

#include "Time.h"

class Transport
{
private:
	double costOfOneKM;
	double speed;
public:
	Transport(double costOfOneKN, double speed);
	Time timeOfTravel(double pathLength) const;
	double costOfTravel(double pathLength) const;
	void show(double pathLength) const;

	virtual std::string nameOfTransport() const = 0;

	virtual ~Transport();
};
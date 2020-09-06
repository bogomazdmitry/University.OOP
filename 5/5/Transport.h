#pragma once

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

	virtual std::string nameOfTransport() = 0;

	virtual ~Transport();
};
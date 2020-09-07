#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "Time.h"


class Transport
{
protected:
	double speed;
public:
	Transport();
	Transport(double new_speed);
	Time timeOfTravel(double pathLength) const;
	virtual std::string nameOfTransport() const = 0;
	virtual void show(double pathLength) const;
	virtual ~Transport();
};


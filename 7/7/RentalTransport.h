#pragma once
#include <iostream>
#include <iomanip>

#include "Time.h"
#include "Transport.h"

class RentalTransport : public Transport
{
private:
	double costOfOneKM;
public:
	RentalTransport(double costOfOneKN, double speed);
	
	double costOfTravelOfRental(double pathLength) const;
	virtual void show(double pathLength) const;

	virtual std::string nameOfTransport() const = 0;

	virtual ~RentalTransport();
};
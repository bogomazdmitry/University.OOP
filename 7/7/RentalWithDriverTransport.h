#pragma once

#include "Transport.h"

class RentalWithDriverTransport : public Transport
{
private:
	double costOfOneKM;;
public:
	RentalWithDriverTransport(double costOfOneKN, double speed);

	double costOfTravelOfRentalWithDriver(double pathLength) const;
	virtual void show(double pathLength) const;

	virtual std::string nameOfTransport() const = 0;

	virtual ~RentalWithDriverTransport();
};


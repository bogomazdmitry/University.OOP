#pragma once

#include "RentalTransport.h"
#include "RentalWithDriverTransport.h"

class Car : public RentalWithDriverTransport, public RentalTransport
{
public:
	Car();
	virtual std::string nameOfTransport() const;
	virtual void show(double pathLendth) const;
};
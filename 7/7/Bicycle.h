#pragma once

#include "RentalTransport.h"

class Bicycle : public RentalTransport
{
public:
	Bicycle();
	virtual std::string nameOfTransport() const;
};
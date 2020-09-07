#pragma once

#include "RentalTransport.h"

class Cart : public RentalTransport
{
public:
	Cart();
	virtual std::string nameOfTransport() const;
};
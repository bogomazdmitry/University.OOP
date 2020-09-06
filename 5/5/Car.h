#pragma once

#include "Transport.h"

class Car : public Transport
{
public:
	Car();
	virtual std::string nameOfTransport();
};
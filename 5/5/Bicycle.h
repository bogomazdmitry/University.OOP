#pragma once

#include "Transport.h"

class Bicycle : public Transport
{
public:
	Bicycle();
	virtual std::string nameOfTransport();
};
#pragma once

#include "Transport.h"

class Cart : public Transport
{
public:
	Cart();
	virtual std::string nameOfTransport();
};
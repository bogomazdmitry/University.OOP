#include "Bicycle.h"

Bicycle::Bicycle() :
	RentalTransport(15, 40)
{
}

std::string Bicycle::nameOfTransport() const
{
	return "Велосипед";
}


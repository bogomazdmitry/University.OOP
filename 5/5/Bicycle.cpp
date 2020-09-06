#include "Bicycle.h"

Bicycle::Bicycle() :
	Transport(15, 40)
{
}

std::string Bicycle::nameOfTransport() const
{
	return "Велосипед";
}


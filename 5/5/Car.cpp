#include "Car.h"

Car::Car():
	Transport(80, 60)
{
}

std::string Car::nameOfTransport()
{
	return "Машина";
}

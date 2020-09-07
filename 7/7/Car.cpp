#include "Car.h"

Car::Car() :
	RentalWithDriverTransport(90, 90),
	RentalTransport(80, 80)
{}

std::string Car::nameOfTransport() const
{
	return "Машина";
}

void Car::show(double pathLendth) const
{
	RentalTransport::show(pathLendth);
	std::cout << std::endl;
	RentalWithDriverTransport::show(pathLendth);
}

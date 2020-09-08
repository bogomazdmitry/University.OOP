#include "RentalTransport.h"

RentalTransport::RentalTransport(double costOfOneKM, double speed) :
	costOfOneKM(costOfOneKM),
	Transport(speed)
{
}


double RentalTransport::costOfTravelOfRental(double pathLength) const
{
	return pathLength * costOfOneKM;
}

void RentalTransport::show(double KM) const
{
	Transport::show(KM);
	std::cout << "За аренду: " << std::endl;
	std::cout << "Цена: " << std::setw(26) << costOfTravelOfRental(KM) << std::endl;
	std::cout << "Время: " << std::setw(21) << timeOfTravel(KM) << std::endl;
}

RentalTransport::~RentalTransport()
{
}

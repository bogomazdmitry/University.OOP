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
	std::cout << "�� ������: " << std::endl;
	std::cout << "����: " << std::setw(26) << costOfTravelOfRental(KM) << std::endl;
	std::cout << "�����: " << std::setw(21) << timeOfTravel(KM) << std::endl;
}

RentalTransport::~RentalTransport()
{
}

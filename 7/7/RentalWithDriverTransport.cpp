#include "RentalWithDriverTransport.h"

RentalWithDriverTransport::RentalWithDriverTransport(double costOfOneKN, double speed) :
	costOfOneKM(costOfOneKN),
	Transport(speed)
{
}


double RentalWithDriverTransport::costOfTravelOfRentalWithDriver(double pathLength) const
{
	return pathLength * costOfOneKM;
}

void RentalWithDriverTransport::show(double KM) const
{
	Transport::show(KM);
	std::cout << "�� ������ � ���������: " << std::endl;
	std::cout << "����: " << std::setw(26) << costOfTravelOfRentalWithDriver(KM) << std::endl;
	std::cout << "�����: " << std::setw(21) << timeOfTravel(KM) << std::endl;
}

RentalWithDriverTransport::~RentalWithDriverTransport()
{
}

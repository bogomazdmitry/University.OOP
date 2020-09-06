#include "Transport.h"

Transport::Transport(double costOfOneKN, double speed) :
	costOfOneKM(costOfOneKN),
	speed(speed)
{
}

Time Transport::timeOfTravel(double pathLength) const
{
	return Time(static_cast<size_t>(pathLength / speed * 3600));
}

double Transport::costOfTravel(double pathLength) const
{
	return pathLength * costOfOneKM;
}

void Transport::show(double KM) const
{
	std::cout << "Транспорт: " << std::setw(21) << nameOfTransport() << std::endl;
	std::cout << "Цена: " << std::setw(26) << costOfTravel(KM) << std::endl;
	std::cout << "Время: " << std::setw(21) << timeOfTravel(KM) << std::endl;
}

Transport::~Transport()
{
}

#include "Transport.h"

Transport::Transport()
{
}

Transport::Transport(double new_speed):
	speed(new_speed)
{
}

void Transport::show(double pathLength) const
{
	std::cout << "Транспорт: " << std::setw(21) << nameOfTransport() << std::endl;
}

Time Transport::timeOfTravel(double pathLength) const
{
	return Time(static_cast<size_t>(pathLength / speed * 3600));
}

Transport::~Transport()
{
}

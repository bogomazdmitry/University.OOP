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

Transport::~Transport()
{
}

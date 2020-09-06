#include "Time.h"

Time::Time() :
	hours(0),
	minutes(0),
	seconds(0)
{
}

Time::Time(size_t numberOfSeconds)
{
	seconds = numberOfSeconds % 60;
	numberOfSeconds /= 60;
	minutes = numberOfSeconds % 60;
	hours =	numberOfSeconds / 60;
}

Time::Time(const Time& copy) :
	seconds(copy.seconds),
	minutes(copy.minutes),
	hours(copy.hours) {}

void Time::set_hours(int newHours)
{
	if (newHours < 0)
		throw std::exception("ВЫход за диапозон часов");
	hours = newHours;
}

void Time::set_minutes(int newMinutes)
{
	if (newMinutes < 0 || newMinutes > 60)
		throw std::exception("ВЫход за диапозон минут");
	minutes = newMinutes;
}

void Time::set_seconds(int newSeconds)
{
	if (newSeconds < 0 || newSeconds > 60)
		throw std::exception("ВЫход за диапозон секунд");
	seconds = newSeconds;
}

size_t Time::timeToSeconds() const
{
	return seconds + 60 * minutes + 3600 * hours;
}

std::istream& operator>>(std::istream& is, Time& t)
{
	int temp1;
	int temp2;
	int temp3;
	is >> temp1 >> temp2 >> temp3;

	t.set_hours(temp1);
	t.set_minutes(temp2);
	t.set_seconds(temp3);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << ':' << t.minutes << ':' << t.seconds;
	return os;
}

#pragma once

#include <iostream>
class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time();
	Time(size_t numberOfSeconds);
	Time(const Time& copy);

	void set_hours(int newHours);
	void set_minutes(int newMinutes);
	void set_seconds(int newSeconds);

	inline size_t timeToSeconds() const;

	friend std::istream& operator>>(std::istream& is, Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Time
{
private:
	int hour, min, sec;
	void sec_to_time(int);

public:
	Time();
	Time(int, int, int);
	Time(std::string);
	Time(int);
	Time(Time&);

	int operator -(Time&);
	Time operator +(int);
	Time operator -(int);

	bool operator >(Time&);
	bool operator <(Time&);
	bool operator ==(Time&);

	int time_to_sec();
	int time_to_min();
};


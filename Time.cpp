#include "Time.h"

void Time::sec_to_time(int secs)
{
	sec = secs % 60;
	secs /= 60;
	min = secs % 60;
	secs /= 60;
	hour = secs;
}

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(int hour, int min, int sec)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

Time::Time(std::string time)
{
	const char SEP = ':';
	std::stringstream ist(time);
	std::string h;
	std::string m;
	std::string s;
	std::getline(ist, h, SEP);
	std::getline(ist, m, SEP);
	std::getline(ist, s, SEP);
	hour = std::stoi(h);
	min = std::stoi(m);
	sec = std::stoi(s);
}

Time::Time(int secs)
{
	sec_to_time(secs);
}

Time::Time(Time& time)
{
	hour = time.hour;
	min = time.min;
	sec = time.sec;
}

int Time::operator -(Time& time)
{
	int t1 = time_to_sec(*this);
	int t2 = time_to_sec(time);
	return abs(t1 - t2);
}

Time Time::operator +(int secs)
{
	int time = time_to_sec(*this);
	time += secs;
	this->sec_to_time(time);
	return *this;
}

Time Time::operator -(int secs)
{
	int time = time_to_sec(*this);
	time -= secs;
	this->sec_to_time(time);
	return *this;
}

bool Time::operator <(Time& time)
{
	return time_to_sec(*this) < time_to_sec(time);
}

bool Time::operator >(Time& time)
{
	return time_to_sec(*this) > time_to_sec(time);
}

bool Time::operator ==(Time& time)
{
	return time_to_sec(*this) == time_to_sec(time);
}

int Time::time_to_sec(Time& time)
{
	return (time.hour * 60 + time.min) * 60 + time.sec;
}

int Time::time_to_min(Time& time)
{
	if (sec >= 30)
	{
		return hour * 60 + min + 1;
	}
	else
	{
		return hour * 60 + min;
	}
}
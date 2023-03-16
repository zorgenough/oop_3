#pragma once
#include "Time.h"
class Bill
{
private:
	std::string surname;
	std::string number;
	double rate;
	int discount;
	Time start;
	Time end;
	double sum;
	void sum_count();
public:
	Bill();
	Bill(std::string, std::string, double, int, Time, Time);

	std::string get_surname();
	std::string get_number();
	double get_rate();
	int get_discount();
	Time get_start();
	Time get_end();
	int get_sub_min();
	double get_sum();

	void set_surname(std::string);
	void set_number(std::string);
	void set_rate(double);
	void set_discount(int);
	void set_start(Time);
	void set_end(Time);

	std::string toString();

	friend std::ostream& operator <<(std::ostream&, Bill&);
	friend std::istream& operator >>(std::istream&, Bill&);
};


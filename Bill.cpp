#include "Bill.h"

void Bill::sum_count()
{
	sum = (get_sub_min()*rate)*(1-0.01*discount);
}

Bill::Bill()
{
	surname = "";
	number = "";
	rate = 0.0;
	discount = 0;
	sum = 0;
}

Bill::Bill(std::string surname, std::string number, double rate, int discount, Time start, Time end)
{
	this->surname = surname;
	this->number = number;
	this->rate = rate;
	this->discount = discount;
	this->start = start;
	this->end = end;
	sum_count();
}

std::string Bill::get_surname()
{
	return surname;
}

std::string Bill::get_number()
{
	return number;
}

double Bill::get_rate()
{
	return rate;
}

int Bill::get_discount()
{
	return discount;
}

Time Bill::get_start()
{
	return start;
}

Time Bill::get_end()
{
	return end;
}

int Bill::get_sub_min()
{
	int tmp = abs(end - start);
	if (tmp % 60 > 0)
	{
		return tmp / 60 + 1;
	}
	else
	{
		return tmp / 60;
	}
}

double Bill::get_sum()
{
	return sum;
}

void Bill::set_surname(std::string surname)
{
	this->surname = surname;
}

void Bill::set_number(std::string number)
{
	this->number = number;
}

void Bill::set_rate(double rate)
{
	this->rate = rate;
	sum_count();
}

void Bill::set_discount(int discount)
{
	this->discount = discount;
	sum_count();
}

void Bill::set_start(Time start)
{
	this->start = start;
	sum_count();
}

void Bill::set_end(Time end)
{
	this->end = end;
	sum_count();
}

std::string Bill::toString()
{
	return std::to_string(sum) + " рублей";
}

std::ostream& operator<<(std::ostream& output, Bill& bill)
{
	output << "Фамилия: " << bill.surname << ", номер: " << bill.number << ", сумма к оплате: " << bill.toString();
	return output;
}

std::istream& operator>>(std::istream& input, Bill& bill)
{
	input >> bill.surname >> bill.number >> bill.rate >> bill.discount;
	std::string st, en;
	input >> st >> en;
	bill.start = Time::Time(st);
	bill.end = Time::Time(en);
	bill.sum_count();
	return input;
}

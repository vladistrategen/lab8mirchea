#include "Date.h"
using std::string;
int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}

int Date::get_year()
{
	return year;
}

void Date::set_day(int d)
{
	day = d;
}

void Date::set_month(int m)
{
	month = m;
}

void Date::set_year(int y)
{
	year = y;
}

Date::Date()
{
	day = -1;
	month = -1;
	year = -1;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

Date::~Date()
{
}

Date& Date::operator=(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}



bool Date::operator==(const Date& other)
{
	return((this->day == other.day) && (month == other.month) && (year = other.year));
}

string to_string(const Date& oth)
{
	string res = "";
	res += std::to_string(oth.day) + "/" + std::to_string(oth.month) + "/" + std::to_string(oth.year);
	return res;
}

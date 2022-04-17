#pragma once
#include <string>
using std::string;
class Date
{
public:
	int get_day();
	int get_month();
	int get_year();
	void set_day(int d);
	void set_month(int m);
	void set_year(int y);
	Date();
	Date(int d, int m, int y);
	Date(const Date& other);
	~Date();
	Date& operator=(const Date& other);
	friend string to_string(const Date& oth);
	bool operator==(const Date& other);
private:
	int day;
	int month;
	int year;
};


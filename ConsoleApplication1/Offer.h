#pragma once
#include <string>
#include <iostream>
#include "Date.h"
using std::string;


//typedef enum  offer_type {
//	circuit ,
//	city_break ,
//	cruise ,
//	all_inclusive,
//	wrong_type
//};

class Offer
{
public:

	string get_id();
	string get_dest();
	string get_departure();
	float get_price();
	int get_type();
	friend string to_string(const Offer& of);
	Offer();
	Offer(string id_i, string dest, string dep, Date& d_s, Date& d_e, float price, int t);
	Offer(const Offer& of);
	Offer& operator=(const Offer of);
	friend std::ostream operator<<(std::ostream out, Offer of);
	bool operator==(const Offer& other);
	friend std::istream& operator >> (std::istream& in, Offer& c);
private:

	string id;
	string dest;
	string departure;
	float price;
	Date start_date{};
	Date end_date{};
	int type;
};


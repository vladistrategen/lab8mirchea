#include "Offer.h"
#include <string>
#include <cmath>
using std::string;
using std::to_string;

string Offer::get_id()
{
	return id;
}

string Offer::get_dest()
{
	return dest;
}

string Offer::get_departure()
{
	return departure;
}

float Offer::get_price()
{
	return price;
}

int Offer::get_type() {
	return this->type;
}


Offer::Offer()
{
	id = " - 1";
	dest = "";
	departure = "";
	price = -1;
	start_date = Date{};
	end_date = Date{};
	type = -1;
}

Offer::Offer(string id_i, string dest, string dep, Date& d_s, Date& d_e, float price, int t)
{
	id = id_i;
	this->dest = dest;
	this->departure = dep;
	//this->type = t;
	switch (t) {
	case 0:
		type = 0;
		break;
	case 1:
		type = 1;
		break;
	case 2:
		type = 2;
		break;
	case 3:
		type = 3;
		break;
	default:
		type = -1;
		break;

	}
	start_date.set_day(d_s.get_day());
	start_date.set_month(d_s.get_month());
	start_date.set_year(d_s.get_year());
	end_date.set_day(d_e.get_day());
	end_date.set_month(d_e.get_month());
	end_date.set_year(d_e.get_year());
	//this->end_date = e;
	this->price = price;

}

Offer::Offer(const Offer& of)
{
	departure = of.departure;
	dest = of.dest;
	id = of.id;
	start_date = of.start_date;
	end_date = of.end_date;
	price = of.price;
	type = of.type;
}

Offer& Offer::operator=(Offer of)
{
	//Offer temp{of.id,of.dest,of.departure,of.start_date,of.end_date,of.price,of.type};
	departure = of.departure;
	dest = of.dest;
	id = of.id;
	start_date = of.start_date;
	end_date = of.end_date;
	price = of.price;
	type = of.type;
	return *this;
}

bool Offer::operator==(const Offer& other)
{
	return ((this->departure == other.departure) &&
		(this->dest == other.dest) && (this->id == other.id)
		&& (this->type == other.type) &&
		(fabs(this->price - other.price) < 0.005) &&
		(this->start_date == other.start_date)
		&& (this->end_date == other.end_date));
}

string to_string(const Offer& of)
{
	string res = "";
	res += "Offer id: " + of.id;
	res += ", Type: ";// +std::to_string(this->type);
	switch (of.type) {
	case 0:
		res += "circuit";
		break;
	case 1:
		res += "city break";
		break;
	case 2:
		res += "cruise";
		break;
	case 3:
		res += "all inclusive";
		break;
	default:
		res += "wrong_type";
		break;

	}
	res += "\n";
	res += "Start date: " + to_string(of.start_date);
	res += "\nEnd date: " + to_string(of.end_date) + "\n";
	res += "\tLeave from: " + of.departure + "\n";
	res += "\tArrive at: " + of.dest + "\n";
	res += "Price:" + to_string(of.price) + "\n";
	return res;

}

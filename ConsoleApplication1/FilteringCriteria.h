#pragma once
#include "Offer.h"
#include "DynamicArray.h"
#include <string>
using std::string;
//template <typename T>
class FilteringCriteria
{
public:
	//virutal DynamicArray<T> filter(DynamicArray<T>& data) = 0;
	virtual DynamicArray<Offer> filter(DynamicArray<Offer>& data) = 0;

};


class FilteringPrice :virtual public FilteringCriteria {
private:
	float price;
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data) override;
	FilteringPrice(float p);
};


class FilteringType :virtual public FilteringCriteria {
private:
	int type;
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data) override;
	FilteringType(int t);
};


class FilteringDeparture :virtual public FilteringCriteria {
private:
	string departure;
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data) override;
	FilteringDeparture(string dep);
};


class FilteringCriteriaAnd :virtual public FilteringCriteria{

private:
	FilteringCriteria* crt1;
	FilteringCriteria* crt2;
public:
	FilteringCriteriaAnd( FilteringCriteria& c1,  FilteringCriteria& c2);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
};



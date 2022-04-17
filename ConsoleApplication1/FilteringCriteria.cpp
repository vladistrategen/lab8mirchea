#include "FilteringCriteria.h"
#include <cmath>



DynamicArray<Offer> FilteringPrice::filter(DynamicArray<Offer>& data)
{
    DynamicArray<Offer> res;
    for (int i = 0;i < data.getLength();i++) {
        if ((fabs(data.get(i).get_price() - this->price)<0.005) || data.get(i).get_price()<this->price)
            res.append(data.get(i));
    }
    return res;
}

FilteringPrice::FilteringPrice(float p)
{
    price = p;
}

DynamicArray<Offer> FilteringType::filter(DynamicArray<Offer>& data)
{
    DynamicArray<Offer> res;
    for (int i = 0;i < data.getLength();i++) {
        if (data.get(i).get_type() == this->type)
            res.append(data.get(i));
    }
    return res;
}

FilteringType::FilteringType(int t)
{
    type = t;
}

DynamicArray<Offer> FilteringDeparture::filter(DynamicArray<Offer>& data)
{
    DynamicArray<Offer> res;
    for (int i = 0;i < data.getLength();i++) {
        if (data.get(i).get_departure() == this->departure)
            res.append(data.get(i));
    }
    return res;
}

FilteringDeparture::FilteringDeparture(string dep)
{
    departure = dep;
}

FilteringCriteriaAnd::FilteringCriteriaAnd( FilteringCriteria& c1, FilteringCriteria& c2) {
    crt1 = &c1;
    crt2 = &c2;
}

DynamicArray<Offer> FilteringCriteriaAnd::filter(DynamicArray<Offer>& data) {
    DynamicArray<Offer> res;
    res = crt1->filter(data);
    res = crt2->filter(res);
    return res;
}
// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DynamicArray.h"
#include "FilteringCriteria.h"
#include "Offer.h"
using std::cout;
using std::endl;
int main()
{
    
    DynamicArray<int> da;
    da.append(3);
    cout << da<<endl;
    DynamicArray<Offer> oa;
    Date s_d{ 23, 8, 2021 };
    Date e_d{ 23,9,2021 };
    Offer o1{ "1","bucuresti","cluj",s_d,e_d,3,2 };
    Offer o2{ "2","bucuresti","new york",s_d,e_d,1,2 };
    Offer o3{ "3","bucuresti","los angeles",s_d,e_d,4,3 };
    Offer o4{ "4","bucuresti","new york",s_d,e_d,5,3 };
    Offer o5{ "5","bucuresti","cluj",s_d,e_d,20,3 };
    Offer o6{ "6","bucuresti","new york",s_d,e_d,7,3 };
    Offer o7{ "7","bucuresti","new york",s_d,e_d,79321.232,3 };
    oa.append(o1);
    oa.append(o2);
    oa.append(o3);
    oa.append(o4);
    oa.append(o5);
    oa.append(o6);
    oa.append(o7);
    FilteringPrice fp5{ 5 };
    FilteringType ft3{ 3 };
    FilteringType ft{ 2 };
    FilteringDeparture fdny{ "new york" };
    FilteringDeparture fdc{ "cluj" };
    //FilteringCriteria<int> cv;
    FilteringCriteriaAnd fat3p5{ ft3,fp5 };
   /* cout << ft3.filter(oa);
    cout << "\n-------------------------\n";
    cout << fp5.filter(oa);
    cout << "\n-------------------------\n";*/
    cout << fat3p5.filter(oa);
    cout << "\n-------------------------\n";
    FilteringCriteriaAnd fdnyfp5{ fdny,fp5 };
    cout << fdnyfp5.filter(oa);
    cout << "\n-------------------------\n";
    FilteringCriteriaAnd fdnyft3{ fdny,ft3 };
    cout << fdnyft3.filter(oa);


    //cout << oa;
    

}

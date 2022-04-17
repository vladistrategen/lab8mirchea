// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DynamicArray.h"
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
    Offer o1{ "1a","cluj","bucuresti",s_d,e_d,3,2 };
    oa.append(o1);
    cout << oa;

}

#pragma once
#include <string>
#include <ostream>
#include "Offer.h"
using namespace std;

template <class ElementType>
class DynamicArray
{
public:
	
	DynamicArray(int capacity=100) {
		length = 0;
		this->capacity = capacity;
		data = new ElementType[capacity]();

		if (data == nullptr) {
			cerr << "DynamicArray(): failed to allocate memory" << endl;
			exit(-1);
		}
	}

	~DynamicArray() {
		//free the allocated memory
		delete[] data;
	}

	DynamicArray& operator=(const DynamicArray& other) {

		if (this != &other) { // self assignment check
			// deep copy of other
			length = other.length;
			capacity = other.capacity;

			delete[] this->data;
			// !! data 
			// data = other.data; NOO! this is shallow copy
			// deep copy of data
			data = new ElementType[other.capacity]();

			if (data == nullptr) {
				cerr << "operator=(): failed to allocate memory" << endl;
				exit(-1);
			}

			for (unsigned int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		return *this; // the type of this is DynamicArray* -> dereferencing
	}

	DynamicArray(const DynamicArray& other) {
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		data = new ElementType[other.capacity]();

		if (data == nullptr) {
			cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}

	void append(const ElementType& v, bool* err=nullptr)
	{
		// todo 
		// check if the length < capacity
		if (length == capacity) {
			// double the capacity
			resize(capacity * 2);
		}
		data[length] = v;

		length++;
	}

	friend ostream& operator<<(ostream& s, const DynamicArray& arr) {
		// [1 2 3 4 5 ]
		//s << "[";
		for (unsigned int i = 0; i < arr.length; i++) {
			s << to_string(arr.data[i]);
			//s << "\n------------------------------\n";
		}
		//s << "]";
		return s;
	}
	//
	//ElementType DynamicArray::popBack() {
	//	// delete and return the last element in the array
	//	// pre array is not empty
	//	if (length == 0) {
	//		// unfriendly way of handling corner cases
	//		cerr << "Precondition does not hold: popBack()" << endl;
	//		exit(-1);
	//	}
	//		
	//	// convention 0 - elements that were not set
	//
	//	ElementType v = data[length];
	//	length--;
	//
	//	return v;
	//}
	//
	//ElementType DynamicArray::remove(unsigned int index)
	//{
	//	//  index >= 0 and index < length
	//	// pre index >=0 and index < length
	//	if (index >= 0 && index < length) {
	//		ElementType v = data[index];
	//		for (unsigned int i = index; i < length - 1; i++)
	//			data[i] = data[i + 1];
	//		length--;
	//		return v;
	//	}
	//	else {
	//		// unfriendly way of handling corner cases
	//		cerr << "Precondition does not hold: remove()" << endl;
	//		exit(-1);
	//	}
	//}


	ElementType& get(unsigned int index) {

		// pre index >=0 and index < length
		if (index >= 0 && index < length) {
			return data[index];
		}
		else {
			// unfriendly way of handling corner cases
			cerr << "Precondition does not hold: get()" << endl;
			exit(-1);
		}
	}

	


private:
	// static -> it belongs to the class
	static int count;
	// Length – how many elements do we have(0)
	unsigned int length;
	//	Capacity – the max number of elements
	unsigned int capacity;
	// data - array itself
	ElementType* data;

	void resize(unsigned int newCapacity) {

		this->capacity = newCapacity;
		// no realloc  in c++

		ElementType* newData = new ElementType[newCapacity]();
		if (newData == nullptr) {
			cerr << "resize(): failed to allocate memory" << endl;
			exit(-1);
		}
		// previous elements located in data
		// copy them in newData
		for (unsigned int i = 0; i < length; i++) {
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}
};

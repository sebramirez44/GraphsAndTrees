#pragma once
#include <iostream>
using namespace std;

template<class T> class List
{
protected:
	int length;

public:
	List(int length)
	{
		this->length = length;
	};

	inline int getLength()
	{
		return length;
	};

	inline bool isEmpty()
	{
		return length == 0;
	};

	virtual void add(T* element) = 0;
	virtual void insert(T* element, int pos) = 0;
	virtual void remove(T* element) = 0;
	virtual void remove(int pos) = 0;
	virtual T* getElement(int pos) = 0;
	virtual int getPosition(T* element) = 0;
};


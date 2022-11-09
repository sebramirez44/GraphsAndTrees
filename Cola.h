#pragma once
#include <iostream>
using namespace std;

template<class T> class Cola
{

public:
	virtual void add(T* elemento) = 0;
	virtual T* remove() = 0;
	virtual T* top() = 0;
	virtual T* last() = 0;
	virtual bool isEmpty() = 0;
};


#pragma once
#include <iostream>
using namespace std;

template<class T> class Pila
{
	
public:
	virtual void push(T* elemento) = 0; //adicionar
	virtual T* pop() = 0; //extraer
	virtual T* top() = 0; //tope
	virtual bool isEmpty() = 0; // es vacia
};


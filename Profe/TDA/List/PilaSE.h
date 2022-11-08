#pragma once
#include "NodoSE.h"
#include "Pila.h"
#include <iostream>
using namespace std;

template<class T> class PilaSE : public Pila<T>
{
protected:
	NodoSE<T>* top_;

public:
	PilaSE()
	{
		this->top_ = NULL;
	}

	~PilaSE()
	{
		
	}

	void push(T* elemento)
	{
		NodoSE<T>* nuevo = new NodoSE<T>(elemento);
		nuevo->setSiguiente(top_);
		this->top_ = nuevo;
	}

	T* pop()
	{
		if (this->top_ == NULL) return NULL;

		T* valor = this->top_->getValor();		
		this->top_ = this->top_->getSiguiente();
		return valor;
	}

	T* top()
	{
		return this->top_ == NULL ? NULL : this->top_->getValor();
	}

	bool isEmpty()
	{
		return this->top_ == NULL;
	}
};


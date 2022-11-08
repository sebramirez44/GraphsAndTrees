#pragma once
#include "NodoSE.h"
#include "Cola.h"
#include <iostream>
using namespace std;

template<class T> class ColaSE : public Cola<T>
{
protected:
	NodoSE<T>* top_;
	NodoSE<T>* last_;

public:
	ColaSE()
	{
		this->top_ = NULL;
		this->last_ = NULL;
	}

	~ColaSE()
	{
	
	}

	void add(T* elemento)
	{
		NodoSE<T>* nuevo = new NodoSE<T>(elemento);
		if (this->isEmpty())
		{
			this->top_ = nuevo;
			this->last_ = nuevo;
		}
		else
		{
			this->last_->setSiguiente(nuevo);
			this->last_ = nuevo;
		}
	}

	T* remove()
	{
		if (this->top_ == NULL) return NULL;

		T* valor = this->top_->getValor();
		this->top_ = this->top_->getSiguiente();

		if (this->top_ == NULL)
			this->last_ = NULL;

		return valor;
	}

	T* top()
	{
		return this->top_ == NULL ? NULL : this->top_->getValor();
	}

	T* last()
	{
		return this->last_ == NULL ? NULL : this->last_->getValor();
	}

	bool isEmpty()
	{
		return this->top_ == NULL;
	}
};


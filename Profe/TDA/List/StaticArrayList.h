#pragma once
#include "List.h"
#include "ArrayList.h"
#include <iostream>
using namespace std;

template<class T> class StaticArrayList : public ArrayList<T>
{
public:
	StaticArrayList(int length) : ArrayList<T>(length)
	{
		this->list = new T*[length];
	}

	void add(T* element)
	{
		if (this->currentAmount == this->length)
		{
			throw "No se puede adicionar el elemento. Arreglo estatico esta lleno";
		}

		this->list[this->currentAmount++] = element;
	}

	void insert(T* element, int pos)
	{
		if (pos < 0 || pos >= this->currentAmount)
		{
			throw "No se puede insertar el elemento porque la posicion es incorrecta";
		}

		if (this->currentAmount > this->length - 1)
		{
			throw "No se puede insertar el elemento porque la lista esta llena";
		}

		for (int i = this->currentAmount; i > pos; i--)
		{
			this->list[i] = this->list[i - 1];
		}
		this->list[pos] = element;
		this->currentAmount++;
	}
};


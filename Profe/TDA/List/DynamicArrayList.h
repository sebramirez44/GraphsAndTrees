#pragma once
#include "List.h"
#include "ArrayList.h"
#include <iostream>
using namespace std;

template<class T> class DynamicArrayList : public ArrayList<T>
{
public:
	DynamicArrayList(int length) : ArrayList<T>(length)
	{
		this->list = new T*[this->length];
	}

	void add(T* element)
	{
		if (this->currentAmount == this->length)
		{
			this->list = increaseArray(this->length + 10);
		}

		this->list[this->currentAmount++] = element;
	}

	void insert(T* element, int pos)
	{
		if (pos < 0 || pos >= this->currentAmount)
		{
			throw "No se puede insertar el elemento porque la posicion es incorrecta";
		}

		if (this->currentAmount == this->length)
		{
			this->list = increaseArray(this->length + 10);
		}

		for (int i = this->currentAmount; i > pos; i--)
		{
			this->list[i] = this->list[i - 1];
		}
		this->list[pos] = element;
		this->currentAmount++;
	}

private:
	T** increaseArray(int newLenght)
	{
		this->length = newLenght;
		T** aux = new T*[this->length];
		for (int i = 0; i < this->currentAmount; i++)
		{
			aux[i] = this->list[i];
		}
		delete[] this->list;
		return aux;
	}
};


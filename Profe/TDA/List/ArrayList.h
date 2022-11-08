#pragma once
#include "List.h"
#include <iostream>
using namespace std;

template<class T> class ArrayList : public List<T>
{
protected:
	int currentAmount;
	T** list;

public:
	ArrayList(int length) : List<T>(length)
	{
		currentAmount = 0;
		this->list = NULL;
	}

	~ArrayList()
	{
		for (int i = 0; i < this->currentAmount; i++)
		{
			delete this->list[i];
		}
		delete[] this->list;
	}

	T* getElement(int pos)
	{
		if (pos < 0 || pos > currentAmount)
		{
			throw "Posicion incorrecta";
		}

		return this->list[pos];
	}

	int getPosition(T* element)
	{
		for (int i = 0; i < this->currentAmount; i++)
		{
			if ((*this->list[i]) == (*element))
			{
				return i;
			}
		}

		return -1;
	}

	void remove(int pos)
	{
		if (pos < 0 || pos >= this->currentAmount)
		{
			throw "No se puede eliminar el elemento en la posicion especificada";
		}

		for (int i = pos; i < this->currentAmount; i++)
		{
			this->list[i] = this->list[i + 1];
		}
		this->currentAmount--;
	}

	void remove(T* element)
	{
		for (int i = 0; i < this->currentAmount; i++)
		{
			if ((*this->list[i]) == (*element))
			{
				remove(i);
				return;
			}
		}

		throw "El elemento a eliminar no existe";
	}

	inline int getCurrentAmount()
	{
		return this->currentAmount;
	}
};


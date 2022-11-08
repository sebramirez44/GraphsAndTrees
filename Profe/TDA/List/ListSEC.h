#pragma once
#include "ListSE.h"
#include "NodoSE.h"
#include <iostream>

template<class T> class ListSEC : public ListSE<T>
{
public:
	ListSEC() : ListSE<T>()
	{
		
	}
	
	~ListSEC()
	{
	
	}

	void add(T* element)
	{
		NodoSE<T>* nuevo = new NodoSE<T>(element);
		if (this->cabeza == NULL)
		{
			this->cabeza = nuevo;
			this->cabeza->setSiguiente(this->cabeza);
		}
		else
		{
			NodoSE<T>* temp = getUltimo();
			temp->setSiguiente(nuevo);
			nuevo->setSiguiente(this->cabeza);
		}
		this->length++;
	}

	void remove(int pos)
	{
		if (pos < 0 || pos >= this->length)
		{
			throw "Posicion incorrecta";
		}

		if (pos == 0)
		{
			NodoSE<T>* temp = getUltimo();
			NodoSE<T>* rem  = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			temp->setSiguiente(this->cabeza);
			delete rem;
			this->length--;
		}
		else if (pos == this->length - 1)
		{
			/*NodoSE<T>* anteriorUlt = this->getElement(pos - 1);
			NodoSE<T>* rem = anteriorUlt->getSiguiente();
			anteriorUlt->setSiguiente(this->cabeza);
			delete rem;
			this->length--;*/
		}
		else
		{
			//invocar eliminar de la clase padre!!!
		}		
	}

private:
	NodoSE<T>* getUltimo()
	{
		NodoSE<T>* temp = this->cabeza;
		while (temp->getSiguiente() != this->cabeza)
		{
			temp = temp->getSiguiente();
		}
		return temp;
	}
};


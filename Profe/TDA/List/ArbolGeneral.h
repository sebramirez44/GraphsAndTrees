#pragma once
#include "ListSE.h"
#include <iostream>
using namespace std;

template<class T> class ArbolGeneral
{
protected:

	T* dato;
	ListSE<ArbolGeneral<T>>* hijos;

public:
	ArbolGeneral(T* dato)
	{
		this->dato = dato;
		this->hijos = new ListSE<ArbolGeneral<T>>();
	};

	~ArbolGeneral()
	{
	
	};

	T* getRaiz()
	{
		return this->dato;
	};

	bool esHoja()
	{
		return this->hijos->getLength() == 0;
	};

	int getGrado()
	{
		return this->hijos->getLength();
	};

	void addicionarParaTodaOcurrencia(T* raiz, T* hijo)
	{
		if ((*this->dato) == (*raiz))
		{
			this->hijos->add(new ArbolGeneral<T>(hijo));
		}

		for (int i = 0; i < this->hijos->getLength(); i++)
		{
			this->hijos->getElement(i)->addicionarParaTodaOcurrencia(raiz, hijo);
		}
	};

	bool addicionarPrimeraOcurrencia(T* raiz, T* hijo)
	{
		if ((*this->dato) == (*raiz))
		{
			this->hijos->add(new ArbolGeneral<T>(hijo));
			return true;
		}

		for (int i = 0; i < this->hijos->getLength(); i++)
		{
			if (this->hijos->getElement(i)->addicionarPrimeraOcurrencia(raiz, hijo));
			{
				return true;
			}
		}

		return false;
	};

	int getAltura()
	{
		if (esHoja())
		{
			return 0;
		}

		int altura = -1;
		for (int i = 0; i < this->hijos->getLength(); i++)
		{
			int altura_aux = this->hijos->getElement(i)->getAltura();
			if (altura_aux > altura)
			{
				altura = altura_aux;
			}
		}

		return altura + 1;
	};

	int getCantHojas()
	{
		if (esHoja())
		{
			return 1;
		}

		int cantHojas = 0;
		for (int i = 0; i < this->hijos->getLength(); i++)
		{
			cantHojas = cantHojas + this->hijos->getElement(i)->getCantHojas();
		}

		return cantHojas;
	};

	void elimminarImpares()
	{
		if (!this->esHoja())
		{
			for (int i = this->hijos->getLength() - 1; i >= 0; i--)
			{
				if ((i + 1) % 2 != 0)
				{
					this->hijos->remove(i);
				}
				else
				{
					this->hijos->getElement(i)->elimminarImpares();
				}
			}
		}
	};

	bool esDescendiente(T* a, T* b)
	{
		if ((*this->dato) == (*a))
		{
			return existeDato(b);
		}
		
		for (int i = 0; i < this->hijos->getLength(); i++)
		{
			if (this->hijos->getElement(i)->esDescendiente(a, b)) // si es TRUE retorno TRUE porque b es descendiente de a
			{
				return true;
			}
		}
		return false;
	};

private:

	bool existeDato(T* b)
	{
		if ((*this->dato) == (*b))
		{
			return true;
		}

		for (int i = 0; i < this->hijos->getLength(); i++)
		{
			if (this->hijos->getElement(i)->existeDato(b))
			{
				return true;
			}
		}

		return false;
	};

};


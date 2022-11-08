#pragma once
#include <iostream>
using namespace std;

template<class T> class ArbolBinario
{
protected:

	T* raiz;
	ArbolBinario<T>* izq;
	ArbolBinario<T>* der;

public:

	ArbolBinario() 
	{
		this->raiz = NULL;
		this->izq = NULL;
		this->der = NULL;
	};

	ArbolBinario(T* dato)
	{
		this->raiz = dato;
		this->izq = new ArbolBinario<T>();
		this->der = new ArbolBinario<T>();
	};

	~ArbolBinario()
	{
		if (raiz != NULL)
		{
			delete raiz;
		}

		if (this->izq != NULL)
		{
			delete izq;
		}

		if (this->der != NULL)
		{
			delete der;
		}
	};

	bool adicionar(T* raiz, T* hijo)
	{
		if ((*this->raiz) == (*raiz))
		{
			if (this->izq->esVacio())
			{
				this->izq = new ArbolBinario<T>(hijo);
				return true;
			}
			else if (this->der->esVacio())
			{
				this->der = new ArbolBinario<T>(hijo);
				return true;
			}
			
			return false; // mejor retornar excepcion
		}

		bool add = !this->izq->esVacio() ? this->izq->adicionar(raiz, hijo) : false;
		if (!add && !this->der->esVacio())
		{
			return this->der->adicionar(raiz, hijo);
		}

		return add;
	};

	bool eliminar(T* raiz)
	{
		if ((*this->raiz) == (*raiz))
		{
			delete this->raiz;
			delete this->izq;
			delete this->der;

			this->raiz = NULL;
			this->izq = NULL;
			this->der = NULL;

			return true;
		}

		bool rem =  !this->izq->esVacio() ? this->izq->eliminar(raiz) : false;
		if (!rem && !this->der->esVacio())
		{
			return this->der->eliminar(raiz);
		}

		return rem;
	}

	int gradp()
	{
		return 2;
	}

	int cantHojas()
	{
		if (esHoja())
		{
			return 1;
		}

		int cantIzq = !this->izq->esVacio() ? this->izq->cantHojas() : 0;
		int cantDer = !this->der->esVacio() ? this->der->cantHojas() : 0;

		return cantIzq + cantDer;
	}

	int altura()
	{
		if (esHoja())
		{
			return 0;
		}

		int altIzq = !this->izq->esVacio() ? this->izq->altura() : 0;
		int altDer = !this->der->esVacio() ? this->der->altura() : 0;

		return altIzq > altDer ? altIzq + 1 : altDer + 1;
	};

	bool esVacio()
	{
		return this->raiz == NULL;
	};

	bool esHoja()
	{
		return this->izq->esVacio() && this->de->esVacio();
	};

	// CLASE PRACTICA

	T* getHijoMasIqz()
	{
		return this->izq->esVacio() ? this->raiz : this->izq->getHijoMasIqz();
	};

	T* getHijoMasDer()
	{
		return this->der->esVacio() ? this->raiz : this->der->getHijoMasDer();
	};

	void invertir()
	{
		if (!this->esHoja() && !this->esVacio())
		{
			ArbolBinario<T>* temp = this->der;
			this->der = this->izq;
			this->izq = temp;

			this->izq->invertir();
			this->der->invertir();
		}
	};

	int getSubArbolesConUnDescendiente()
	{
		if (esHoja())
		{
			return 0;
		}

		int cont = 0;
		if (this->izq->esVacio() && !this->der->esVacio())
		{
			cont++;
		}
		else if (!this->izq->esVacio() && this->der->esVacio())
		{
			cont++;
		}

		// CONDICION ? I1 : I2

		return cont + !this->izq->esVacio() ? this->izq->getSubArbolesConUnDescendiente() : 0
					+ !this->der->esVacio() ? this->der->getSubArbolesConUnDescendiente() : 0;
	};

	int getSubArbolesConDosDescendientes()
	{
		if (esHoja())
		{
			return 0;
		}

		int cont = 0;
		if (!this->izq->esVacio() && !this->der->esVacio())
		{
			cont++;
		}

		return cont + !this->izq->esVacio() ? this->izq->getSubArbolesConDosDescendientes() : 0
					+ !this->der->esVacio() ? this->der->getSubArbolesConDosDescendientes() : 0;
	};
};


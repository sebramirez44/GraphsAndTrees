#include "NodoSE.h"
#include "PilaSE.h"
#include "ColaSE.h"
#include <iostream>
using namespace std;

class ClasePractica_PIlaCola_2
{
public:
	ClasePractica_PIlaCola_2()
	{
	
	}

	~ClasePractica_PIlaCola_2()
	{
	
	}

	PilaSE<int>* reemplazar(PilaSE<int>* pila, int x, int y)
	{
		PilaSE<int>* pilaAux = new PilaSE<int>();
		while (!pila->isEmpty())
		{
			int* valor = pila->pop();
			if ((*valor) == x)
			{
				pilaAux->push(&y);
			}
			else
			{
				pilaAux->push(valor);
			}
		}

		while (!pilaAux->isEmpty())
		{
			pila->push(pilaAux->pop());
		}
		
		return pila;
	}

	ColaSE<std::string>* delete_valores(ColaSE<std::string>* cola, std::string cad)
	{
		ColaSE<std::string>* aux = new ColaSE<std::string>();
		while (!cola->isEmpty())
		{
			std::string* valor = cola->remove();
			if ((*valor) != cad)
			{
				aux->add(valor);
			}
		}
		return aux;
	}

	PilaSE<int>* eliminarCentro(PilaSE<int>* pila)
	{
		int cont = 0;
		PilaSE<int>* aux = new PilaSE<int>();
		while (!pila->isEmpty())
		{
			aux->push(pila->pop());
			cont++;
		}

		bool par = cont % 2 == 0;
		int centro = cont / 2;
		cont = 0;

		while (!aux->isEmpty())
		{
			if (cont == centro)
			{
				aux->pop();
				if (par)
				{
					pila->pop();
				}
				cont += 2;
			}
			else
			{
				pila->push(aux->pop());
				cont++;
			}
		}

		return pila;
	}
};


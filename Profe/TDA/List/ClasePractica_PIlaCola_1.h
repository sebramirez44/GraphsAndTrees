#pragma once
#include "NodoSE.h"
#include "PilaSE.h"
#include "ColaSE.h"
#include <iostream>
using namespace std;

class ClasePractica_PIlaCola_1
{
public:
	ClasePractica_PIlaCola_1()
	{
	
	}

	~ClasePractica_PIlaCola_1()
	{
	
	}

	char* invertirEntreAyB(char* cadena, int lenght)
	{
		char* nuevoArr = new char[lenght];
		PilaSE<char>* pila = new PilaSE<char>();

		for (int i = 0; i < lenght; i++)
		{
			if (cadena[i] == 'a' || cadena[i] == 'A')
			{
				pila->push(&cadena[i]);

				for (int j = i + 1; j < lenght; j++)
				{
					if (cadena[j] == 'b' || cadena[j] == 'B')
					{
						nuevoArr[i++] = cadena[j];
						while (!pila->isEmpty())
						{
							nuevoArr[i++] = (*pila->pop());
						}
						i--;
						break;
					}
					else
					{
						pila->push(&cadena[j]);
					}
				}

				if (!pila->isEmpty())
				{
					PilaSE<char>* pila1 = new PilaSE<char>();
					while (!pila->isEmpty())
					{
						pila1->push(pila->pop());
					}
					while (!pila1->isEmpty())
					{
						nuevoArr[i++] = (*pila1->pop());
					}
				}
			}
			else
			{
				nuevoArr[i] = cadena[i];
			}
		}

		return nuevoArr;
	}

	ColaSE<int>* mezclar(ColaSE<int>* c1, ColaSE<int>* c2)
	{
		ColaSE<int>* aux = new ColaSE<int>();
		while (!c1->isEmpty() && !c2->isEmpty())
		{
			int* top1 = c1->top();
			int* top2 = c2->top();

			if ((*top1) < (*top2))
			{
				aux->add(c1->remove());
			}
			else
			{
				aux->add(c2->remove());
			}
		}

		while (!c1->isEmpty())
		{
			aux->add(c1->remove());
		}

		while (!c2->isEmpty())
		{
			aux->add(c2->remove());
		}

		return aux;
	}

	PilaSE<int>* mezclar(PilaSE<int>* p1, PilaSE<int>* p2)
	{
		PilaSE<int>* aux = new PilaSE<int>();
		while ( !p1->isEmpty() && !p2->isEmpty() )
		{
			int* top1 = p1->top();
			int* top2 = p2->top();

			if ((*top1) < (*top2))
			{
				aux->push(p1->pop());
			}
			else
			{
				aux->push(p2->pop());
			}
		}

		while (!p1->isEmpty())
		{
			aux->push(p1->pop());
		}
				
		while (!p2->isEmpty())
		{
			aux->push(p2->pop());
		}

		PilaSE<int>* aux1 = new PilaSE<int>();
		while (!aux->isEmpty())
		{
			aux1->push(aux->pop());
		}

		return aux1;
	}
};


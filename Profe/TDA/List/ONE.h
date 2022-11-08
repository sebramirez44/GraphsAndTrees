#pragma once
#include <iostream>
#include <string>
#include "List.h"
#include "ListSE.h"
#include "Persona.h"
#include "Estado.h"

class ONE
{
private:
	List<Persona>* personas;

public:
	ONE()
	{
		this->personas = new ListSE<Persona>();
	}

	~ONE()
	{
		delete this->personas;
	}

	void adicionarPersonas(Persona* persona)
	{
		this->personas->add(persona);
	}

	int cantidadDeMujeres()
	{
		int cont = 0;
		for (int i = 0; i < this->personas->getLength(); i++)
		{
			Persona* persona1 = this->personas->getElement(i);
			if (persona1->getSexo() == 'm')
			{
				cont++;
			}
		}
		return cont;
	}

	Persona* getHombreMasJoven()
	{
		Persona* persona = NULL;
		for (int i = 0; i < this->personas->getLength(); i++)
		{
			Persona* tyu = this->personas->getElement(i);
			if (tyu->getSexo() == 'h' && (persona == NULL || tyu->getEdad() < persona->getEdad() ) )
			{
				persona = tyu;
			}
		}

		return persona;
	}

	Estado* getEstadoMayorCantPersonas()
	{
		ListSE<Estado>* estados = new ListSE<Estado>();
		for (int i = 0; i < this->personas->getLength(); i++)
		{
			bool esta = false;
			Persona* persona = this->personas->getElement(i);

			for (int j = 0; j < estados->getLength(); j++)
			{
				Estado* estado = estados->getElement(j);

				if (estado->getEstado() == persona->getEstado())
				{
					esta = true;
					estado->setCantHab(estado->getCantHab() + 1);
					break;
				}
			}

			if (!esta)
			{
				Estado* estado = new Estado(persona->getEstado());
				estado->setCantHab(1);
				estados->add(estado);
			}
		}

		if (!estados->isEmpty())
		{
			Estado* estadoMayor = estados->getElement(0);
			for (int i = 1; i < estados->getLength(); i++)
			{
				Estado* aux = estados->getElement(i);
				if (aux->getCantHab() > estadoMayor->getCantHab())
				{
					estadoMayor = aux;
				}
			}
			return estadoMayor;
		}

		return NULL;
	}

	bool estaEnvejecida()
	{
		int personasmas60 = 0;
		for (int i = 0; i < this->personas->getLength(); i++)
		{
			Persona* persona = this->personas->getElement(i);
			if (persona->getEdad() >= 60)
			{
				personasmas60++;
			}
		}

		return ((float)personasmas60 / this->personas->getLength()) >= 0.33;
	}
};


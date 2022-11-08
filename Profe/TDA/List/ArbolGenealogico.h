#pragma once
#include "ListSE.h"
#include "ArbolGeneral.h"
#include "Persona.h"
#include <iostream>
using namespace std;

class ArbolGenealogico
{
protected:

	Persona* persona;
	ListSE<ArbolGenealogico>* descedientes;

public:

	ArbolGenealogico(Persona* persona)
	{
		this->persona = persona;
		this->descedientes = new ListSE<ArbolGenealogico>();
	};

	~ArbolGenealogico()
	{
	
	};

	ListSE<std::string>* personaConUnColorDeOjos(std::string color)
	{
		ListSE<std::string>* lista = new ListSE<std::string>();
		personaConUnColorDeOjos(color, lista);
		return lista;
	};

protected:

	void personaConUnColorDeOjos(std::string color, ListSE<std::string>* lista)
	{
		if (this->persona->getColorOjos() == color)
		{
			lista->add(&this->persona->getNombre());
		}

		for (int i = 0; i < this->descedientes->getLength(); i++)
		{
			ArbolGenealogico* arbol = this->descedientes->getElement(i);
			arbol->personaConUnColorDeOjos(color, lista);
		}
	}
};


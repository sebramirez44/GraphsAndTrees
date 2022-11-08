#pragma once
#include <iostream>
#include <string>

class Persona
{
private:
	std::string nombre;
	std::string apellido;
	int edad;
	char sexo;
	std::string estado;
	std::string colorOjos;

public:
	Persona(std::string nombre, std::string apellido, int edad, char sexo, std::string estado, std::string colorOjos)
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->sexo = sexo;
		this->estado = estado;
		this->colorOjos = colorOjos;
	}

	std::string getNombre()
	{
		return this->nombre;
	}

	std::string getApellido()
	{
		return this->apellido;
	}

	int getEdad()
	{
		return this->edad;
	}

	char getSexo()
	{
		return this->sexo;
	}

	std::string getEstado()
	{
		return this->estado;
	}

	std::string getColorOjos()
	{
		return this->colorOjos;
	}
};


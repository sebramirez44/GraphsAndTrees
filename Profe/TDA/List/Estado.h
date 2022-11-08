#pragma once
#include <iostream>
#include <string>

class Estado
{
private:
	std::string estado;
	int cantHab;

public:
	Estado(std::string estado)
	{
		this->estado = estado;
		this->cantHab = cantHab;
	}

	std::string getEstado()
	{
		return this->estado;
	}

	int getCantHab()
	{
		return this->cantHab;
	}

	void setCantHab(int cantHab)
	{
		this->cantHab = cantHab;
	}
};


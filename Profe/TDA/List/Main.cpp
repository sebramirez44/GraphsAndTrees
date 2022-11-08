// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "List.h"
#include "ArrayList.h"
#include "StaticArrayList.h"
#include "DynamicArrayList.h"
#include "ClasePractica_PIlaCola_1.h"
#include "ClasePractica_PIlaCola_2.h"
#include "ListSE.h"
#include "ListSEC.h"
#include "ONE.h"
#include "Persona.h"
#include "ArbolGeneral.h"
#include <iostream>

int main()
{
    std::cout << "Hello TDA!\n"; 
	ArbolGeneral<int>* arbol = new ArbolGeneral<int>(new int(5));
	arbol->addicionarPrimeraOcurrencia(new int(5), new int(6));
	arbol->addicionarPrimeraOcurrencia(new int(5), new int(7));
	arbol->addicionarPrimeraOcurrencia(new int(5), new int(8));

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

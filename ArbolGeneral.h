#pragma once
#include "ListSE.h"
#include <iostream>
using namespace std;
//Clase definiendo los nodos de un arbol.
template<class T> class ArbolGeneral{
protected:
    T* dato;
    ListSE<ArbolGeneral<T>*>* hijos;

public:
    ArbolGeneral(T* dato){
        this->dato = dato;
        this->hijos = new listSE<ArbolGeneral<T>>*();
    };
    ~ArbolGeneral(){
        
    };
    T* getRaiz(){
        return this->dato;
    };
    bool esHoja(){
        return this->hijos->getLength() == 0;
    };
    int getGrado(){
        return this->hijos->getLength();
    };
    int getAltura(){ //funcion recursiva
        if (esHoja()){ //caso base
            return 0;
        }
        int altura = -1; //-1 porque necesitamos buscar el mayor, todos los otros elementos seran mayores a -1 es como do while digamos.
        for (int i = 0; i<this->hijos->getLength();i++){
            int altura_aux = this->hijos->getElement(i)->getAltura();
            if (altura_aux > altura){
                altura = altura_aux;
            }
        }
        return altura+1;

    };

    void adicionarParaTodaOcurrencia(T* raiz, T* hijo){
        if ((*this->dato) == (*raiz)){
            this->hijos->add(new ArbolGeneral<T>(hijo));
        }
        for (int i = 0; i < this->hijos->getLength(); i++){
            this->hijos->getElement(i)->adicionar(raiz,hijo);
        }
    };
    bool adicionarPrimeraOcurrencia(T* raiz, T* hijo){
        if ((*this->dato) == (*raiz)){
            this->hijos->add(new ArbolGeneral<T>(hijo));
            return true;
        }
        for (int i = 0; i< this->hijos->getLength(); i++){
            if (this->hijos->getElement(i)->adicionarPrimeraOcurrencia(raiz,hijo)){
                return true;
            }
        }
        return false;
    };
    int getCantHojas(){
        if (esHoja()){
            return 1;
        }
        int cantHojas = 0;
        for (int i = 0; i < this->hijos->getLength();i++){
            cantHojas = cantHojas + this->hijos->getElement(i)->getCantHojas(); //si es hoja va a ser uno y se va a sumar e ir sumando
        }
        return cantHojas;
    };

};

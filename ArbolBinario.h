#pragma once
#include <iostream>
using namespace std;

template<class T> class ArbolBinario{
protected:
    T* raiz;
    ArbolBinario<T>* izq;
    ArbolBinario<T>* der;
public:
    ArbolBinario(){
        this->raiz = NULL;
        this->izq = NULL;
        this->der = NULL;
    };
    ArbolBinario(T* dato){
        this->raiz = dato;
        this->izq = new ArbolBinario<T>();
        this->der = new ArbolBinario<T>();
    };
    ~ArbolBinario(){

    };
    int altura(){

      };
    bool esVacio(){
        return this->raiz == NULL;
    };
    bool esHojas(){
        return this->izq == NULL && this->der == NULL;
    };
};
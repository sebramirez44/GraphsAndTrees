#pragma once
#include <iostream>
using namespace std;
template<class T> class NodoSE{
    protected:
        T* valor;
        NodoSE<T>* siguiente;
    public:
        NodoSE(T* valor){ //Complejidad: O(1)
            this->valor = valor;
        }
        ~NodoSE(){ //Complejidad: O(1)
            delete valor;
        }
        inline T* getValor(){ //Complejidad: O(1)
            return this->valor;
        }
        inline void setValor(T* valor){ //Complejidad: O(1)
            this->valor = valor;
        }
        inline NodoSE<T>* getSiguiente(){ //Complejidad: O(1)
            return this->siguiente;
        }

        inline void setSiguiente(NodoSE<T>* siguiente){ //Complejidad: O(1)
            this->siguiente = siguiente;
        }


        

};//Complejidad total: O(1)
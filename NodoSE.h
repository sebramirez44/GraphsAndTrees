#pragma once
#include <iostream>
using namespace std;
template<class T> class NodoDE{
    protected:
        T* valor;
        NodoDE<T>* siguiente;
    public:
        NodoDE(T* valor){ //Complejidad: O(1)
            this->valor = valor;
        }
        ~NodoDE(){ //Complejidad: O(1)
            delete valor;
        }
        inline T* getValor(){ //Complejidad: O(1)
            return this->valor;
        }
        inline void setValor(T* valor){ //Complejidad: O(1)
            this->valor = valor;
        }
        inline NodoDE<T>* getSiguiente(){ //Complejidad: O(1)
            return this->siguiente;
        }

        inline void setSiguiente(NodoDE<T>* siguiente){ //Complejidad: O(1)
            this->siguiente = siguiente;
        }


        

};//Complejidad total: O(1)
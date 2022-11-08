#pragma once
#include <iostream>
using namespace std;
template<class T> class ABB{
protected:
    T* raiz;
    ABB<T>* izq;
    ABB<T>* der;
public:
    ABB(){
        this->raiz = NULL;
        this->izq = NULL;
        this->der = NULL;
    };
    ABB(T* dato){
        this->raiz = dato;
        this->izq = new ABB<T>();
        this->der = new ABB<T>();

    };
    ~ABB(){

    };
    T* getRaiz(){
        return this->raiz;
    };
    bool adicionar(T* dato){
        if(esVacio()){
            this->raiz = dato;
            this->izq = new ABB<T>();
            this->der = new ABB<T>();
            return true;
        }
        if ((*this->raiz) == (*dato)){ //retornamos falso porque el elemento ya esta en el arbol
            return false;
        }
        if ((*dato) < (*this->raiz)){ //si es menor al dato lo ponemos en la izquierda.
            return this->izq->adicionar(dato);
            // return false;
        }
        else {
            return this->der->adicionar(dato);
            // return false;
        }
        return false;

    };//cambiar para BST
    bool eliminar(T* raiz)
	{
		if ((*this->raiz) == (*raiz))
		{
			delete this->raiz;
			delete this->izq;
			delete this->der;

			this->raiz = NULL;
			this->izq = NULL;
			this->der = NULL;

			return true;
		}

		bool rem =  !this->izq->esVacio() ? this->izq->eliminar(raiz) : false;
		if (!rem && !this->der->esVacio())
		{
			return this->der->eliminar(raiz);
		}

		return rem;
	};
    int cantHojas()
	{
		if (esHoja())
		{
			return 1;
		}

		int cantIzq = !this->izq->esVacio() ? this->izq->cantHojas() : 0;
		int cantDer = !this->der->esVacio() ? this->der->cantHojas() : 0;

		return cantIzq + cantDer;
	}
    int altura()
	{
		if (esHoja())
		{
			return 0;
		}

		int altIzq = !this->izq->esVacio() ? this->izq->altura() : 0;
		int altDer = !this->der->esVacio() ? this->der->altura() : 0;

		return altIzq > altDer ? altIzq + 1 : altDer + 1;
	};

	bool esVacio()
	{
		return this->raiz == NULL;
	};

	bool esHoja()
	{
		return this->izq->esVacio() && this->der->esVacio();
	};

	// CLASE PRACTICA

	T* getHijoMasIzq()
	{

		return this->izq->esVacio() ? this->raiz : this->izq->getHijoMasIzq();
	};

	T* getHijoMasDer()
	{
		return this->der->esVacio() ? this->raiz : this->der->getHijoMasDer();
	};
    void printEnOrden(ABB<T>* dato){
		if (dato == NULL || dato == 0){
			return;
		}
		
		if (dato == *this->raiz->getHijoMasDer()){
		 	std::cout << "no se lol" << std::endl;
		 	return;
		}
		
		printEnOrden(this->izq);
		std::cout << *dato->getRaiz() << std::endl;
		if (this->der != NULL){
			printEnOrden(this->der);
		}
		
    }
    int getSubArbolesConUnDescendiente()
	{
		if (esHoja())
		{
			return 0;
		}

		int cont = 0;
		if (this->izq->esVacio() && !this->der->esVacio())
		{
			cont++;
		}
		else if (!this->izq->esVacio() && this->der->esVacio())
		{
			cont++;
		}

		// CONDICION ? I1 : I2

		return cont + !this->izq->esVacio() ? this->izq->getSubArbolesConUnDescendiente() : 0
					+ !this->der->esVacio() ? this->der->getSubArbolesConUnDescendiente() : 0;
	};

	int getSubArbolesConDosDescendientes()
	{
		if (esHoja())
		{
			return 0;
		}

		int cont = 0;
		if (!this->izq->esVacio() && !this->der->esVacio())
		{
			cont++;
		}

		return cont + !this->izq->esVacio() ? this->izq->getSubArbolesConDosDescendientes() : 0
					+ !this->der->esVacio() ? this->der->getSubArbolesConDosDescendientes() : 0;
	};

};


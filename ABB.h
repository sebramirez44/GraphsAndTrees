#pragma once
#include "ListDE.h"
#include <iostream>


using namespace std;

template<class T> class ListDE;
template<class T> class ABB : public ListDE<T>{
protected:
	string valor;
    T* raiz;
    ABB<T>* izq;
    ABB<T>* der;
	int count = 0;

public:
    ABB(){
        this->raiz = NULL;
        this->izq = NULL;
        this->der = NULL;
    };
    ABB(T* dato){
        this->raiz = dato;
        this->izq = NULL;
        this->der = NULL;

    };
	ABB(T* dato, string valor){
		this->raiz = dato;
		this->izq = NULL;
		this->der = NULL;
		this->valor = valor;
	}
    ~ABB(){

    };
    T* getRaiz(){
        return this->raiz;
    };
	bool adicionar(T* dato, string valor){
        if(esVacio()){
            this->raiz = dato;
            this->izq = NULL;
            this->der = NULL;
			this->valor = valor;

            return true;
		}
        if ((*dato) < (*this->raiz)){ //si es menor al dato lo ponemos en la izquierda.
			if (this->izq == NULL){
				this->izq = new ABB<T>(dato);
				return true;
			}
            return this->izq->adicionar(dato);
            // return false;
        }
        else {
			if (this->der == NULL){
				this->der = new ABB<T>(dato);
				return true;
			}
            return this->der->adicionar(dato);
            // return false;
        }
        return false;

    };//cambiar para BST

    bool adicionar(T* dato){
        if(esVacio()){
            this->raiz = dato;
            this->izq = NULL;
            this->der = NULL;

            return true;
        }
	
        if ((*dato) < (*this->raiz)){ //si es menor al dato lo ponemos en la izquierda.
			if (this->izq == NULL){
				this->izq = new ABB<T>(dato);
				return true;
			}
            return this->izq->adicionar(dato);
            // return false;
        }
        else {
			if (this->der == NULL){
				this->der = new ABB<T>(dato);
				return true;
			}
            return this->der->adicionar(dato);
            // return false;
        }
        return false;
	};
		
	

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
	ABB<T>* getHijoIzq(){
		return this->izq;
	}

	T* getHijoMasDer()
	{
		return this->der->esVacio() ? this->raiz : this->der->getHijoMasDer();
	};
	void printEnOrdenOne(ABB<T>* arbol){
		if (arbol !=NULL) {
			printEnOrdenOne(arbol->izq);
			cout << *arbol->getRaiz() << endl;
			printEnOrdenOne(arbol->der);
		}	
	}
    
    
	void printPosOrden(ABB<T>* dato){
		if (dato != NULL){
			printPosOrden(dato->izq);
			printPosOrden(dato->der);
			cout << *dato->getRaiz() << endl;
		}
	}

	void printPreOrden(ABB<T>* dato){
		if (dato != NULL){
			cout << *dato->getRaiz() << endl;
			printPreOrden(dato->izq);
			printPreOrden(dato->der);
		}
	}
	void primeros(ABB<T>* dato){
		if (dato != NULL && count < 5){
			cout << *dato->getRaiz() << endl;
			this->count++;
			primeros(dato->izq);
			primeros(dato->der);
		}
	};

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
	string getValor(){
		return this->valor;
	};
	void setValor(string valor){
		this->valor = valor;
	};
	ABB<T>* sortAll(ListDE<string>* list){
		    int cantidad = list->getPosition(list->cola->getValor()); //mas uno porque posicion en cola incluye 0
            NodoDE<string>* temp = list->cabeza;
            ABB<T>* sorted = new ABB<T>;
            while(temp!=list->cola && temp->getSiguiente() != NULL){
                string* Element = temp->getValor();
                int* veces = new int(list->find(Element));
                //meter a cada uno a un ABB
                sorted->adicionar(veces, *Element);

                for (int i = 0; i < *veces; i++){
                    // cout << "Elemento a borrar: " << *Element << endl;
                    // cout << cantidad << endl;

                    list->remove(Element);
                }
                temp = temp->getSiguiente();
            }
			return sorted;
	};
	ABB<T>* sortNetwork(ListDE<string>* list){
		NodoDE<string>* temp = list->cabeza;
		ABB<T>* sort = new ABB<T>;
		while(temp!=list->cola && temp->getSiguiente() != NULL){
			string* Element = temp->getValor();
			string sub = *temp->getValor();
			sub = sub.substr(0,3);
			int veces = list->findNet(Element);
			// sort->adicionar(veces, sub);
			temp = temp->getSiguiente();
			cout << veces << endl;
		}

		return sort;

	}
	

};
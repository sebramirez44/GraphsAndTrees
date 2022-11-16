#pragma once
#include "ListDE.h"
#include "ColaSE.h"
#include <iostream>
using namespace std;

template<class T> class ABB : public ListDE<T>{
protected:
    T* raiz;
    ABB<T>* izq;
    ABB<T>* der;

public:
    ABB(){ //constructor, incializamos todo a NULL porque era mas facil para adicion y busqueda
        this->raiz = NULL;
        this->izq = NULL;
        this->der = NULL;
    };
	ABB(T* dato){ //constructor con raiz
		this->raiz = dato;
		this->izq = NULL;
		this->der = NULL;
	}
    ~ABB(){

    };
    T* getRaiz(){ //funcion para obtener raiz de un arbol
        return this->raiz;
    };
	bool adicionar(T* dato){ //funcion apra adicionar un elemento al arbol, O(log(n))
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
            return this->izq->adicionar(dato); //si hay un arbol en la izquierda se hace recursion con ese arbol.
        }
        else {
			if (this->der == NULL){ //si es mayor y no hay nada en la derecha se agrega
				this->der = new ABB<T>(dato);
				return true;
			}
            return this->der->adicionar(dato); //si hay un arbol en la derecha, recursion con ese arbol
        }
        return false;

    };


	

    bool eliminar(T* raiz) //funcion para eliminar un arbol
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
	
    int cantHojas() //funcion para revisar la cantidad de hojas de un arbol binario.
	{
		if (esHoja())
		{
			return 1;
		}

		int cantIzq = !this->izq->esVacio() ? this->izq->cantHojas() : 0;
		int cantDer = !this->der->esVacio() ? this->der->cantHojas() : 0;

		return cantIzq + cantDer;
	};
    
	
	int height(){ //funcion par aobtener la altura del arbol O(log(n))
		int heightLeft = 0;
		int heightRight = 0;
		int heightRaiz = 0;
		if(this->raiz == NULL){ //caso nbase de la recursion.

			return -1;
		}
		if (this->izq != NULL){ //revisamos que izquierda no sea null para poder hacer un metodo de este.
			heightLeft = this->izq->height(); //hacemos el metodo recursivamente.
		}
		else{
			heightLeft = -1; 
		}
		if (this->der != NULL){  //checamos que le nodo de la derecha no este vacio para hacer un metodo.
			heightRight = this->der->height(); //hacemos este metodo revursivamente co el nodo de la derecha.
		}
		else{ 
			heightRight = -1;
		}
		if (heightLeft > heightRight){ //asignamos la raiz mayor a la altura total qu enombre heightRaiz
			heightRaiz = heightLeft + 1;
		}
		else if (heightLeft < heightRight){ 
			heightRaiz = heightRight + 1;
		}
		else{ //si ambos son iguales, simplemenete utilizamos el nivel de la derecha. 
			heightRaiz = heightRight + 1;
		}
		
		return heightRaiz;	
		
	};
	void ancestros(T* dato){ //O(log(n)) las colas son constantes porque no son todo el arbol, solo el nivel
		//declaramos variables que utilizaremos, no use recursividad
		//porque es mas facil estar al tanto del calor de cola de esta forma.
		ColaSE<T>* cola = new ColaSE<T>;
		ColaSE<T>* nuevaCola = new ColaSE<T>;
		ABB<T>* arbol = new ABB<T>(this->raiz);
		//primero hice un camino por el que pasa agregando cada padre a la cola, despues los reverti.
		arbol->izq = this->izq;
		arbol->der = this->der; //declaramos un nuevo arbol que utilizaremos para hacer "recursividad"
		cola->add(arbol->getRaiz());
		while (*arbol->getRaiz() != *dato){
			
			if (*dato > *arbol->getRaiz()){
				if (*cola->top() != *arbol->getRaiz()){ //si el elemento en cola no es igual que raiz, lo agregamos raiz a la cola.
					cola->add(arbol->getRaiz()); 
				}
				arbol = arbol->der; //cambiamos el arbol en el que trabajamos al arbol de la derecha porque el dato era mayor que la raiz asi que esta a la derecha.
			}
			else if (*dato < *arbol->getRaiz()){  //hacemos lo mismo pero con la izquierda
				if (*cola->top() != *arbol->getRaiz()){
					cola->add(arbol->getRaiz());
				}
				arbol = arbol->izq;
			}
		}
		while (!cola->isEmpty()){ //cambiamos la cola a otra cola nueva para cambiar el orden de los elementos.
			nuevaCola->add(cola->top());
			cola->remove();
		}
		while (!nuevaCola->isEmpty()){
			cout << *nuevaCola->top() << " "; //imprimimos la nueva cola para mostrar los ancestros.
			nuevaCola->remove();
		}
		return;

	};
	int whatlevelamI(T* dato){ //O(log(n))
		ABB<T>* arbol = new ABB<T>(this->raiz);
		arbol->izq = this->izq;
		arbol->der = this->der;
		int nivel = 0;
		while(*arbol->getRaiz() != *dato){ //la funcion busca el dato en el arbol y por cada nivel que baja
			if(*dato > *arbol->getRaiz()){ //se agrega 1 a count, de esta forma nos da su nivel.
				arbol = arbol->der;
				nivel++;
			}
			else if(*dato < *arbol->getRaiz()){
				arbol = arbol->izq;
				nivel++;
			}
		}
		return nivel;
	};

	bool esVacio()
	{
		return this->raiz == NULL;
	};

	bool esHoja()
	{
		ABB<T>* arbol = new ABB<T>(this->raiz);
		arbol->izq = this->izq;
		arbol->der = this->der;
		if (arbol != NULL){
			return arbol->izq->esVacio() && arbol->der->esVacio();
		}

		return false;
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
	void visit(int seleccion){ //funcion para imprimir el arbol O(n)
		//crear arbol aqui y usarlo como parametro en cada funcion.
		ABB<T>* arbol = new ABB<T>(this->raiz);
		arbol->izq = this->izq;
		arbol->der = this->der;
		switch (seleccion){
			case 1:
				printPreOrden(arbol);
				break;
			case 2:
				printEnOrden(arbol);
				break;
			case 3:
				printPosOrden(arbol);
				break;
			case 4:
				printLevelbyLevel(arbol);
				break;
			default:
				cout << "argumento invlido" << endl;
				break;	
		}
	};
	
	void printLevelbyLevel(ABB<T>* arbol){ //funcion que imprime el arbol en orden de nivel a nivel. O(n)
		ColaSE<ABB>* cola = new ColaSE<ABB>;
		cola->add(arbol);
		while(!cola->isEmpty()){
			arbol = cola->top();
			cola->remove();
			cout << *arbol->getRaiz() << " ";
			if (arbol->izq != NULL){
				cola->add(arbol->izq);
			}
			if(arbol->der != NULL){
				cola->add(arbol->der);
			}
		}

	};

	void printEnOrden(ABB<T>* arbol){ //funcion que imprime el arbol en orden. O(n)
		if (arbol !=NULL) {
			printEnOrden(arbol->izq);
			cout << *arbol->getRaiz() << " ";
			printEnOrden(arbol->der);
		}
	};
	
    
    
	void printPosOrden(ABB<T>* arbol){ //funcion que imprime el arbol en posorden O(n)
		if (arbol != NULL){
			printPosOrden(arbol->izq);
			printPosOrden(arbol->der);
			cout << *arbol->getRaiz() << " ";
		}
	};

	void printPreOrden(ABB<T>* arbol){ //funcion que imprime el arbol en preorden O(n)
		if (arbol != NULL){
			cout << *arbol->getRaiz() << " ";
			printPreOrden(arbol->izq);
			printPreOrden(arbol->der);
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


};

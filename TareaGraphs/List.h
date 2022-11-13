//pragma once se usa para remplazar header guard
#pragma once
#include <iostream>
using namespace std;

template<class T> class List{
    //protected puede ser accesado por subclases y private no
    protected:
        int length;
    public:
        //constructor
        List(int length){
            this->length = length;//Complejidad O(1)
        };
        inline int getLength(){
            return length; //Complejidad O(1)
        };
        inline bool isEmpty(){
            return length == 0; //Complejidad O(1)
        };
        
        virtual void add(T* element) = 0;
        virtual void insert(T* element, int pos) = 0;
        virtual void remove(T* element) = 0;
        virtual void remove(int pos) = 0;
        virtual T* getElement(int pos) = 0;
        virtual int getPosition(T* element) = 0;
}; //Complejidad total: O(1)
//TDA LISTA
//COLECCION DE ELEMENTOS DEL MISMO TIPO
//Constructor
//Adicionar(tipo X)
//Insertar (Tipo X, Entero)
//Obtener(Entero i) : Tipo
//Eliminar (Entero i)
//Bucar (Tipo X) : Entero
//Vacia() : Logico
//Obtener (Entero i)
//Obtienes el elemento en la posicion i
//Eliminar (Entero i)
//Eliminar el elemento en la poicion i
//Buscar (Tipo x): Entero
//Buscar(7) Busca donde se encuentra el numero 7 en la lista de ints y te da su posicion i
//vacia devuelve verdadero o falso si la lista esta vacia o no.
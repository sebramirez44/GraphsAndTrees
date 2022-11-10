#pragma once
#include "List.h"
#include "NodoDE.h"
#include "ABB.h"

#include <iostream>
template<class T> class ABB;
template<class T> class ListDE : public List<T>{
    protected:
        
    public:
        //creo que es por las templates, pero no me dejaba accesar
        //estos atributos desde la otra clase aunque tengan herencia
        NodoDE<T>* cabeza;
        NodoDE<T>* cola;
        
        ListDE() : List<T>(0){
            this->cabeza = NULL;
            this->cola = NULL;
        }
        ~ListDE(){
            //Borrar todos los elementos de la lista
            for (int i=0; i<this->length-1;i++){ //Complejidad: O(n)
                NodoDE<T>* rem = this->cola;
                this->cola = this->cola->getPrevio();
                delete rem;
            }
        }
        
        void add (T* element){ //Complejidad: O(1)
            NodoDE<T>* nuevo = new NodoDE<T>(element);
            if(this->cabeza == NULL){
                this->cabeza = nuevo;
            }
            else if (this->cabeza != NULL && this->cola == NULL){
                this->cola = nuevo;
                cabeza->setSiguiente(cola);
                cola->setPrevio(cabeza);
            }
            else{
                cola->setSiguiente(nuevo);
                nuevo->setPrevio(cola);
                this->cola = nuevo;
            }
            this->length++;
        }
        void insert(T* element, int pos){ //Coplejidad: O(n/2)
            if (pos < 0 || pos >= this->length){
                throw "No se puede insertar el elemento porque la posicion es incorrecta";
            }
            NodoDE<T>* nuevo = new NodoDE<T>(element);
            NodoDE<T>* temp = this->cabeza;
            if(pos == 0){
                temp = cabeza->getSiguiente();
                nuevo->setSiguiente(cabeza);
                temp->setPrevio(cabeza);
                cabeza = nuevo;
            }
            else{
                
                if(pos <= this->length/2){
                    NodoDE<T>* temp = this->cabeza;
                    //pos es la posicion donde quiero insertar
                    int posTemp = 0;
                    while(posTemp < pos-1){
                        temp = temp->getSiguiente();
                        posTemp++;
                    }
                    //linkeas nuevo con el siguiente elemento de la lista y linkeas el anterior
                    //a nuevo con temp para insertarlo a la lista.
                    nuevo->setSiguiente(temp->getSiguiente());
                    nuevo->setPrevio(temp->getPrevio());
                    temp->setSiguiente(nuevo);
                    nuevo->setPrevio(temp);
                    
                }
                else if(pos > this->length/2){
                    NodoDE<T>* temp = this->cola;
                    int posTemp = this->length-1;
                    while(posTemp > pos){
                        temp = temp->getPrevio();
                        posTemp--;
                    }                    //cambiar esto
                    nuevo->setPrevio(temp->getPrevio());
                    temp->setPrevio(nuevo);
                    
                }
            }
            this->length++;
        }
        //TODO cambiar esto a O(n/2)
        T* getElement(int pos){ //complejidad: O(n/2)
            if (pos < 0 || pos > this->length){
                throw "Posicion incorrecta";
            }
            else if (pos<=this->length/2){
                int posTemp = 0;
                NodoDE<T>* temp = this->cabeza;
                while (posTemp < pos){
                    temp = temp->getSiguiente();
                    posTemp++;
                }
                return temp->getValor();
            }
            else if (pos > this->length/2){
                
                NodoDE<T>* temp = this->cola;
                int posTempB = this->length;
                while (posTempB >= pos+2){
                    temp = temp->getPrevio();
                    posTempB--;
                }
                return temp->getValor();
            }
            return NULL;


        }
        //esta funcion no funciona con Banco.h por el tipo de dato
        int getPosition(T* element){ //Complejidad: O(n)
            int posTemp = 0;
            NodoDE<T>* temp = this->cabeza;
            while (*temp->getValor() != *element && temp->getSiguiente()!=NULL){ //agregue el &&
                temp = temp->getSiguiente();
                posTemp++;
            }
            return posTemp;
        }
        int find(string* element){
            NodoDE<T>* temp = this->cabeza;
            int count = 0;
                        // remove(getPosition(cola->getValor()));

		    while(temp!=this->cola){
                if (*temp->getValor() == *element){
                    count++;
                }
                
                temp = temp->getSiguiente();
                
            }

            return count;
	    }
        int findNet(string* element){
            NodoDE<T>* temp = this->cabeza;
            int count = 0;
            string elem = *element;
            elem = elem.substr(0,3);
            string valor = *temp->getValor();
            valor = valor.substr(0,3);
            while (temp!=this->cola){
                if(valor == elem){
                    count++;
                }
                temp = temp->getSiguiente();

            }
            return count;
        }
        
        void remove(int pos){ //complejidad: O(n/2)
            if (pos < 0 || pos >= this->length){
                throw "Posicion incorrecta";
            }
            //remove en la primera posicion
            if (pos == 0){
                NodoDE<T>* rem = this->cabeza;
                this->cabeza = this->cabeza->getSiguiente();
                delete rem;
                
            }
            else if (pos == this->length-1){
                NodoDE<T>* rem = this->cola;
                this->cola = this->cola->getPrevio();
                delete rem;
            }
            else if(pos <= this->length/2){
                    int posTemp = 0;
                    NodoDE<T>* rem = this->cabeza;
                    
                    while(posTemp < pos){
                        rem = rem->getSiguiente();
                        posTemp++;
                    }
                    NodoDE<T>* tempPrevio = rem->getPrevio();
                    tempPrevio->setSiguiente(rem->getSiguiente());
                    NodoDE<T>* tempSiguiente = rem->getSiguiente();
                    tempSiguiente->setPrevio(rem->getPrevio());
                    delete rem;
                }
            else if(pos > this->length/2){
                NodoDE<T>* rem = this->cola;
                int posRem = this->length-1;
                while(posRem >= pos){
                    rem = rem->getPrevio();
                    posRem--;
                }
                NodoDE<T>* tempPrevio = rem->getPrevio();
                tempPrevio->setSiguiente(rem->getSiguiente());
                NodoDE<T>* tempSiguiente = rem->getSiguiente();
                tempSiguiente->setPrevio(rem->getPrevio());

                delete rem;
                }

            
            this->length--;
        }
        void printList(){
            NodoDE<T>* temp = this->cabeza;
            while(temp!=cola){
                cout << *temp->getValor() << endl;
                temp = temp->getSiguiente();
            }
            cout << *temp->getValor() << endl;
        }
        void remove(T* element){//complejidad O(n)
            //usar funcion getPosition() y remove(int pos)
            int posicion = getPosition(element); //Eliminar esta seccion para Banco.h
            remove(posicion);
        }
        
	};

//complejidad total: O(n)
#pragma once
#include "List.h"
#include "NodoSE.h"
#include <iostream>
template<class T> class ListSE : public List<T>{
    private:
        NodoSE<T>* cabeza;
        NodoSE<T>* cola;
    public:
        ListSE() : List<T>(0){
            this->cabeza = NULL;
            this->cola = NULL;
        }
        ~ListSE(){
            //Borrar todos los elementos de la lista
            for (int i=0; i<this->length-1;i++){ //Complejidad: O(n)
                NodoSE<T>* rem = this->cola;
                this->cola = this->cola->getPrevio();
                delete rem;
            }
        }
        
        void add (T* element){ //Complejidad: O(1)
            NodoSE<T>* nuevo = new NodoSE<T>(element);
            if(this->cabeza == NULL){
                this->cabeza = nuevo;
            }
            else if (this->cabeza != NULL && this->cola == NULL){
                this->cola = nuevo;
                cabeza->setSiguiente(cola);
            }
            else{
                cola->setSiguiente(nuevo);
                this->cola = nuevo;
            }
            this->length++;
        }
        void insert(T* element, int pos){ //Coplejidad: O(n)
            if (pos < 0 || pos >= this->length){
                throw "No se puede insertar el elemento porque la posicion es incorrecta";
            }
            NodoSE<T>* nuevo = new NodoSE<T>(element);
            NodoSE<T>* temp = this->cabeza;
            if(pos == 0){
                nuevo->setSiguiente(cabeza);
                cabeza = nuevo;
            }
            else{
                
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
                temp->setSiguiente(nuevo);
                
            }
            this->length++;
        }

        T* getElement(int pos){ //complejidad: O(n)
            if (pos < 0 || pos > this->length){
                throw "Posicion incorrecta";
            }
            else {
                int posTemp = 0;
                NodoDE<T>* temp = this->cabeza;
                while (posTemp < pos){
                    temp = temp->getSiguiente();
                    posTemp++;
                }
                return temp->getValor();
            }
            
            return NULL;
        }

        int getPosition(T* element){ //Complejidad: O(n)
            int posTemp = 0;
            NodoDE<T>* temp = this->cabeza;
            while (*temp->getValor() != *element){
                temp = temp->getSiguiente();
                posTemp++;
            }
            return posTemp;
        }
        
        void remove(int pos){ //complejidad: O(n)

            if (pos < 0 || pos >= this->length){
                throw "Posicion incorrecta";
            }
            //remove en la primera posicion
            if (pos == 0){
                NodoSE<T>* rem = this->cabeza;
                this->cabeza = this->cabeza->getSiguiente();
                delete rem;
                
            }

            else{
                    int posTemp = 0;
                    NodoSE<T>* temp = this->cabeza;
                    
                    
                    while(posTemp < pos-1){
                        temp = temp->getSiguiente();
                        posTemp++;
                    }
                    NodoSE<T>* rem = temp->getSiguiente();
                    temp->setSiguiente(rem->getSiguiente());
                    
                    delete rem;
            }

                // algo de aqui causa segfault
            
            this->length--;
        }
        
        void remove(T* element){//complejidad O(n)
            //usar funcion getPosition() y remove(int pos)
            int posicion = getPosition(element); //Eliminar esta seccion para Banco.h
            remove(posicion);
        }

};//complejidad total: O(n)
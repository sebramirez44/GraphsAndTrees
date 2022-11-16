#pragma once
#include "ListDE.h"
#include "ABB.h"
#include <iostream>
#include <string>
using namespace std;
class Hash{
    protected:
    ABB<int>* arbol = new ABB<int>;
    ListDE<string>* value = new ListDE<string>;
    ListDE<int>* keys = new ListDE<int>;
    ListDE<string>* inp = new ListDE<string>;
    public:
    Hash(ABB<int>* arbol, ListDE<string>* inp){
        this->arbol = arbol;
        this->inp = inp;
    }
    void obtener(){
        int key = 0;
        string val;
        for (int i = 0; i < this->inp->getLength(); i++){
            val = *this->inp->getElement(i);
            key = this->inp->contarVeces(new string(val));
            // this->inp->remove(i);
            this->keys->add(new int(key));
            this->value->add(new string(val));
            cout << keys->getLength() << endl;          
        }
    }
    ListDE<int>* getKeys(){
        return this->keys;
    }
    int getLength(){
        return this->keys->getLength();
    }



};
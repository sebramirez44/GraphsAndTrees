#include "ABB.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "caso de prueba 1: " << endl;
    ABB<int>* arbol = new ABB<int>(new int(3));
    arbol->adicionar(new int(2));
    arbol->adicionar(new int(7));
    arbol->adicionar(new int(2));
    ABB<int>* arbolLeft = arbol->getLeft();
    cout << "Arbol visitado en orden: ";
    cout << arbolLeft->getKey();
    cout << endl;
    cout << arbol->getKey() << endl;


    return 0;
}
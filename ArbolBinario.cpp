#include "ABB.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "Hello TDA!\n";
    ABB<int>* arbol = new ABB<int>(new int(5));
    arbol->adicionar(new int(6));
    arbol->adicionar(new int(4));
    int *izq = arbol->getHijoMasIzq();

    // arbol->eliminar(new int(6));
    arbol->printEnOrden(arbol);
    return 0;
}
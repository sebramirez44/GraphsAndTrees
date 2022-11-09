#include "ABB.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "Hello TDA!\n";
    int num = 5;
    ABB<int> arbol(new int(5));
    ABB<int>* arbols = &arbol;
    ABB<int>* test = new ABB<int>(new int(5));
    test->adicionar(new int(2));
    test->adicionar(new int(6));
    test->adicionar(new int(1));
    // test->adicionar(new int(6));
    // test->adicionar(new int(1));
 
    test->printEnOrdenOne(test);
    cout << "cambio a posorden: " << endl;
    test->printPosOrden(test);
    cout << "cambio a preorden: " << endl;
    test->printPreOrden(test);

    // arbol->eliminar(new int(6));
    return 0;
}
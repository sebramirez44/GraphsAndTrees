#include "ABB.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "caso de prueba 1: " << endl;
    ABB<int>* arbol = new ABB<int>(new int(3));
    arbol->adicionar(new int(2));
    arbol->adicionar(new int(7));
    arbol->adicionar(new int(6));
    arbol->adicionar(new int(1));
    arbol->adicionar(new int(5));
    int altura = arbol->height();
    int nivel = arbol->whatlevelamI(new int(5));

    cout << "Arbol visitado en preorden: ";
    arbol->visit(1);
    cout << endl;
    cout << "Arbol visitado en orden: ";
    arbol->visit(2);
    cout << endl;
    cout << "arbol visitado en posorden: ";
    arbol->visit(3);
    cout << endl;
    cout << "Arbol visitado en level by level: ";
    arbol->visit(4);
    cout << endl;
    cout << "altura del arbol: " << altura << endl;
    cout << "nivel del elemento 5 en el arbol: " << nivel << endl;
    cout << "ancestros del elemento 5 del arbol: ";
    arbol->ancestros(new int(5));
    cout << endl;
    cout << endl;
    cout << "----------------------------------------";
    cout << endl;
    cout << "caso de prueba 2: " << endl;
    ABB<int>* arbol2 = new ABB<int>(new int(5));
    arbol2->adicionar(new int(2));
    arbol2->adicionar(new int(8));
    arbol2->adicionar(new int(10));
    arbol2->adicionar(new int(1));
    arbol2->adicionar(new int(4));
    altura = arbol2->height();
    nivel = arbol2->whatlevelamI(new int(5));
    

    cout << "Arbol visitado en preorden: ";
    arbol2->visit(1);
    cout << endl;
    cout << "Arbol visitado en orden: ";
    arbol2->visit(2);
    cout << endl;
    cout << "arbol visitado en posorden: ";
    arbol2->visit(3);
    cout << endl;
    cout << "Arbol visitado en level by level: ";
    arbol2->visit(4);
    cout << endl;
    cout << "altura del arbol: " << altura << endl;
    cout << "nivel del elemento 5 en el arbol: " << nivel << endl;
    cout << "ancestros del elemento 5 del arbol: ";
    arbol2->ancestros(new int(5));
    cout << endl;
    cout << endl;
    cout << "----------------------------------------";
    cout << endl;
    cout << "caso de prueba 3: " << endl;
    ABB<int>* arbol3 = new ABB<int>(new int(10));
    arbol3->adicionar(new int(9));
    arbol3->adicionar(new int(8));
    arbol3->adicionar(new int(2));

    altura = arbol3->height();
    nivel = arbol3->whatlevelamI(new int(8));

    cout << "Arbol visitado en preorden: ";
    arbol3->visit(1);
    cout << endl;
    cout << "Arbol visitado en orden: ";
    arbol3->visit(2);
    cout << endl;
    cout << "arbol visitado en posorden: ";
    arbol3->visit(3);
    cout << endl;
    cout << "Arbol visitado en level by level: ";
    arbol3->visit(4);
    cout << endl;
    cout << "altura del arbol: " << altura << endl;
    cout << "nivel del elemento 8 en el arbol: " << nivel << endl;
    cout << "ancestros del elemento 2 del arbol: ";
    arbol3->ancestros(new int(2));
    cout << endl;
    cout << endl;
    cout << "----------------------------------------";
    cout << endl;
    cout << "caso de prueba 4: " << endl;
    ABB<int>* arbol4 = new ABB<int>(new int(12));
    arbol4->adicionar(new int(5));
    arbol4->adicionar(new int(7));
    arbol4->adicionar(new int(10));
    arbol4->adicionar(new int(20));
    arbol4->adicionar(new int(9));
    arbol4->adicionar(new int(15));

    altura = arbol4->height();
    nivel = arbol4->whatlevelamI(new int(20));

    cout << "Arbol visitado en preorden: ";
    arbol4->visit(1);
    cout << endl;
    cout << "Arbol visitado en orden: ";
    arbol4->visit(2);
    cout << endl;
    cout << "arbol visitado en posorden: ";
    arbol4->visit(3);
    cout << endl;
    cout << "Arbol visitado en level by level: ";
    arbol4->visit(4);
    cout << endl;
    cout << "altura del arbol: " << altura << endl;
    cout << "nivel del elemento 20 en el arbol: " << nivel << endl;
    cout << "ancestros del elemento 20 del arbol: ";
    arbol4->ancestros(new int(20));
    cout << endl;

    return 0;
}
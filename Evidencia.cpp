//Sebastian Ramirez Cordero A01571087
#include "ABB.h"
#include "Direccion.h"
#include "ListSE.h"
#include "ListDE.h"
#include "Hash.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int toInt(char c){
    switch(c){
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
    }

};
string* split(string sentence){
            static string arr[5] = {""};
            string adicionar = "";
            int letras = 0;
            int contador = 0;
            for (int i = 0; i < sentence.length();i++){
                letras++;
                if (sentence[i] == ' ' && contador < 4){
                    arr[contador] = adicionar;
                    adicionar = "";
                    contador++;
                    // i++;
                }
                else{
                    adicionar = adicionar + sentence[i];
                }

            }
            arr[4] = adicionar;

            return arr;
};
string removePuntos(string dato){
    string final = "";
    for (int i = 0; i<dato.size(); i++){
        if (dato[i] != '.' && dato[i] != ':'){
            final = final + dato[i];
        }
    }
    return final;
};
int Sint(string dato){
    int temp = 0;
    for (int i = 0; i < dato.length(); i++){
        temp = toInt(dato[i]) + 10*temp;
    }
    return temp;
};
string Network(string dato){
    string final = "";
    for (int i = 0; i<dato.size(); i++){
        if(dato[i] == '.'){
            break;
        }
        else{
            final = final + dato[i];
        }
    }
    return final;
}
//es un problem acon mi funcion

// ABBCont<int>* ordenar (ABB<long int>* dato, ABB<int>* desorden){
//     if (!dato->esHoja()){
        
//     }
// }

int main(){
    ifstream file("bitacora.txt");
    string line;
    string test;
    string arr[5] = {" "};
    getline(file,line);
    getline(file,line);
    getline(file,line);
    getline(file,line);

    
    
    ListDE<string>* lista = new ListDE<string>;
    ABB<long int>* arbol = new ABB<long int>;
    string temp;
    long int dato = 0;
    while(getline(file,line)){
        string *atributos = split(line);
        temp = atributos[3];
        lista->add(new string(temp));
        temp = removePuntos(temp);
        dato = stoul(temp);
        arbol->adicionar(new long int(dato));
    }
    // ABB<long int>* arbol2 = new ABB<long int>(new long int(arbol->getCont()));
    ABB<long int>* arbol2 = new ABB<long int>(new long int);

    arbol2->getArbolLlave(arbol);
    dato = stoul(*lista->getElement(0));
    cout << "Se encontro el dato: " << arbol2->BuscarLong(dato) << endl;

    cout << "arbol2: " << arbol2->getHijoIzq()->getKey() << endl;
    cout << "arbol2: " << *arbol2->getHijoIzq()->getRaiz() << endl;
    
    // arbol->visit(2);
    // long int veryLong = 799714375997;
    // arbolCont->adicionar(new int(1),veryLong);
    // arbolCont->adicionar(new int(arbol->getKey()),*arbol->getRaiz());
    // cout << "arbol: " << *arbol->getRaiz() << endl;
    // cout << "arbol izq: " << *arbol->getHijoIzq()->getRaiz();
    //algo en visit causa error
    // cout << "RAIZ ES: " << *arbolCont->getHijoIzq()->getRaiz() << endl;
    //separe la IP de los demas datos, ahora ` cuantas veces sale cada ip
    cout << endl;
    cout << "Los mayores elementos del arbol son: ";
    // Hash* hash = new Hash(arbol,lista);
    // test.append(" ");
    cout << *arbol2->getRaiz() << " " << arbol2->getKey() << endl;
    // stringstream intS(test);
    // intS >> testInt;

    // hash->obtener();
    // arbol->primeros(arbol);
    file.close();
    cout << "Podemos ver que todas las IPs son distintas, asi que una mejor forma de identificar ";
    cout << "usuarios, seria buscando su red de la siguiente forma: " << endl;

    ifstream arch("bitacora.txt");
    getline(arch,line);
    getline(arch,line);
    getline(arch,line);
    getline(arch,line);

    ABB<long int>* arbolNet = new ABB<long int>;

    while(getline(arch,line)){
        string *atributos = split(line);
        temp = atributos[3];
        lista->add(new string(temp));
        temp = Network(temp);
        dato = stoul(temp);
        arbolNet->adicionar(new long int(dato));
    }
    // arbolNet->visit(2);
    // cout << "raiz: " << *arbolNet->getRaiz() << "valor: " << arbolNet->getCont() << endl;
    // cout << endl;
    // ABB<long int>* arbol3 = new ABB<long int>;
    // cout << endl << "raiz3: " << *arbol3->getRaiz() << "valor3: " << *arbol3->getRaiz() << endl;

    // ListDE<int>* keys = hash->getKeys();
    // cout << keys->getLength() << endl;
    // for (int i = 0; i < keys->getLength(); i++){
    //     cout << "si funciona" << endl;
    //     cout << keys->getElement(i) << endl;
    // }

    return 0;
}
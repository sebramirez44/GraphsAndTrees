//Sebastian Ramirez Cordero A01571087
#include "ABB.h"
#include "Direccion.h"
#include "ListSE.h"
#include "ListDE.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int hash(char c){
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


int main(){
    ifstream file("bitacora.txt");
    string line;
    string test;
    string arr[5] = {" "};
    getline(file,line);
    getline(file,line);
    getline(file,line);
    getline(file,line);
    getline(file,line);

    
    
    ListDE<string> lista;
    while(getline(file,line)){
        string *atributos = split(line);
        lista.add(new string(atributos[3]));
    }
    ABB<int>* arbol = new ABB<int>;

    ListDE<string>* ptrList = &lista;
    arbol = arbol->sortAll(ptrList);
    cout << "Los mayores elementos del arbol son: " << endl;
    arbol->primeros(arbol);
    cout << "Podemos ver que todas las IPs son distintas, asi que una mejor forma de identificar ";
    cout << "usuarios, seria buscando su red" << endl;


    return 0;
}
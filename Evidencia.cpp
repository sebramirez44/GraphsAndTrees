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
string* split(string sentence){ //O(n)
//funcion para separar el string a un array.
            static string arr[5] = {""};
            string adicionar = "";
            int letras = 0;
            int contador = 0;
            for (int i = 0; i < sentence.length();i++){
                letras++;
                if (sentence[i] == ' ' && contador < 4){ //separamos el string en los espacios
                    arr[contador] = adicionar;
                    adicionar = "";
                    contador++;
                }
                else{
                    adicionar = adicionar + sentence[i];
                }

            }
            arr[4] = adicionar;

            return arr;
};
string removePuntos(string dato){//le quitamos los puntos al string ip O(n)
    string final = "";
    for (int i = 0; i<dato.size(); i++){
        if (dato[i] != '.' && dato[i] != ':'){
            final = final + dato[i];
        }
    }
    return final;
};

string Network(string dato){ //convertimos el string ip a un string de red. O(n)
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

int main(){
    //archivo
    ifstream file("bitacora.txt");
    string line;
    getline(file,line);
    getline(file,line);
    getline(file,line);
    getline(file,line);

    //inicializamos el arbol que utilizaremos para guardar las IPs y su numero de veces (atributo cont)    
    ABB<long int>* arbol = new ABB<long int>;
    string temp;
    long int dato = 0;

    while(getline(file,line)){//mientras no nos hemos terminado el archivo O(n)
        string *atributos = split(line); //
        temp = atributos[3];
        // temp = removePuntos(temp); utilizariamos esto para checar cada ip completa, sin embargo no haremos eso porque cada ip es unica
        temp = Network(temp);
        dato = stoul(temp);
        arbol->adicionar(new long int(dato));
    }
    ABB<long int>* arbol2 = new ABB<long int>; //arbol en el que tendremos el numero de veces que ocurre como la raiz y la ip como la llave
    arbol2->getArbolLlave(arbol); //inicializamos el arbol utilizando el otro arbol, pero utilizamos cont() de arbol como la raiz de arbol2 y la raiz de arbol como la llave de arbol2
    cout << endl;
    cout << "los maximos por red son: " << endl;
    for (int i = 0; i <= 5; i++){ //mostramos los elementos mas grandes
        arbol2->kthLargest(arbol2,i);
    }
    cout << endl;
    file.close();
    
    
    
    return 0;
}
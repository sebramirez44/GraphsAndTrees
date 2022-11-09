#include "ABB.h"
#include "Direccion.h"
#include "listSE.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string hash(int key){

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

    cout << line << endl;
    string *atributos = split(line);
    for (int i = 0; i<5;i++){
        cout << "el array es: " << atributos[i] << endl;
    }
    ListSE<string> lista;
    lista.add(&atributos[3]);
    cout << *lista.getElement(0) << endl;

    while(getline(file,line)){
        cout << line << endl;
    }
    
    file.close();

    return 0;
}
#pragma once
#include "ABB.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Clase definiendo los nodos de un arbol.
class Direccion{
    protected:
        string mes;
        string dia;
        string hora; //alomejor cambiar a int
        string ip; //separar el string por puntos alomejor?
        string razon;

    public:
        Direccion(){
            mes = "";
            dia = 0;
            hora = "";
            ip = "";
            razon = "";
        };
        Direccion(string mes, string dia, string hora, string ip, string razon){

        }
        ~Direccion(){
            
        };
        string *split(string sentence){
            string arr[5] = {" "};
            string final = "";
            for (int i = 0; i < sentence.length();i++){
                if (!(sentence[i] == ' ')){
                    arr[i] = arr[i] + sentence[i];
                }
            }
            return arr;
        };

    
};

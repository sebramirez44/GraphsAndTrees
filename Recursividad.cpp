#include <iostream>
#include <string>
using namespace std;
int factorial(int num){
    if (num == 0 || num == 1){
        return 1;
    }
    return num*factorial(num-1);
}
int potencia(int base, int exp){
    if (exp == 0){
        return 1;
    }
    return base*potencia(base, exp - 1);
}
//digamos cad = Hola, posActual = 3
string invertirR(string cad, int posActual){
    if (posActual == 0){ //caso base, posicion 0
        char io = cad.at(0);
        string cActual(1,io);
        return cActual;
    }

    return cad.at(posActual) + invertirR(cad, posActual - 1); //caso normal
}
string hex(int num){
    switch (num){
        case 1:
        return "1";
        break;
        case 2:
        return "2";
        break;
        case 3:
        return "3";
        break;
        case 4:
        return "4";
        break;
        case 5:
        return "5";
        break;
        case 6:
        return "6";
        break;
        case 7:
        return "7";
        break;
        case 8:
        return "8";
        break;
        case 9:
        return "9";
        break;
        case 10:
        return "A";
        break;
        case 11:
        return "B";
        break;
        case 12:
        return "C";
        break;
        case 13:
        return "D";
        break;
        case 14:
        return "E";
        break;
        case 15:
        return "F";
        break;
        default:
        return "N/A";

    }

}
string convertHex(int num){
    if (num < 16){ //Caso base, si se puede traducir solo ese numero a una letra
        return hex(num);
    }
    int coc = num / 16;
    int res = num % 16;

    return convertHex(coc) + hex(res); //caso normal, usamos recursividad
}


string invertirR(string cad){
    return invertirR(cad, cad.size()-1);
}

int main()
{
    string hex = convertHex(500);
    cout << "Hola es: " << hex << endl;

    return 0;
}
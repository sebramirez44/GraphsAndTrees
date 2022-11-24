#include <iostream>
#include <vector>
#include <string>
#include "Heap.h"
using namespace std;
int main(){
    vector<int> v = {63,30,40,10,25,8,38,5,3};
    Heap<int> test(v);
    test.push(18);
    test.pop();
    test.imprimir();

    return 0;
}
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T> class Heap{
private:
    vector<T> heap;
public:
    Heap(vector<T> heap){
        this->heap = heap;
    }
    ~Heap(){

    }
    void pushHeap(){
        int currentPos, parentPos;
        T target;
        currentPos = this->heap.size()-1;
        parentPos = (currentPos-1)/2;
        target = this->heap[this->heap.size()-1];
        // cout << this->heap[currentPos] << endl;
        while (currentPos != 0){
            if (target > this->heap[parentPos]){
                this->heap[currentPos] = this->heap[parentPos];
                currentPos = parentPos;
                parentPos = (currentPos-1)/2;
            }
            else{
                break;
            }
            
        }
        this->heap[currentPos] = target;
    }
    void adjustHeap(){ //heapify cuando root no es el mas grande
        int currentPos = 0;
        T target = heap[currentPos];
        int childPos = 2*currentPos+1;
        while(childPos <= heap.size()-1){
            if ((childPos+1 <= heap.size()-1) && heap[childPos+1] > heap[childPos]){
                childPos++;
            }
            if (heap[childPos] > target){
                heap[currentPos] = heap[childPos];
                currentPos = childPos;
                childPos = 2* currentPos + 1;
            }
            else{
                break;
            }
        }
        heap[currentPos] = target;

    }
    void push(T dato){
        //primero pushback al vector
        this->heap.push_back(dato);
        int currentPos, parentPos;

        //despues pushHeap donde target es el ultimo valor
        this->pushHeap();
        //profit
    }
    void pop(){
        //primero cambiar el mas grande con el ultimo
        T temp;
        temp = heap[0];
        heap[0] = heap[heap.size()-1];
        heap[heap.size()-1] = temp;
        this->adjustHeap();
        this->heap.pop_back();
        //reheapify pero de arriba a abajo.
        //borrar el de hasta abajo
        //profit
    }
    void imprimir(){
        for (int i = 0; i < this->heap.size();i++){
            cout << this->heap[i] << endl;
        }
    }



};
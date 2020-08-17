#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(bool minHeap) {
    this->minHeap = minHeap;
    contador = 0;
    for(int i = 0; i < 1023; i++){
        arreglo[i] = -1;
    }
}

void Heap::encolar(int prioridad){
    int i = contador;
    contador++;
    arreglo[i] = prioridad;
    if(minHeap){
        while(i >= 1 && arreglo[i/2]>=arreglo[i]){
            int temp = arreglo[i/2];
            arreglo[i/2] = arreglo[i];
            arreglo[i] = temp;
            i/=2;
        }
    } else {
        while(i >= 1 && arreglo[i/2]<=arreglo[i]){
            int temp = arreglo[i/2];
            arreglo[i/2] = arreglo[i];
            arreglo[i] = temp;
            i/=2;
        }
    }
}

void Heap::imprimirArreglo(){
    cout << "[ ";
    for(int i = 0; i < 1023; i++){
        if(arreglo[i] == -1){
            break;
        }
        cout << arreglo[i] << ", ";
    }
    cout << "]" << endl;
}

int Heap::desencolar(){
    int elemento = arreglo[0];
    if(elemento == -1) return -1;
    arreglo[0] = arreglo[contador - 1];
    arreglo[contador - 1] = -1;
    contador--;
    if(minHeap){
        balancearHeapMin(0);
    } else {
        balancearHeapMax(0);
    }
    return elemento;
}

void Heap::balancearHeapMax(int i){
    int l = i*2+1;
    int r = i*2+2;
    if(l > contador || r > contador) return;
    if(arreglo[i*2+1] > arreglo[i]){
        int temp = arreglo[i];
        arreglo[i] = arreglo[l];
        arreglo[l] = temp;
        balancearHeapMax(i);
        balancearHeapMax(l);
    } else if(arreglo[r] > arreglo[i]){
        int temp = arreglo[i];
        arreglo[i] = arreglo[r];
        arreglo[r] = temp;
        balancearHeapMax(i);
        balancearHeapMax(r);
    }
}

void Heap::balancearHeapMin(int i){
    int l = i*2+1;
    int r = i*2+2;
    if(l > contador || r > contador) return;
    if(arreglo[i*2+1] < arreglo[i]){
        int temp = arreglo[i];
        arreglo[i] = arreglo[l];
        arreglo[l] = temp;
        balancearHeapMin(i);
        balancearHeapMin(l);
    } else if(arreglo[r] < arreglo[i]){
        int temp = arreglo[i];
        arreglo[i] = arreglo[r];
        arreglo[r] = temp;
        balancearHeapMin(i);
        balancearHeapMin(r);
    }
}

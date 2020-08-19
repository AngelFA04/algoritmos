#include <iostream>
#include <limits.h>
#include "Prim.h"

using namespace std;

Prim::Prim(int numeroNodos, int **matrizAdj){
    this->numeroNodos = numeroNodos;
    this->matrizAdj = matrizAdj;
    arbol = new int[numeroNodos];
    visitados = new bool[numeroNodos];
}



void Prim::inicializarValores(){
    for(int i = 0; i < numeroNodos; i++){
        arbol[i] = -1;
        visitados[i] = false;
    }
    arbol[0] = 0;
    visitados[0] = true;
}

bool Prim::noVisiteTodos(){
    for(int i = 0; i < numeroNodos; i++){
        if(!visitados[i]){
            return true;
        }
    }
    return false;
}

void Prim::imprimirSolucion(){
    cout << "[ ";
    for(int i = 0; i < numeroNodos - 1; i++){
        cout << arbol[i] << ", ";
    }
    cout << arbol[numeroNodos - 1] << " ]" << endl;
}

void Prim::calcularAEM(){
    inicializarValores();
    while(noVisiteTodos()){
        int minPeso = INT_MAX;
        int minIndex;
        int padre;
        for(int i = 0; i < numeroNodos; i++){
            if(arbol[i] != -1){
                for(int j = 0; j < numeroNodos; j++){
                    if(visitados[j] || matrizAdj[i][j] == 0) continue;
                    if(matrizAdj[i][j] < minPeso){
                        minPeso = matrizAdj[i][j];
                        minIndex = j;
                        padre = i;
                    }
                }
            }
        }
        arbol[minIndex] = padre + 1;
        visitados[minIndex] = true;
    }
    imprimirSolucion();
}

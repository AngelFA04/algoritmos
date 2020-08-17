#include <iostream>
#include <limits.h>
#include "Dijkstra.h"

using namespace std;

Dijkstra::Dijkstra(int numeroNodos, int **matrizAdj){
    this->numeroNodos = numeroNodos;
    this->matrizAdj = matrizAdj;
    distancias = new int[numeroNodos];
    visitados = new bool[numeroNodos];
    padres = new int[numeroNodos];
}

void Dijkstra::imprimirCamino(int j) {
    if (padres[j] == - 1){
        return;
    }
    imprimirCamino(padres[j]);
    cout << j << ", ";
}

void Dijkstra::imprimirSolucion(int src){
    cout << "Las distancias mas cortas de " << (src + 1) << " hacia los demas nodos son: " << endl;
    for(int i = 0; i < numeroNodos; i++){
        if(i == src) continue;
        cout << "[" << (i+1) << "] -> ";
        if(distancias[i] == INT_MAX){
            cout << "\u221E" << endl;
        } else {
            cout << distancias[i] << " -> ";
            imprimirCamino(i);
            cout << endl;
        }
    }
    cout << endl;
}

int Dijkstra::minDistancia(){
    int minD = INT_MAX, minI;
    for(int i = 0; i < numeroNodos; i++){
        if(!visitados[i] && distancias[i] < minD){
            minD = distancias[i];
            minI = i;
        }
    }
    return minI;
}

void Dijkstra::inicializarValores(int src){
    for(int i = 0; i < numeroNodos; i++){
        if(matrizAdj[src][i] == 0){
            distancias[i] = INT_MAX;
        } else {
            distancias[i] = matrizAdj[src][i];
        }
        visitados[i] = false;
        padres[i] = -1;
    }
    distancias[src] = 0;
    visitados[src] = true;
}

void Dijkstra::calcularDC(int src){
    inicializarValores(src);
    for(int i = 0; i < numeroNodos - 1; i++){
        int u = minDistancia();
        visitados[u] = true;
        for(int j = 0; j < numeroNodos; j++){
            if(matrizAdj[u][j] == 0 || visitados[j]) continue;
            int tempS = distancias[u] + matrizAdj[u][j];
            if(tempS < distancias[j]){
                distancias[j] = tempS;
                padres[j] = u;
            }
        }
    }
    imprimirSolucion(src);
}

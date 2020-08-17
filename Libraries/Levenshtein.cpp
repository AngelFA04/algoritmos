#include "Levenshtein.h"
#include<iostream>
#include<string>

using namespace std;

Levenshtein::Levenshtein(){ }

int Levenshtein::masChico(int arriba, int derecha, int diagonal){
    if(arriba <= derecha && arriba <= diagonal){
        return arriba;
    }
    if(derecha <= arriba && derecha <= diagonal){
        return derecha;
    }
    if(diagonal <= arriba && diagonal <= derecha){
        return diagonal;
    }
    return 0;
}

int Levenshtein::calcularDistancia(string palabra1, string palabra2){
    int n = palabra1.length()+1;
    int m = palabra2.length()+1;
    int matriz[n][m];
    int costoS;
    for(int i = 0; i < n; i++){
        matriz[i][0] = i;
    }
    for(int i = 1; i < m; i++){
        matriz[0][i] = i;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(palabra1[i-1] == palabra2[j-1]){
                costoS = 0;
            } else {
                costoS = 1;
            }
            int arriba = matriz[i-1][j] + 1;
            int derecha = matriz[i][j-1] + 1;
            int diagonal = matriz[i-1][j-1] + costoS;
            matriz[i][j] = masChico(arriba, derecha, diagonal);
        }
    }
    return matriz[n-1][m-1];
}

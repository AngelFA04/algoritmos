#include <iostream>
#include "Ordenamiento.h"

using namespace std;

Ordenamiento::Ordenamiento(){ }

Ordenamiento::~Ordenamiento(){ }

void Ordenamiento::imprime(int *datos, int sizeA){
    cout << "[ ";
    for(int i = 0; i < sizeA - 1; i++){
        cout << datos[i] << ", ";
    }
    cout << datos[sizeA - 1] << " ]";
    cout << endl;
}

void Ordenamiento::imprimeAlreves(int *datos, int sizeA){
    cout << "[ ";
    for(int i = sizeA-1; i > 0; i--){
        cout << datos[i] << ", ";
    }
    cout << datos[0] << " ]";
    cout << endl;
}


void Ordenamiento::swap(int *v1, int *v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void Ordenamiento::burbuja(int *datos, int sizeA){
    for(int j = 0; j < sizeA; j++){
        for(int i = 0; i < sizeA; i++){
            if(datos[i]>datos[i+1]){
                swap(&datos[i], &datos[i+1]);
            }
        }
    }
}

void Ordenamiento::seleccion(int *datos, int sizeA){
    for(int i = 0; i < sizeA - 1; i++){
        for(int j = i + 1; j < sizeA; j++){
            if(datos[i]>datos[j]){
                swap(&datos[i], &datos[j]);
            }
        }
    }
}

void Ordenamiento::merge(int *datos, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    for(i = 0; i<nl; i++){
        larr[i] = datos[l+i];
    }
    for(j = 0; j<nr; j++){
        rarr[j] = datos[m+1+j];
    }
    i = 0; j = 0; k = l;
    while(i < nl && j < nr) {
        if(larr[i] <= rarr[j]) {
            datos[k] = larr[i];
            i++;
        }else{
            datos[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        datos[k] = larr[i];
        i++; k++;
    }
    while(j<nr) {
        datos[k] = rarr[j];
        j++; k++;
    }
}

void Ordenamiento::mergeSort(int *datos, int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;
        mergeSort(datos, l, m);
        mergeSort(datos, m + 1, r);
        merge(datos, l, m, r);
    }
}

int Ordenamiento::partition (int *datos, int l, int h) {
    int pivote = datos[h];
    int i = (l - 1);
    for (int j = l; j < h; j++){
        if (datos[j] <= pivote){
            i++;
            swap(&datos[i], &datos[j]);
        }
    }
    swap(&datos[i + 1], &datos[h]);
    return (i + 1);
}

void Ordenamiento::quickSort(int *datos, int l, int h) {
    if(l < h) {
        int pivote = partition(datos, l, h);
        quickSort(datos, l, pivote - 1);
        quickSort(datos, pivote + 1, h);
    }
}

int Ordenamiento::max(int *datos, int sizeA){
    int m = datos[0];
    for(int i = 1; i < sizeA; i++){
        if(datos[i] > m){
            m = datos[i];
        }
    }
    return m;
}

void Ordenamiento::bucketSort(int *datos, int sizeA){
    int index = 0;
    int m = max(datos, sizeA);
    int bucket[m + 1];
    for(int i = 0; i <= m; i++){
        bucket[i] = 0;
    }
    for(int i = 0; i < sizeA; i++){
        bucket[datos[i]]++;
    }
    for(int i = 0; i <= m; i++){
        if(bucket[i] > 0){
            for(int j = 0; j < bucket[i]; j++){
                datos[index] = i;
                index++;
            }
        }
    }
}















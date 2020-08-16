#include <iostream>
#include "../Libraries/ListaLigada.h"
#include "../Libraries/Ordenamiento.h"
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int number;
    ListaLigada list;
    Ordenamiento order;

    cout << "Introduce una lista de números, para detener presiona introduce -1\n";
    cin >> number;
    while (number != -1){
        list.agregar(number);
        cin >> number;
    }
    //list.imprimeLista();
    
    //Convertir lista a array para ordenar
    int n = list.sizeLista;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = list.desEnlista()->valor;
    }
    
    
    //Ordenar lista
    order.seleccion( arr , n);
    
    //Imprimir lista ordenada
    cout << "\nArreglo ordenado\n";
    //Menor a mayor
    cout << "Menor a mayor:\n";
    order.imprime(arr, n);
    //Mayor a menor
    cout << "Mayor a menor:\n";
    order.imprimeAlreves(arr,n);

    return 0;
}

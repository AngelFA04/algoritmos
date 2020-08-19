#include <iostream>
#include "../../Libraries/Dijkstra.h"
#include "../../Libraries/Prim.h"


using namespace std;



int main(int argc, char const *argv[])
{
    int n_nodes;
    int node_weight;
    cout << "Introduce la cantidad nodos que quieres agregar: ";
    cin >> n_nodes;

    int **matriz_prueba;
    matriz_prueba = new int*[n_nodes];
    bool correct;
    correct = false;
    char option;
    
    while(!correct){

            //Introducir datos en matriz
        for(int i = 0; i < n_nodes; i++){
            matriz_prueba[i] = new int[n_nodes];
        }
        for(int i = 0; i < n_nodes; i++){
            for(int j = 0; j < n_nodes; j++){
                cout << " Introducir peso de nodo en ["<<i<<"]["<<j<<"]: ";
                cin >> node_weight;
                matriz_prueba[i][j] = node_weight;
            }
        }
        
        //Mostrar matriz de adyacencia
        cout << "La matriz de adjacencia generada es la siguiente: \n";
        for(int i = 0; i < n_nodes; i++){
            cout << "\t";
            for(int j = 0; j < n_nodes; j++){
                //cout <<i << " " << j <<"\n";
                cout <<matriz_prueba[i][j] <<" ";
            }
            cout << "\n";
        }
        cout << "¿La matriz generada es correcta?: Sí[1], No[0]: ";
        cin >> option;
        if(option == '1'){
            correct = true;
        } 
        else if(option == '0'){
            correct = false;
        }
        else{
            correct = false;
        }
        cout << "\n";
    }
    


    Dijkstra grafo(n_nodes, matriz_prueba);
    for(int i =0; i < n_nodes; i++){
        grafo.calcularDC(i);
    }
    Prim prim(n_nodes, matriz_prueba);
    cout << "El arbol de expansion minima es el siguiente:\n";
    prim.calcularAEM();
 
    return 0;
}

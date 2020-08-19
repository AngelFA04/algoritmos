#include <iostream>
#include "Dijkstra.h"

using namespace std;

int main() {
    int numNodos, respuesta;
    int **matrizAdj;
    bool correcto = true;
    bool correcto2 = true;
    
    //Empezamos a definir el grafo, comenzando por el número de nodos
    cout << "Escribe el numero de nodos de tu grafo: ";
    cin >> numNodos;
    int matrizAdjT[numNodos][numNodos];
    
    //¿?
    while(correcto){
    for(int i=0; i<numNodos; i++){
        for(int x=0; x<numNodos; x++){
            cout<<"Dijite el numero[" << i+1 << "][" << x+1 <<"]";
            cin >> matrizAdjT[i][x];

        }
    }
    //Imprimimos la matriz resultante
    cout<<"La matriz almacenada es"<<endl;
      for(int i=0; i<numNodos; i++){
        for(int x=0; x<numNodos; x++){
            cout << matrizAdjT[i][x] <<" ";

        }
    }
    //Confirmamos la matriz
    cout<<"\n";
    do{
    cout<<"1. Si\n2. No\nIndica si la matriz es correcta ";
    cin >> respuesta;
    cout<<"\n";
    if(respuesta == 1 ){
        correcto = false;
        correcto2 = false;
    }else if(respuesta == 2){
        correcto = true;
        correcto2 = false;
        }else{
            cout<< "Esa opcion no es valida "<<endl;
            correcto2 = true;
            }
        }while(correcto2);
    }while(correcto);


    matrizAdj = new int*[numNodos];
    for(int i = 0; i < numNodos; i++){
        matrizAdj[i] = new int[numNodos];
    }
    for(int i = 0; i < numNodos; i++){
        for(int j = 0; j < numNodos; j++){
            matrizAdj[i][j] = matrizAdjT[i][j];
        }
    }
    //Pasamos a aplicar Dijkstra y calcular la distancia más corta
    Dijkstra d(numNodos, matrizAdj);
    for(int i = 0; i < numNodos; i++){
        d.calcularDC(i);
    }
    return 0;
}

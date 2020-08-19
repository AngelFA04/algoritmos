#include <iostream>
#include "Dijkstra.h"

using namespace std;

int main() {
    int nNodos, respuesta;
    int **matrizAdj;
    bool correcto = true;
    bool correcto2 = true;
    
    //Empezamos a definir el grafo, comenzando por el número de nodos
    cout << "Escribe el numero de nodos de tu grafo: ";
    cin >> numNodos;
    int matrizAdjT[nNodos][nNodos];

    while(correcto){
    for(int i=0; i<numNodos; i++){
        for(int x=0; x<numNodos; x++){
            cout<<"Dijite el numero[" << i+1 << "][" << x+1 <<"]";
            cin >> matrizAdjT[i][x];

        }
    }
    cout<<"\n";
    cout<<"La matriz almacenada"<<endl;
      for(int i=0; i<numNodos; i++){
        for(int x=0; x<numNodos; x++){
            cout << matrizAdjT[i][x] <<" ";

        }
        cout <<"\n";
    }
    cout<<"\n";
    do{
    cout<<"1. SI\n2. NO\n¿Es correcta la matriz? ";
    cin >> respuesta;
    cout<<"\n";
    if(respuesta == 1 ){
        correcto = false;
        correcto2 = false;
    }else if(respuesta == 2){
        correcto = true;
        correcto2 = false;
        }else{
            cout<< "Esa opcion no es valida! "<<endl;
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
    Dijkstra d(numNodos, matrizAdj);
    for(int i = 0; i < numNodos; i++){
        d.calcularDC(i);
    }
    return 0;
}

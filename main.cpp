#include "./ListaLigada.h"
#include <iostream>

using namespace std;


int main(){
    cout << "Menu de opciones" << "\n";
    cout << "1. Insertar\n";
    cout << "2. Buscar\n";
    cout << "3. Borrar\n";
    cout << "4. Imprimir\n";
    cout << "5. Salir\n";

    int option;
    cout << "Introduce la opción:\n";
    cin >> option;

    //Crear lista ligada
    ListaLigada ll;

    while(option != 5){
        switch (option)
        {
        case 1:
            /* Insertar - Angel */
            int value;
            cout << "Introduce el valor para enlistar en la lista\n";
            cin >> value;
            Nodo *node = ll.creaNodo(0, value);

            ll.enLista(node);
            
            break;
        case 2:
            /* Borrar - Luis*/
            break;
        case 3:
            /* Buscar - Luis */
            break;
        case 4:
            /* Imprimir */
            ll.imprimeLista();
            break;
        default:
            cout << "Esta opción no existe";
            break;
        }
    }
}
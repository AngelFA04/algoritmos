#include "../Libraries/ListaLigada.h"
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
    int value;

    //Crear lista ligada
    ListaLigada ll;

    while(option  != 5 ){
        switch (option)
        {
        case 1:
            /* Insertar - Angel */
            cout << "Introduce el valor para enlistar en la lista\n";
            cin >> value;
            int lastId;
            if(ll.sizeLista == 0){
                lastId = 0;
            }
            else
            {
                lastId = ll.fin->id + 1;
            }
            

            ll.enLista(ll.creaNodo(lastId, value) );
            
            break;

        
        case 2:
            /* Buscar - Luis */
                
                cout << "Introduce el valor para buscar en la lista: ";
                cin >> value;
                Nodo *aux;  
                aux = ll.inicio;
                bool existe;
                existe = false;

                while(aux != NULL )
                {
                    if (aux->valor == value) {
                        existe = true;
                        break;
                    } else {
                        aux=aux->siguiente;
                    }
                }
                if( existe == true)
                {
                    cout<<"El número "<<value<<" está en la lista";
                }
                else
                {
                    cout<<"El numero  no está en la lista";
                }
            break;
        case 3:
            /* Borrar - Luis*/
            int pos_remove;
            cout << "Introduce la posición del valor para remover de la lista\n";
            cin >> pos_remove;
            if(ll.sizeLista == 0){
                cout << "No hay elementos en la lista";
            }
            else
            {
                ll.removerDe(pos_remove);
            } /* ?*/
            break;
                
        case 4:
            /* Imprimir */
            cout << "\n";
            ll.imprimeLista();
            cout << "\n";
            break;
        default:
            cout << "Esta opción no existe";
            break;
        
        }
            cout << "Menu de opciones" << "\n";
            cout << "1. Insertar\n";
            cout << "2. Buscar\n";
            cout << "3. Borrar\n";
            cout << "4. Imprimir\n";
            cout << "5. Salir\n";

            cout << "Introduce la opción:\n";
            cin >> option;

    }
}
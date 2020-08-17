#include <iostream>
#include "../Libraries/ArbolBinario.h"

using namespace std;


void imprimir_menu(){
    cout << "------------------------" << "\n";
    cout << "Menu de opciones" << "\n";
    cout << "1. Insertar\n";
    cout << "2. Buscar\n";
    cout << "3. Borrar\n";
    cout << "4. Imprimir\n";
    cout << "5. Salir\n";
    cout << "------------------------" << "\n";
}

void imprimir_opciones(){
    /* Función para imprimir los diferentes metodos de mostrar
    un arbol binario */
    cout << "\ta) Imprimir In\n";
    cout << "\tb) Imprimir Post\n";
    cout << "\tc) Imprimir Pre\n";
    cout << "\tIntroduce una opción:\n\t";
    
}

void logica(int option){
    int dato;
    int number;
    ArbolBinario arbol;


    while(option!=5 )
    {
        switch (option)
        {
            case 1:
                /* Insertar */
                cout << "Introduce un dato para la hoja: ";
                cin >> dato;
                arbol.insertaHoja(dato);
                break;
            case 2:
                /* Buscar */
                cout << "Número a buscar: ";
                cin >> number;
                cout << "*********\n";
                if(arbol.buscar(number)){
                    cout << "✔ El número " << number << " fue encontrado\n";
                }
                else{
                    cout << "❌ El número " << number << " NO fue encontrado\n";
                }
                cout << "*********\n";
                break;
            case 3:
                /* Borrar */
                cout << "Número a borrar: ";
                cin >> number;
                if (arbol.buscar(number))
                {
                    arbol.podar(number);
                    cout << "✔ Elemento borrado correctamente\n";
                }
                else{
                    cout << "❌ El número que intentas borrar no existe\n";
                }
                
                break;
            case 4:
                /* Imprimir */
                char tipo;
                imprimir_opciones();
                cin >> tipo;
                switch (tipo)
                {
                case 'a':
                    arbol.imprimirIn();
                    break;
                case 'b':
                    arbol.imprimirPost();
                    break;
                case 'c':
                    arbol.imprimirPre();
                    break;
                default:
                    break;
                }
                break;
            case 5:
                break;
        
            default:
                cout << "Opcion no valida, ingresa otro número!\n";
                break;
        }
        
        imprimir_menu();
        cin >> option;
    
    }
}


int main(int argc, char const *argv[])
{

    //Imprime el menu
    imprimir_menu();

    int option;
    cin >> option;
    //Mantiene al programa corriendose hasta que se presione 5
    logica(option);
    
    
    return 0;
}





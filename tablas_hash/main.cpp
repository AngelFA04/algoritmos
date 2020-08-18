#include <iostream>
#include "TablaHash.h"

using namespace std;

void menu_opciones(){
        cout << "------------------------" << "\n";
        cout << "Menu de Opciones" << "\n";
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Actualizar "<< endl;
        cout << "4. Borrar" << endl;
        cout << "5. Imprimir" << endl;
        cout << "6. Salir" << endl;
        cout << "------------------------" << "\n";
}

int main()
{

    int opcion;
    string nombre, email, numero;
    TablaHash th;

    menu_opciones();
    int option;
    cout << "Introduce la opción que quieras realizar: ";
    cin >> option;

    while(option  != 6 ){
    switch (option)
    {
        //Insertar 
        case 1:
            cout << "Escribe el nombre que deseas insertar: \n";
            cin >>nombre;
            cout << "Escribe un numero que deseas insertar: \n";
            cin >> numero;
            cout << "Escribe el correo que deseas insertar: \n";
            cin >> email;
            th.insertar(nombre, numero, email);
            cout<<"La información ha sido insertada\n"<<endl;
            break;

        //Buscar
        case 2: 
            cout << "Escribe el nombre de la persona que quieres buscar: \n";
            cin >> nombre;
            if(th.buscar(nombre)!=-1){
                cout << "Ese nombre está registrado\n"<<endl;
            }
            else{
                cout << "El nombre no está registrado\n";
            }
            break;

        //Actualizar
        case 3: 
            cout << "Escribe el nombre de la persona que quieres actualizar: \n";
            
            cin >> nombre;
            if(th.buscar(nombre)==-1){
                cout << "Ese nombre no está registrado \n"<<endl;
            }else{
                cout << "Escribe el nuevo número: \n";
                cin >> numero;
                cout << "Escribe el correo: \n";
                cin >> email;
                th.actualizar(nombre, numero, email, true);
                cout << "La base de datos ha sido actualizada"<<endl;
            }

            break;
        //Borrar
        case 4:

            cout << "Escribe el nombre de la persona que quieres eliminar: \n";
            cin >> nombre ;
            if(th.buscar(nombre)==-1){
                cout << "El nombre no está registrado \n"<<endl;
            }else{
                th.eliminar(nombre);
                cout<<"Eliminado con exito! \n" << endl;
            }

            break;
        //Imprimir
        case 5:
            th.imprimir();
            break;

        case 6:
            th.imprimirTabla();
            break;
    }
    menu_opciones();
    cin >> option;
    }
    return 0;
}
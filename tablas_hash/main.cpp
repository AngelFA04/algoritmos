#include <iostream>
#include "TablaHash.h"

using namespace std;

int main()
{

    int opcion;
    string nombre, email, numero;
    TablaHash th;

    do {
        //system("cls");

        cout << "\nMenu de Opciones" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Actualizar "<< endl;
        cout << "4. Borrar" << endl;
        cout << "5. Imprimir" << endl;
        cout << "6. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1://INSERTAR
                cout << "\nEscribe el nombre: ";
                cin.ignore();
                getline(cin,nombre);
                cout << "\nEscribe el numero: ";
                //cin.ignore();
                cin >> numero;
                //getline(cin,numero);
                cout << "\nEscribe el correo: ";
                cin.ignore();
                //getline(cin,email);
                cin >> email;
                th.insertar(nombre, numero, email);
                cout<<"\n\tInsertado exitosamente!"<<endl;
                break;

            case 2: //BUSCAR
                cout << "\nEscribe el nombre de la persona que quieres buscar: ";
                cin.ignore();
                getline(cin,nombre);
                if(th.buscar(nombre)==-1){
                    cout << "\nEse nombre no existe"<<endl;
                }
                break;

            case 3: //ACTUALIZAR
                cout << "\nEscribe el nombre de la persona que quieres actualizar: ";
                cin.ignore();
                getline(cin,nombre);
                if(th.buscar(nombre)==-1){
                    cout << "\nEse nombre no existe"<<endl;
                }else{
                    cout << "\nEscribe el numero: ";
                    cin >> numero;
                    cout << "\nEscribe el correo: ";
                    cin.ignore();
                    cin >> email;
                    th.actualizar(nombre, numero, email, true);
                    cout << "\n\tActualizacion exitosa!"<<endl;
                }

                break;
            case 4://BORRAR

                cout << "\nEscribe el nombre de la persona que quieres borrar: ";
                cin.ignore();
                getline(cin,nombre);
                if(th.buscar(nombre)==-1){
                    cout << "\nEse nombre no existe"<<endl;
                }else{
                    th.eliminar(nombre);
                    cout<<"\n\tEliminado con exito!" << endl;
                }

                break;

            case 5://Imprimir
                cout<<endl;
                th.imprimirTabla();
                break;
        }

    } while (opcion != 6);

    return 0;

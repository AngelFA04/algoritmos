#include "TablaHash.h"

TablaHash::TablaHash() {
    for(int i = 0; i < 1024; i++){
        tabla[i] = NULL;
    }
    tam = 0;
}

void TablaHash::imprimirTabla(){
    for(int i = 0; i < 1024; i++){
        if(tabla[i] != NULL){
            cout << "Pos: " << i << " -> ";
            for(Nodo *temp = tabla[i]; temp!=NULL; temp=temp->siguiente){
                cout << "(Nombre: " << temp->nombre;
                cout << " Numero: " << temp->numero;
                cout << " Correo: " << temp->email;
                cout << ") -> ";
            }
            cout << endl;
        }
    }
}


void TablaHash::insertar(string nombre, string numero, string email){
    int pos = obtenerCodigoHash(nombre);
    Nodo *nodo = crearNodo(nombre, numero, email);
    insertar(nodo, pos);
    tam++;
}

void TablaHash::insertar(Nodo *nodo, int pos){
    if(tabla[pos] == NULL){
        tabla[pos] = nodo;
    } else {
        Nodo *temp = tabla[pos];
        for( ;temp->siguiente != NULL; temp=temp->siguiente);
        temp->siguiente = nodo;
    }
}


void TablaHash::actualizar(string nombre, string numero, string email, bool ins){
    bool encontrado = false;
    int pos = obtenerCodigoHash(nombre);
    for(Nodo *temp = tabla[pos]; temp != NULL; temp=temp->siguiente){
        if(temp->nombre.compare(nombre) == 0){
            temp->numero = numero;
            temp->email=email;
            encontrado = true;
            break;
        }
    }
    if(ins && !encontrado){
        insertar(nombre, numero, email);
        return;
    }
    if(!ins && !encontrado){
        cout << "No se encontro la nombre: " << nombre << endl;
    }
}

int TablaHash::obtenerCodigoHash(string nombre){
    int numero = 0;
    for(unsigned int i = 0; i < nombre.length(); i++){
        numero += nombre.at(i)*(i+1);
    }
    numero %= 1024;
    return numero;
}

Nodo *TablaHash::crearNodo(string nombre, string numero, string email){
    Nodo *nodo = new Nodo;
    nodo->nombre = nombre;
    nodo->numero = numero;
    nodo->email = email;
    nodo->siguiente = NULL;
    return nodo;
}

void TablaHash::eliminar(string nombre){
    bool encontrado = false;
    int pos = obtenerCodigoHash(nombre);
    Nodo *temp = tabla[pos];
    Nodo *anterior = temp;
    for(; temp != NULL; temp=temp->siguiente){
        if(temp->nombre.compare(nombre) == 0){
            encontrado = true;
            break;
        }
        anterior = temp;
    }
    if(encontrado){
        if(temp->dato == tabla[pos]->dato){
            tabla[pos] = NULL;
        } else {
            anterior->siguiente = NULL;
        }
        delete temp;
        tam--;
    } else {
        cout << "No se encontro la nombre: " << nombre << endl;
    }
}

int TablaHash::buscar(string nombre){
    int pos = obtenerCodigoHash(nombre);
    for(Nodo *temp = tabla[pos]; temp != NULL; temp=temp->siguiente){
        if(temp->nombre.compare(nombre) == 0){
            cout<<endl;
            cout << "\t(Nombre: " << temp->nombre;
            cout << " Numero: " << temp->numero;
            cout << " Correo: " << temp->email;
            cout << ") ";
            cout<<endl;
            return temp->dato;
        }
    }
    return -1;
}

int TablaHash::obtenTamanio(){
    return tam;
}

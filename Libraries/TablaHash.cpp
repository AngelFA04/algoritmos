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
                cout << "(Llave: " << temp->llave;
                cout << " Valor: " << temp->dato;
                cout << ") -> ";
            }
            cout << endl;
        }
    }
}

void TablaHash::insertar(string llave, int valor){
    int pos = obtenerCodigoHash(llave);
    Nodo *nodo = crearNodo(llave, valor);
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


void TablaHash::actualizar(string llave, int valor, bool ins){
    bool encontrado = false;
    int pos = obtenerCodigoHash(llave);
    for(Nodo *temp = tabla[pos]; temp != NULL; temp=temp->siguiente){
        if(temp->llave.compare(llave) == 0){
            temp->dato = valor;
            encontrado = true;
            break;
        }
    }
    if(ins && !encontrado){
        insertar(llave, valor);
        return;
    }
    if(!ins && !encontrado){
        cout << "No se encontro la llave: " << llave << endl;
    }
}

int TablaHash::obtenerCodigoHash(string llave){
    int valor = 0;
    for(unsigned int i = 0; i < llave.length(); i++){
        valor += llave.at(i)*(i+1);
    }
    valor %= 1024;
    return valor;
}

Nodo *TablaHash::crearNodo(string llave, int valor){
    Nodo *nodo = new Nodo;
    nodo->llave = llave;
    nodo->dato = valor;
    nodo->siguiente = NULL;
    return nodo;
}

void TablaHash::eliminar(string llave){
    bool encontrado = false;
    int pos = obtenerCodigoHash(llave);
    Nodo *temp = tabla[pos];
    Nodo *anterior = temp;
    for(; temp != NULL; temp=temp->siguiente){
        if(temp->llave.compare(llave) == 0){
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
        cout << "No se encontro la llave: " << llave << endl;
    }
}

int TablaHash::buscar(string llave){
    int pos = obtenerCodigoHash(llave);
    for(Nodo *temp = tabla[pos]; temp != NULL; temp=temp->siguiente){
        if(temp->llave.compare(llave) == 0){
            return temp->dato;
        }
    }
    return -1;
}

int TablaHash::obtenTamanio(){
    return tam;
}

#include<iostream>
#include <string>
#ifndef TABLAHASH_H
#define TABLAHASH_H

using namespace std;

struct Nodo{
    string llave;
    int dato;
    Nodo *siguiente;
};

class TablaHash {
    public:
        TablaHash();
        void insertar(string llave, int valor);
        void eliminar(string llave);
        void actualizar(string llave, int valor, bool ins);
        int buscar(string llave);
        int obtenTamanio();
        void imprimirTabla();
    private:
        int tam;
        Nodo *tabla[1024];
        int obtenerCodigoHash(string llave);
        Nodo *crearNodo(string llave, int valor);
        void insertar(Nodo *nodo, int pos);
};

#endif // TABLAHASH_H

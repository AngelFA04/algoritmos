#include<iostream>
#include <string>
#ifndef TABLAHASH_H_INCLUDED
#define TABLAHASH_H_INCLUDED

using namespace std;

struct Nodo{
    string nombre, email, numero;
    int dato;
    Nodo *siguiente;
};

class TablaHash {
    public:
        TablaHash();
        void insertar(string nombre, string numero, string email);
        void eliminar(string nombre);
        void actualizar(string nombre, string numero, string email, bool ins);
        int buscar(string nombre);
        int obtenTamanio();
        void imprimirTabla();
        void imprimirNodo();
        void imprimir();
    private:
        int tam;
        Nodo *tabla[1024];
        int obtenerCodigoHash(string nombre);
        Nodo *crearNodo(string nombre, string numero, string email);
        void insertar(Nodo *nodo, int pos);
};


#endif // TABLAHASH_H_INCLUDED

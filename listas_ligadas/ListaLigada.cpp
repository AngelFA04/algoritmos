#include <iostream>
#include "ListaLigada.h"

using namespace std;

ListaLigada::ListaLigada() {
    ListaLigada::inicio = NULL;
    sizeLista = 0;
}

ListaLigada::~ListaLigada() {

}

Nodo *ListaLigada::creaNodo(int id, int valor){
    Nodo *aux = new Nodo;
    aux->id = id;
    aux->valor = valor;
    aux->siguiente = NULL;
    return aux;
}

bool ListaLigada::estaVacia(){
    return inicio == NULL;
}

void ListaLigada::enLista(Nodo *n){
    if(estaVacia()){
        inicio = n;
        fin = n;
    } else {
        fin->siguiente = n;
        fin = n;
    }
    sizeLista++;
}

void ListaLigada::insertaEn(Nodo *n, int pos){
    if(pos < 0 || pos > sizeLista){
        cout << "Error al insertar, posición inválida" << endl;
    } else {
        if(pos == 0){
            n->siguiente = inicio;
            inicio = n;
            sizeLista++;
        } else {
            Nodo *aux = inicio;
            for(int i = 0; i < pos - 1; i++){
                aux = aux->siguiente;
            }
            n->siguiente = aux->siguiente;
            aux->siguiente = n;
            sizeLista++;
        }
    }
}

Nodo *ListaLigada::removerDe(int pos){
    if(pos < 0 || pos > sizeLista){
        cout << "Error al remover, posición inválida" << endl;
        return NULL;
    } else {
        if(pos == 0){
            return desEnlista();
        } else {
            Nodo *aux = inicio;
            for(int i = 0; i < pos - 1; i++){
                aux = aux->siguiente;
            }
            Nodo *remover = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;
            remover->siguiente = NULL;
            return remover;
        }
    }
}

Nodo *ListaLigada::desEnlista(){
    if(estaVacia()){
        return NULL;
    } else {
        Nodo *aux = inicio;
        inicio = inicio -> siguiente;
        aux -> siguiente = NULL;
        sizeLista--;
        return aux;
    }
}

void ListaLigada::imprimeNodo(Nodo *n){
    if(n == NULL){
        return;
    }
    cout << "(" << n->id << ", " << n->valor << ") -> ";
}

void ListaLigada::imprimeLista(){
    for(Nodo *aux = inicio; aux != NULL; aux = aux->siguiente){
        imprimeNodo(aux);
    }
    cout << "FIN" << endl;
}

int ListaLigada::obtenTamanio(){
    return sizeLista;
}

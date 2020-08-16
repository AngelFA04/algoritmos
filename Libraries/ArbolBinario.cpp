#include <iostream>
#include "ArbolBinario.h"

using namespace std;

ArbolBinario::ArbolBinario(){
    raiz = NULL;
}

bool ArbolBinario::estaVacio(){
    return raiz == NULL;
}

Hoja *ArbolBinario::creaHoja(int dato){
    Hoja *h = new Hoja;
    h->dato = dato;
    h->der = NULL;
    h->izq = NULL;
    return h;
}

void ArbolBinario::insertHoja(Hoja *h, Hoja *r){
    if(h->dato < r->dato){
        if(r->izq == NULL){
            r->izq = h;
        } else {
            insertHoja(h, r->izq);
        }
    } else {
        if(r->der == NULL){
            r->der = h;
        } else {
            insertHoja(h, r->der);
        }
    }
}

void ArbolBinario::insertaHoja(int dato){
    insertaHoja(creaHoja(dato));
}

void ArbolBinario::insertaHoja(Hoja *h){
    if(raiz == NULL){
        raiz = h;
    } else {
        insertHoja(h, raiz);
    }
}

bool ArbolBinario::buscar(int dato){
    return buscarR(dato, raiz);
}

void ArbolBinario::imprimirPre(){
    cout << "[";
    preOrden(raiz);
    cout << "]" << endl;
}

void ArbolBinario::imprimirIn(){
    cout << "[";
    inOrden(raiz);
    cout << "]" << endl;
}

void ArbolBinario::imprimirPost(){
    cout << "[";
    postOrden(raiz);
    cout << "]" << endl;
}

void ArbolBinario::preOrden(Hoja *r){
    if(r != NULL){
        cout << r->dato << ", ";
        if(r->izq != NULL) preOrden(r->izq);
        if(r->der != NULL) preOrden(r->der);
    }
}

void ArbolBinario::inOrden(Hoja *r){
    if(r != NULL){
        if(r->izq != NULL) inOrden(r->izq);
        cout << r->dato << ", ";
        if(r->der != NULL) inOrden(r->der);
    }
}

void ArbolBinario::postOrden(Hoja *r){
    if(r != NULL){
        if(r->izq != NULL) postOrden(r->izq);
        if(r->der != NULL) postOrden(r->der);
        cout << r->dato << ", ";
    }
}

bool ArbolBinario::buscarR(int dato, Hoja *r){
    if(r==NULL){
        return false;
    } else {
        if(r->dato==dato){
            return true;
        } else {
            if(dato > r->dato){
                return buscarR(dato, r->der);
            } else {
                return buscarR(dato, r->izq);
            }
        }
    }
}

Hoja *ArbolBinario::podar(int dato){
    return podarR(dato, raiz, NULL);
}

Hoja *ArbolBinario::podarR(int dato, Hoja *r, Hoja *padre){
    if(r == NULL){
        return NULL;
    }
    if(r->dato == dato){
        if(r->izq == NULL && r->der == NULL){
            if(padre == NULL){
                raiz = NULL;
            } else if(padre->izq != NULL && padre->izq->dato == dato){
                padre->izq = NULL;
            } else if(padre->der != NULL && padre->der->dato == dato){
                padre->der = NULL;
            }
            return r;
        } else if(r->izq == NULL && r->der != NULL){
            Hoja *encontrado = r;
            if(padre == NULL){
                raiz = r->der;
            } else if(padre->izq != NULL && padre->izq->dato == dato){
                padre->izq = r->der;
            } else if(padre->der != NULL && padre->der->dato == dato){
                padre->der = r->der;
            }
            encontrado->der = NULL;
            return encontrado;
        }else if(r->izq != NULL && r->der == NULL){
            Hoja *encontrado = r;
            if(padre == NULL){
                raiz = r->izq;
            } else if(padre->izq != NULL && padre->izq->dato == dato){
                padre->izq = r->izq;
            } else if(padre->der != NULL && padre->der->dato == dato){
                padre->der = r->izq;
            }
            encontrado->izq = NULL;
            return encontrado;
        } else if(r->izq != NULL && r->der != NULL){
            Hoja *temp = r->der;
            Hoja *padreT = r;
            while(temp->izq != NULL){
                padreT = temp;
                temp = temp->izq;
            }
            if(padreT->dato == r->dato){
                padreT->der = temp->der;
            } else {
                padreT->izq = temp->der;
            }
            int tempD = dato;
            r->dato = temp->dato;
            temp->dato = tempD;
            temp->der = NULL;
            return temp;
        }
    } else {
        if(dato < r->dato){
            return podarR(dato, r->izq, r);
        } else {
            return podarR(dato, r->der, r);
        }
    }
    return NULL;
}

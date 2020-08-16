#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

struct Hoja{
    int dato;
    Hoja *izq;
    Hoja *der;
};

class ArbolBinario {
    public:
        ArbolBinario();
        bool estaVacio();
        Hoja *creaHoja(int dato);
        void insertaHoja(int dato);
        void imprimirIn();
        void imprimirPre();
        void imprimirPost();
        bool buscar(int dato);
        Hoja *podar(int dato);
    private:
        Hoja *raiz;
        void inOrden(Hoja *r);
        void preOrden(Hoja *r);
        void postOrden(Hoja *r);
        void insertaHoja(Hoja *h);
        void insertHoja(Hoja *h, Hoja *r);
        bool buscarR(int dato, Hoja *r);
        Hoja *podarR(int dato, Hoja *r, Hoja *padre);
};

#endif // ARBOLBINARIO_H

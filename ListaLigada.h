#ifndef LISTALIGADA_H
#define LISTALIGADA_H

struct Nodo{
    int valor;
    int id;
    Nodo *siguiente;
};

class ListaLigada {
    private:
        Nodo *inicio;
        Nodo *fin;
        int sizeLista;
    public:
        ListaLigada();
        virtual ~ListaLigada();
        void enLista(Nodo *n);
        void insertaEn(Nodo *n, int pos);
        Nodo *desEnlista();
        Nodo *removerDe(int pos);
        void imprimeLista();
        void imprimeNodo(Nodo *n);
        bool estaVacia();
        int obtenTamanio();
        Nodo *creaNodo(int id, int valor);
};

#endif // LISTALIGADA_H

#ifndef LISTALIGADA_H
#define LISTALIGADA_H

struct Nodo{
    int valor;
    int id;
    Nodo *siguiente;
};

class ListaLigada {
    private:
    public:
        ListaLigada();
        Nodo *inicio;
        int sizeLista;
        Nodo *fin;
        virtual ~ListaLigada();
        void agregar(int n);
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

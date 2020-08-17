#ifndef PRIM_H
#define PRIM_H


class Prim {
    public:
        Prim(int numeroNodos, int **matrizAdj);
        void calcularAEM();
    private:
        int numeroNodos;
        int *arbol;
        bool *visitados;
        int **matrizAdj;
        void imprimirSolucion();
        void inicializarValores();
        bool noVisiteTodos();
};

#endif // PRIM_H

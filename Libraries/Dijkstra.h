#ifndef DIJKSTRA_H
#define DIJKSTRA_H


class Dijkstra {
    public:
        Dijkstra(int numeroNodos, int **matrizAdj);
        void calcularDC(int scr);
    private:
        int numeroNodos;
        int *distancias;
        int *padres;
        bool *visitados;
        int **matrizAdj;
        int minDistancia();
        void imprimirSolucion(int scr);
        void imprimirCamino(int j);
        void inicializarValores(int scr);
};

#endif // DIJKSTRA_H

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H


class Ordenamiento{
    public:
        Ordenamiento();
        virtual ~Ordenamiento();
        void burbuja(int *datos, int sizeA);
        void seleccion(int *datos, int sizeA);
        void mergeSort(int *datos, int l, int r);
        void quickSort(int *datos, int l, int h);
        void bucketSort(int *datos, int sizeA);
        void imprime(int *datos, int sizeA);
        void imprimeAlreves(int *datos, int sizeA);

    private:
        void swap(int *v1, int *v2);
        int max(int *datos, int sizeA);
        void merge(int *datos, int l, int m, int r);
        int partition(int *datos, int l, int h);
};

#endif // ORDENAMIENTO_H

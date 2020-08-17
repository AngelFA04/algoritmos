#ifndef HEAP_H
#define HEAP_H

class Heap {
    public:
        Heap(bool minHeap);
        void encolar(int prioridad);
        int desencolar();
        void imprimirArreglo();
    private:
        bool minHeap;
        int arreglo[1023];
        int contador = 0;
        void balancearHeapMax(int i);
        void balancearHeapMin(int i);
};

#endif // HEAP_H

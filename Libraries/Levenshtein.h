#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <iostream>
#include <string>

using namespace std;

class Levenshtein{
    public:
        Levenshtein();
        int calcularDistancia(string palabra1, string palabra2);
    private:
        int masChico(int arriba, int derecha, int diagonal);
};

#endif // LEVENSHTEIN_H

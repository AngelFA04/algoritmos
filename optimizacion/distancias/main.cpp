#include <iostream>
#include "../../Libraries/Levenshtein.h"
#include <string>

int main(int argc, char const *argv[])
{

    string name;
    string names[20] = {"Alberto", "Maria", "Alex", "Juan", "Pedro", "Mariana", "Alan", "Jesica", "Luisa", "Luis", "Alejandra", "Mario", "Jesus", "Montserrat","Cristian", "Roberto", "Angel", "Alfredo", "Margarita", "Andres"};
    Levenshtein lev;
    

    cout << "Introduce tu nombre: ";
    cin >> name;
    int distance;
    int min = 100;
    string similar_name;
    // Comparar nombre de usario con nombres en Base de Datos
    for (int i = 0; i < 20; i++)
    {   
        distance = lev.calcularDistancia(name, names[i]);
        cout << "Distancias entre: " << name << " - " <<names[i] << " : " << distance << endl;
        if(distance <= min){
            min = distance;
            similar_name = names[i];
        }
    }
    cout << "El nombre más similar es: " << similar_name << endl; 

    //int dis = lev.calcularDistancia(string1, string2);
    //cout << dis;

    return 0;
}

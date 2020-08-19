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
    float percentage;
    float name_len;
    string similar_name;
    // Comparar nombre de usario con nombres en Base de Datos
    for (int i = 0; i < 20; i++)
    {   
        distance = lev.calcularDistancia(name, names[i]);
        name_len = names[i].length();
        //cout << "Distancias entre: " << name << " - " <<names[i] << " : " << distance << endl;
        if(distance <= min){
            min = distance;
            similar_name = names[i];
          //  cout << "Name len " << name_len;
            percentage =  (name_len -  distance) / name_len;
        }
    }
    cout << "El nombre más similar es: " << similar_name << " en un " << percentage << endl; 

    return 0;
}

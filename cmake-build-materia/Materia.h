#ifndef MATERIA_H
#define MATERIA_H

#include <string>
using namespace std;

class Materia {
private:
    string nombre;
    double calificacion;

public:

    Materia(string nombre, double calificacion);

    string getNombre();
    int getCalificacion();


    void mostrarInfo();

};

#endif


#ifndef MATERIA_H
#define MATERIA_H

#include <string>
using namespace std;

class Materia {
public:
    string nombre;
    double calificacion;

    Materia(const string& nombre, double calificacion = 0.0);
};

#endif

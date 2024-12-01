//
// Created by savda on 01/12/2024.
//

#ifndef ALUMNO_H
#define ALUMNO_H

#include "persona.h"
#include "materia.h"
#include <vector>

class Alumno : public Persona {
private:
    vector<Materia> materias;

public:
    Alumno(string nombre, string matricula);
    void agregarMateria(const Materia& materia);
    void asignarCalificacion(string nombreMateria, double calificacion);
    double calcularPromedio() const;
    void mostrarInformacion() const;
};

#endif // ALUMNO_H

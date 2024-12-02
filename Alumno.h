//
// Created by savda on 01/12/2024.
//

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"
#include "Materia.h"
#include <vector>

using namespace std;

class Alumno : public Persona {
private:
    vector<Materia> materias;

public:
    Alumno(const string& nombre, const string& matricula);

    void agregarMateria(const string& nombre);
    void asignarCalificacion(const string& nombreMateria, double calificacion);
    const vector<Materia>& getMaterias() const;
    double calcularPromedio() const;

    void consultarCalificaciones() const;
    void mostrarInformacion() const override;
};

#endif


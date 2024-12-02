//
// Created by Valeria Porcayo on 01/12/24.
//

#ifndef MAESTRO_H
#define MAESTRO_H
#include "Persona.h"
#include "Materia.h"
#include <string>
#include <vector>


class Maestro : public Persona {
private:
    int matricula;
    std::vector<Materia> materias;

public:
    Maestro(int matricula, std::string nombre, std::string direccion, int edad);

    int getMatricula() const;
    void agregarMateria(const Materia& materia);
    void verListaAlumnos() const;
    void asignarCalificacion(int matriculaAlumno, double calificacion);
    void verCalificaciones() const;
};

#endif //MAESTRO_H

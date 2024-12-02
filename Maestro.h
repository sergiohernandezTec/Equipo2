//
// Created by Valeria Porcayo on 01/12/24.
//

#ifndef MAESTRO_H
#define MAESTRO_H
#include <string>
#include <vector>
#include "Materia.h"

class Maestro {
private:
    std::string nombre;
    int id;
    std::vector<Materia> materiasAsignadas;

public:
    Maestro(const std::string& nombre, int id);
    void asignarMateria(const Materia& materia);
    void asignarCalificacion(const std::string& nombreMateria, int idAlumno, double calificacion);
    void verListaAlumnos();

    std::string getNombre() const;
    int getId() const;
    std::vector<Materia> getMaterias() const;
};

#endif //MAESTRO_H



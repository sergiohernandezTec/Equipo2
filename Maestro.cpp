//
// Created by Valeria Porcayo on 01/12/24.
//

#include "Maestro.h"
#include "Maestro.h"
#include <iostream>


Maestro::Maestro(const std::string& nombre, int id) : nombre(nombre), id(id) {}


void Maestro::asignarMateria(const Materia& materia) {
    materiasAsignadas.push_back(materia);
    std::cout << "Materia " << materia.getNombre() << " asignada a " << nombre << ".\n";
}


void Maestro::asignarCalificacion(const std::string& nombreMateria, int idAlumno, double calificacion) {
    for (auto& materia : materiasAsignadas) {
        if (materia.getNombre() == nombreMateria) {
            materia.asignarCalificacion(idAlumno, calificacion);
            std::cout << "Calificación asignada en " << nombreMateria << " al alumno ID: " << idAlumno << ".\n";
            return;
        }
    }
    std::cout << "Materia no encontrada.\n";
}

void Maestro::verListaAlumnos() {
    for (const auto& materia : materiasAsignadas) {
        std::cout << "Materia: " << materia.getNombre() << "\n";
        materia.verAlumnos();
    }
}

std::string Maestro::getNombre() const {
    return nombre;
}

int Maestro::getId() const {
    return id;
}

std::vector<Materia> Maestro::getMaterias() const {
    return materiasAsignadas;
}

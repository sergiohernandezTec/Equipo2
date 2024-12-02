//
// Created by Valeria Porcayo on 01/12/24.
//

#include "Maestro.h"
#include <iostream>

Maestro::Maestro(int matricula, std::string nombre, std::string direccion, int edad)
    : Persona(nombre, direccion, edad), matricula(matricula) {}

int Maestro::getMatricula() const {
    return matricula;
}

void Maestro::agregarMateria(const Materia& materia) {
    materias.push_back(materia);
}

void Maestro::verListaAlumnos() const {
    std::cout << "Lista de alumnos: \n";
    for (const auto& materia : materias) {
        materia.mostrarAlumnos();
    }
}

void Maestro::asignarCalificacion(int matriculaAlumno, double calificacion) {
    for (auto& materia : materias) {
        if (materia.tieneAlumno(matriculaAlumno)) {
            materia.asignarCalificacion(matriculaAlumno, calificacion);
            std::cout << "Calificación asignada a alumno con matrícula " << matriculaAlumno << std::endl;
        }
    }
}

void Maestro::verCalificaciones() const {
    for (const auto& materia : materias) {
        std::cout << "Materia: " << materia.getNombre() << " - Calificación: "
                  << materia.obtenerCalificacion() << std::endl;
    }
}

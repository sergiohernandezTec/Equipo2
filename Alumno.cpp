//
// Created by savda on 01/12/2024.
//

#include "alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(string nombre, string matricula) : Persona(nombre, matricula) {}

void Alumno::agregarMateria(const Materia& materia) {
    materias.push_back(materia);
}

void Alumno::asignarCalificacion(string nombreMateria, double calificacion) {
    for (Materia& materia : materias) {
        if (materia.getNombre() == nombreMateria) {
            materia.setCalificacion(calificacion);
            return;
        }
    }
    cout << "Materia no encontrada: " << nombreMateria << endl;
}

double Alumno::calcularPromedio() const {
    if (materias.empty()) return 0;
    double suma = 0;
    for (const Materia& materia : materias) {
        suma += materia.getCalificacion();
    }
    return suma / materias.size();
}

void Alumno::mostrarInformacion() const {
    Persona::mostrarInformacion();
    cout << "Materias y calificaciones:\n";
    for (const Materia& materia : materias) {
        materia.mostrarInformacion();
    }
    cout << "Promedio: " << calcularPromedio() << endl;
}

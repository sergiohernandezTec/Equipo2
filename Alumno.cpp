//
// Created by savda on 01/12/2024.
//

#include "Alumno.h"
#include <iostream>
#include <iomanip>

using namespace std;

Alumno::Alumno(const string& nombre, const string& matricula)
    : Persona(nombre, matricula) {}

void Alumno::agregarMateria(const string& nombre) {
    materias.emplace_back(nombre, 0.0);
}

void Alumno::asignarCalificacion(const string& nombreMateria, double calificacion) {
    for (auto& materia : materias) {
        if (materia.nombre == nombreMateria) {
            materia.calificacion = calificacion;
            return;
        }
    }
    cout << "Materia no encontrada.\n";
}

const vector<Materia>& Alumno::getMaterias() const {
    return materias;
}

double Alumno::calcularPromedio() const {
    if (materias.empty()) return 0.0;

    double suma = 0.0;
    for (const auto& materia : materias) {
        suma += materia.calificacion;
    }
    return suma / materias.size();
}

//INICIA CHAT GPT
void Alumno::consultarCalificaciones() const {
    cout << "Calificaciones de " << nombre << ":\n";
    for (const auto& materia : materias) {
        cout << "  - " << materia.nombre << ": "
             << fixed << setprecision(2) << materia.calificacion << "\n";
    }
    cout << "Promedio general: " << fixed << setprecision(2) << calcularPromedio() << "\n";
}
//TERMINA CHAT GPT

void Alumno::mostrarInformacion() const {
    consultarCalificaciones();
}
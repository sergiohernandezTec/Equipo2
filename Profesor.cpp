//
// Created by Valeria Porcayo on 01/12/24.
//
#include "Profesor.h"

Profesor::Profesor(const string& nombre, const string& matricula)
    : Persona(nombre, matricula) {}

void Profesor::asignarMateria(const string& nombreMateria) {
    materias.push_back(nombreMateria);
}

const vector<string>& Profesor::getMaterias() const {
    return materias;
}

bool Profesor::imparteMateria(const string& nombreMateria) const {
    for (const auto& materia : materias) {
        if (materia == nombreMateria) {
            return true;
        }
    }
    return false;
}

void Profesor::mostrarMaterias() const {
    cout << "Materias que imparte " << nombre << ":\n";
    for (const auto& materia : materias) {
        cout << "  - " << materia << "\n";
    }
}

void Profesor::mostrarInformacion() const {
    mostrarMaterias();
}

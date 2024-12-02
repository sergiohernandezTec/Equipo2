//
// Created by Valeria Porcayo on 01/12/24.
//

#include "Persona.h"

Persona::Persona(const string& nombre, const string& matricula)
    : nombre(nombre), matricula(matricula) {}

string Persona::getNombre() const {
    return nombre;
}

string Persona::getMatricula() const {
    return matricula;
}
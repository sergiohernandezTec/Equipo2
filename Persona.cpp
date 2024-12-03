//
// Created by savda on 01/12/2024.
//


#include "Profesor.h"
#include <iostream>

using namespace std;

#include "Persona.h"
Persona::Persona(const string& nombre, const string& matricula)
    : nombre(nombre), matricula(matricula) {}

string Persona::getNombre() const {
    return nombre;
}

string Persona::getMatricula() const {
    return matricula;
}






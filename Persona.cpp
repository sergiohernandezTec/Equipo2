//
// Created by savda on 01/12/2024.
//

#include "persona.h"
#include <iostream>
using namespace std;

Persona::Persona(string nombre, string matricula) : nombre(nombre), matricula(matricula) {}

string Persona::getNombre() const {
    return nombre;
}

string Persona::getMatricula() const {
    return matricula;
}

void Persona::mostrarInformacion() {
    cout << "Nombre: " << nombre << ", Matrícula: " << matricula << endl;
}





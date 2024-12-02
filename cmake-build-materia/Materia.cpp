#include "Materia.h"
#include <iostream>

using namespace std;


Materia::Materia(string nombre,  double calificacion) {
    this->nombre = nombre;
    this->calificacion = calificacion;
}


string Materia::getNombre() {
    return nombre;
}


int Materia::getCalificion() {
    return calificacion;
}


void Materia::mostrarInfo() {
    cout << "Materia: " << nombre << endl;
    cout << "Calificacion: " << creditos << endl;
}




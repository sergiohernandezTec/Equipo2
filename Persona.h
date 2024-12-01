//
// Created by savda on 01/12/2024.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    string matricula;

public:
    Persona(string nombre, string matricula);
    string getNombre() const;
    string getMatricula() const;
    void mostrarInformacion();
};

#endif // PERSONA_H
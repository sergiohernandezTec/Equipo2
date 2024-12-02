//
// Created by savda on 01/12/2024.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    string matricula;

public:
    Persona(const string& nombre, const string& matricula);

    string getNombre() const;
    string getMatricula() const;

    virtual void mostrarInformacion() const = 0; //CHAT GPT

    virtual ~Persona() = default; //CHAT GPT
};

#endif
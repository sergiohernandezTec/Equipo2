//
// Created by Valeria Porcayo on 01/12/24.
//

#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include "Persona.h"
#include <vector>

using namespace std;

class Profesor : public Persona {
private:
    vector<string> materias;

public:
    Profesor(const string& nombre, const string& matricula);

    void asignarMateria(const string& nombreMateria);
    const vector<string>& getMaterias() const;
    bool imparteMateria(const string& nombreMateria) const;
    void mostrarMaterias() const;
    void mostrarInformacion() const override;
};

#endif

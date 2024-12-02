//
// Created by islas on 30/11/2024.
//
#ifndef ESCUELA_H
#define ESCUELA_H
#include<iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Alumno.h"
#include "Profesor.h"

using namespace std;
class Escuela {
private:
    string nombre;
    string telefono;
    vector<Alumno> alumnos;
    vector<Profesor> profesores;
    //vector<materia>materias;
    double promGeneral;

public:
    Escuela(string _nombre, string _telefono);
    void guardarAlumnos(const vector<Alumnos>& alumnos);
    void cargarAlumnos(vector<Alumno>& alumnos);
    void guardarProfesores(const vector<Profesor>& profesores);
    void cargarProfesores(vector<Profesor>& profesores);
    void mostrarMenu();
};



#endif //ESCUELA_H

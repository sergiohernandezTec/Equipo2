//
// Created by islas on 30/11/2024.
//
#ifndef ESCUELA_H
#define ESCUELA_H
#include <string>
#include <vector>
using namespace std;
class Escuela {
private:
    string nombre;
    string telefono;
    //vector<alunmo>alumnos;
    //vector<profesor>profesores;
    //vector<calificacion>calificaciones;
    //vector<materia>materias;
    double promGeneral;

public:
    Escuela(string _nombre, string _telefono);
    void inscribirAlumno();
    double getPromGeneral();
    void menuAdministrador();
    void menuProfes();
    void menuAlumnos();
};



#endif //ESCUELA_H

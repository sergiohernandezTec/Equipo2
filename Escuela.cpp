//
// Created by islas on 30/11/2024.
//
#include "Escuela.h"
Escuela:: Escuela(string _nombre, string _telefono){
  nombre = _nombre;
  telefono = _telefono;
}
void Escuela::inscribirAlumno(Alumno a) {
    alumnos.push_back(a);
}
void Escuela::contratarProfesor(Profesor p) {
    profesores.push_back(p);
}




void Escuela::guardarAlumnos(const vector<Alumno>& alumnos) {
    ofstream archivo("alumnos.txt");
    if (!archivo.is_open()) {
        cerr << "Error al guardar los alumnos.\n";
        return;
    }
    for (const auto& alumno : alumnos) {
        archivo << alumno.getNombre() << "\n";
        archivo << alumno.getMatricula() << "\n";
        for (const auto& materia : alumno.getMaterias()) {
            archivo << materia.nombre << "|" << materia.calificacion << "\n";
        }
        archivo << "#\n";
    }
    archivo.close();
}


void Escuela::cargarAlumnos(vector<Alumno>& alumnos) {
    ifstream archivo("alumnos.txt");
    if (!archivo.is_open()) {
        cerr << "No se encontraron datos de alumnos.\n";
        return;
    }
    string nombre, matricula, linea;
    while (getline(archivo, nombre)) {
        getline(archivo, matricula);
        Alumno alumno(nombre, matricula);
        while (getline(archivo, linea) && linea != "#") {
            size_t pos = linea.find('|');
            string materia = linea.substr(0, pos);
            double calificacion = stof(linea.substr(pos + 1));
            alumno.agregarMateria(materia);
            alumno.asignarCalificacion(materia, calificacion);
        }
        alumnos.push_back(alumno);
    }
    archivo.close();
}


void Escuela::guardarProfesores(const vector<Profesor>& profesores) {
    ofstream archivo("profesores.txt");
    if (!archivo.is_open()) {
        cerr << "Error al guardar los profesores.\n";
        return;
    }
    for (const auto& profesor : profesores) {
        archivo << profesor.getNombre() << "\n";
        archivo << profesor.getMatricula() << "\n";
        for (const auto& materia : profesor.getMaterias()) {
            archivo << materia << "\n";
        }
        archivo << "#\n";
    }
    archivo.close();
}

void Escuela::cargarProfesores(vector<Profesor>& profesores) {
    ifstream archivo("profesores.txt");
    if (!archivo.is_open()) {
        cerr << "No se encontraron datos de profesores.\n";
        return;
    }
    string nombre, matricula, linea;
    while (getline(archivo, nombre)) {
        getline(archivo, matricula);
        Profesor profesor(nombre, matricula);
        while (getline(archivo, linea) && linea != "#") {
            profesor.asignarMateria(linea);
        }
        profesores.push_back(profesor);
    }
    archivo.close();
}
//TERMINA CHAT GPT
void Escuela::mostrarMenu() {
    cout<<"\n___________________________________"
                      "\n\tOpciones administrador"
                      "\n1. Inscribir alumno."
                      "\n2. Contratar profesor"
                      "\n3. Asignar materia a un alumno"
                      "\n4. Asignar materia a un profesor"
                      "\n5. Consultar materias de un profesor"
                      "\n___________________________________\n";
}

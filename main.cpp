#include <iostream>
#include "Escuela.h"
#include <algorithm>
#include <inttypes.h>
using namespace std;

int main() {
    Escuela Escuela("Tec de Monterrey", "1234567890");
    int opcion;
    string contrasenia;

    menu1:
    cout<<"\n___________________________________"
          "\n\tSistema de Escuela"<<endl;
    cout<<"\tMenu de opciones "
    "\n1. Opciones de administrador."
    "\n2. Opcion para profesores(Calificar)."
    "\n3. Opcion para alumnos(Consulta de calificaciones)."
    "\n___________________________________\n"
    "\nSelecciona una opcion:";
    cin>>opcion;

    while (opcion>3 || opcion <1) {
        cout<<"Ingresa un opcion valida:"<<endl;
        goto menu1;
    }
    switch (opcion) {
        case 1: {
            int opcionAdmin;
            int opContrasenia;
            do {
                cout<<"\nHa seleccionado opciones para administrador"
                  "\nEs necesario ingresar la contrasenia"
                  "\n1. Ingresar "
                  "\t2. Regresar"
                  "\nIngresa una opcion:";
                cin>>opContrasenia;
                if (opContrasenia>2 || opContrasenia<1) {
                    cout<<"Ingresa una opcion valida."<<endl;
                }
            }while (opContrasenia>2 || opContrasenia<1);
            if (opContrasenia==1) {
                cout<<"Ingresa la contrasenia:(contrasenia: admin):"; cin>>contrasenia;
                while (contrasenia != "admin") {
                    cout<<"Contrasenia incorrecta intente de nuevo: ";cin>>contrasenia;
                }
                cout<<"Contrasenia correcta.";
                menuAD:
                Escuela.mostrarMenu();
                cout<<"Ingrese una opcion:";cin>>opcionAdmin;
                if (opcionAdmin==1){
                    string nombre, matricula;
                    cout << "Nombre del alumno: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Matricula del alumno: ";
                    getline(cin, matricula);
                    Alumno alumno(nombre, matricula);
                    Escuela.inscribirAlumno(alumno);
                    cout << "Alumno agregado correctamente.\n";
                }
                else if (opcionAdmin==2){
                    string nombre, matricula;
                    cout << "Nombre del profesor: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Matricula del profesor: ";
                    getline(cin, matricula);
                    Profesor profesor(nombre, matricula);
                    Escuela.contratarProfesor(profesor);
                    cout << "Profesor agregado correctamente.\n";
                }
                else if (opcionAdmin==3){
                    string matricula, materia;
                    cout << "Ingrese la matricula del alumno: ";
                    cin >> matricula;
                    cout << "Ingrese el nombre de la materia: ";
                    cin.ignore();
                    getline(cin, materia);

                    auto i = find_if(Escuela.alumnos.begin(), Escuela.alumnos.end(), [&matricula](const Alumno& alumno) {
                        return alumno.getMatricula() == matricula;
                    });

                    if (i != Escuela.alumnos.end()) {
                        i->agregarMateria(materia);
                        cout << "Materia asignada correctamente.\n";
                    } else {
                        cout << "Alumno no encontrado.\n";
                    }

                }
                else if (opcionAdmin==4) {
                    string matricula, materia;
                    cout << "Ingrese la matricula del profesor: ";
                    cin >> matricula;

                    auto i = find_if(Escuela.profesores.begin(), Escuela.profesores.end(), [&matricula](const Profesor& profesor) {
                        return profesor.getMatricula() == matricula;
                    });

                    if (i != Escuela.profesores.end()) {
                        cout << "Ingrese la materia a asignar: ";
                        cin.ignore();
                        getline(cin, materia);
                        i->asignarMateria(materia);
                        cout << "Materia asignada correctamente al profesor.\n";
                    } else {
                        cout << "Profesor no encontrado.\n";

                    }
                }
                else if (opcionAdmin==5) {
                    cout<<"Lista de profesores: "<<endl;
                    for (int i = 0; i < Escuela.profesores.size(); i++) {
                        Escuela.profesores[i].mostrarInformacion();

                    }
                    string matricula;
                    cout << "Ingrese la matricula del profesor: ";
                    cin >> matricula;

                    auto it = find_if(Escuela.profesores.begin(), Escuela.profesores.end(), [&matricula](const Profesor& profesor) {
                        return profesor.getMatricula() == matricula;
                    });

                    if (it != Escuela.profesores.end()) {
                        it->mostrarMaterias();
                    } else {
                        cout << "Profesor no encontrado.\n";
                    }
                }else {
                    cout<<"Ingresa una opcion valida."<<endl;
                    goto menuAD;
                }
            }else{
                goto menu1;
            }
            int opcionF;
            cout<<"\nDesea realizar otra operacion?"
                  "\n1. Menu administrador"
                  "\n2. Menu inicial"
                  "\n3. No"
                  "\nIngrese una opcion: ";cin>>opcionF;
            if(opcionF==1) {
                goto menuAD;
            }else if (opcionF==2){
                goto menu1;
            }else {
                cout<<"Gracias por usar el sistema de escuela :)"<<endl;
            }
            break;
        }//Break del caso 1
        case 2: {
            string matriculaProfesor, matriculaAlumno, materia;
            double calificacion;
            mtNOencontrada:
            cout << "Ingrese la matricula del profesor: ";
            cin >> matriculaProfesor;

            auto iProfesor = find_if(Escuela.profesores.begin(), Escuela.profesores.end(), [&matriculaProfesor](const Profesor& profesor) {
                return profesor.getMatricula() == matriculaProfesor;
            });

            if (iProfesor == Escuela.profesores.end()) {
                cout << "Profesor no encontrado.\n";
                int opcionP;
                cout<<"\nDesea intentar de nuevo?"
                      "\n1. Si"
                      "\n2. No"
                      "\n3. Regresar al menu inicial"
                      "\nIngrese una opcion: ";cin>>opcionP;
                if(opcionP==1) {
                    goto mtNOencontrada;;
                }else if (opcionP==2){
                    cout<<"Gracias por usar el sistema de escuela :)"<<endl;
                }else {
                    goto menu1;
                }
            }
            materiaNOencontrada:

            cout << "Ingrese la materia: ";
            cin.ignore();
            getline(cin, materia);

            if (!iProfesor->imparteMateria(materia)) {
                cout << "El profesor no imparte esta materia o materia no existente.\n";
                int opcionM;
                cout<<"\nDesea intentar de nuevo?"
                      "\n1. Si"
                      "\n2. No"
                      "\n3. Regresar al menu inicial"
                      "\nIngrese una opcion: ";cin>>opcionM;
                if(opcionM==1) {
                    goto materiaNOencontrada;
                }else if (opcionM==2){
                    cout<<"Gracias por usar el sistema de escuela :)"<<endl;
                }else {
                    goto menu1;
                }
            }

            mtAlumnoNoEncontrada:
            cout << "Ingrese la matricula del alumno: ";
            cin >> matriculaAlumno;

            auto iAlumno = find_if(Escuela.alumnos.begin(), Escuela.alumnos.end(), [&matriculaAlumno](const Alumno& alumno) {
                return alumno.getMatricula() == matriculaAlumno;
            });

            if (iAlumno == Escuela.alumnos.end()) {
                cout << "Alumno no encontrado.\n";
                int opcionA;
                cout<<"\nDesea intentar de nuevo?"
                      "\n1. Si"
                      "\n2. No"
                      "\n3. Regresar al menu inicial"
                      "\nIngrese una opcion: ";cin>>opcionA;
                if(opcionA==1) {
                    goto mtAlumnoNoEncontrada;
                }else if (opcionA==2){
                    cout<<"Gracias por usar el sistema de escuela :)"<<endl;
                }else {
                    goto menu1;
                }
            }

            cout << "Ingrese la calificacion: ";
            cin >> calificacion;

            iAlumno->asignarCalificacion(materia, calificacion);
            cout << "Calificacion asignada correctamente.\n";
            int opcionF2;
            cout<<"\n¿Desea realizar otra operacion?"
                  "\n1. Menu incial"
                  "\n2. Salir"
                  "\nIngrese una opcion: ";cin>>opcionF2;
            if(opcionF2==1) {
                goto menu1;
            }else {
                cout<<"Gracias por usar el sistema de escuela :)"<<endl;
            }

            break;
        }//Break del caso 2
        case 3: {
            alumno:
            string matriculaA;
            cout << "Ingrese la matricula del alumno: ";
            cin >> matriculaA;
            auto i = find_if(Escuela.alumnos.begin(), Escuela.alumnos.end(), [&matriculaA](const Alumno& alumno) {
                return alumno.getMatricula() == matriculaA;
            });

            if (i != Escuela.alumnos.end()) {
                i->consultarCalificaciones();
            } else {
                cout << "Alumno no encontrado.\n";
            }
            int opcionF3;
            cout<<"\nDesea intentar de nuevo?"
                  "\n1. Si"
                  "\n2. No"
                  "\n3. Regresar al menu inicial"
                  "\nIngrese una opcion: ";cin>>opcionF3;
            if(opcionF3==1) {
                goto alumno;
            }else if (opcionF3==2){
                cout<<"Gracias por usar el sistema de escuela :)"<<endl;
            }else {
                goto menu1;
            }

            break;
        }//Break del caso 3
        default: {
            break;
        }//Break del default option

    }



    return 0;
}
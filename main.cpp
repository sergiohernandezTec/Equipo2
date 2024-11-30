#include <iostream>
#include "Escuela.h"
using namespace std;

int main() {
    Escuela Escuela("Tec de Monterrey", "1234567890");
    int opcion;

    menu1:
    cout<<"\n\tSistema de Escuela"<<endl;
    cout<<"\tMenu de opciones "
    "\n1. Opciones de administrador."
    "\n2. Opciones para profesores."
    "\n3. Opciones para alumnos."
    "\nSelecciona una opción:";
    cin>>opcion;

    while (opcion>3 || opcion <1) {
        cout<<"Ingresa un opcion valida:"<<endl;
        goto menu1;
    }
    switch (opcion) {
        case 1:
            int opContrasenia;
            do {
                cout<<"\nHa seleccionado opciones para administrador"
                  "\nEs necesario ingresar la contraseña"
                  "\n1. Ingresar "
                  "\t2. Regresar"<<endl;
                cin>>opContrasenia;
                if (opContrasenia>2 || opContrasenia<1) {
                    cout<<"Ingresa una opcion valida."<<endl;
                }
            }while (opContrasenia>2 || opContrasenia<1);


            break;
        case 2:
            break;
        case 3:
            break;

    }



    return 0;
}
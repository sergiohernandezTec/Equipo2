cmake_minimum_required(VERSION 3.29.6)
project(Equipo2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Equipo2 main.cpp
        Escuela.cpp
        Escuela.h
        Persona.cpp
        Persona.h
        Profesor.cpp
        Profesor.h
        Alumno.cpp
        Alumno.h
        Materia.cpp
        Materia.h
)

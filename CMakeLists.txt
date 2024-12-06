cmake_minimum_required(VERSION 3.28.1)
project(EA3_ProyectoFinal_Fase1)

set(CMAKE_CXX_STANDARD 14)

# Incluye los directorios donde están los encabezados (.h)
include_directories(include)

# Se deben agregar solo los archivos .cpp en add_executable
add_executable(EA3_ProyectoFinal_Fase1
        src/Conductor.cpp
        src/Taxi.cpp
        src/RegistroTaxiConductor.cpp
        main.cpp
        src/FlotaManager.cpp
        src/ArchivoManager.cpp
        src/UserInterface.cpp
        src/Viajes.cpp
)
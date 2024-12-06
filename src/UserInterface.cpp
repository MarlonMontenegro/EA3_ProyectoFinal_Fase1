#include "UserInterface.h"
#include <iostream>
#include <cstdlib>


int UserInterface::seleccionarCategoria() {
    int eleccionDeCategoria;
    std::cout << "Por favor, seleccione el tipo de taxi que desea solicitar:\n";
    std::cout << "1. Taxi Tradicional\n";
    std::cout << "2. Taxi Ejecutivo\n";
    std::cout << "Ingrese el numero correspondiente a su eleccion: ";
    std::cin >> eleccionDeCategoria;
    return eleccionDeCategoria;
}

double UserInterface::seleccionTarifa() {
    double tarifa;
    std::cout << "Por favor, ingrese la tarifa.\n";
    std::cin >> tarifa;
    return tarifa;
}

Taxi UserInterface::registrarTaxi() {
    std::string placa;
    std::string numMotor;
    std::string modelo;
    int anio;

    std::cout << "============================================" << std::endl;
    std::cout << "!Registro de Taxi!" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Ingrese la placa del taxi:" << std::endl;
    std::getline(std::cin >> std::ws, placa);
    std::cout << "Ingrese el numero de motor:" << std::endl;
    std::getline(std::cin >> std::ws, numMotor);
    std::cout << "Ingrese el modelo:" << std::endl;
    std::getline(std::cin >> std::ws, modelo);
    std::cout << "Ingrese el anio del vehiculo:" << std::endl;
    std::cin >> anio;


    Taxi theTaxi(placa, numMotor, modelo, anio);

    return theTaxi;
}

Conductor UserInterface::registrarConductor() {
    std::string nombre;
    std::string apellido;
    std::string documento;
    std::string seguroSocial;
    std::string telefono;
    std::cout << "============================================" << std::endl;
    std::cout << "!Registro de Conductor!" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Ingrese su nombre:" << std::endl;
    std::getline(std::cin >> std::ws, nombre);
    std::cout << "Ingrese el numero de documento" << std::endl;
    std::getline(std::cin >> std::ws, documento);
    std::cout << "Ingrese el numero del seguro social:" << std::endl;
    std::getline(std::cin >> std::ws, seguroSocial);
    std::cout << "Ingrese el numero de telefono" << std::endl;
    std::getline(std::cin >> std::ws, telefono);
    Conductor theConductor(nombre, documento, seguroSocial, telefono);

    return theConductor;
}

void UserInterface::menu() {
    // Colores ANSI para la terminal

    // Título
    std::cout << "=====================================" << std::endl;
    std::cout << "  Bienvenido al sistema de gestion  " << std::endl;
    std::cout << "            de taxis              " << std::endl;
    std::cout << "=====================================" << std::endl;

    // Opciones del menú
    std::cout << "1." << " Registrar taxi." << std::endl;
    std::cout << "2." << " Mostrar taxis." << std::endl;
    std::cout << "3." << " Ver datos de Conductor." << std::endl;
    std::cout << "4." << " Iniciar Viaje." << std::endl;
    std::cout << "5." << " Ver taxis en Ruta." << std::endl;
    std::cout << "6." << " Taxis Disponibles." << std::endl;
    std::cout << "7." << " Finalizar Viaje." << std::endl;
    std::cout << "8." << " Reportes." << std::endl;
    std::cout << "9." << " Salir." << std::endl;


    // Solicitar opción
    std::cout << "\nPor favor, ingresa una opcion: ";
}

void UserInterface::menuReportes() {
    std::cout << "=====================================" << std::endl;
    std::cout << "  Bienvenido al sistema de reportes  " << std::endl;
    std::cout << "            de taxis                 " << std::endl;
    std::cout << "=====================================" << std::endl;

    // Opciones del menú
    std::cout << "1." << " Listado de Viajes" << std::endl;
    std::cout << "2." << " Listado de viajes por vehiculo" << std::endl;
    std::cout << "3." << " Ingresos totales obtenidos en un mes" << std::endl;
    std::cout << "4." << " Ingresos totales obtenidos en un mes por vehiculo" << std::endl;
    std::cout << "8." << " Salir." << std::endl;

    // Solicitar opción
    std::cout << "\nPor favor, ingresa una opcion: ";
}


void UserInterface::limpiarPantalla() {
    system("cls");
}

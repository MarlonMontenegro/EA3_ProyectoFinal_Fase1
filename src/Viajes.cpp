#include "Viajes.h"
#include <chrono>
#include <FlotaManager.h>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <UserInterface.h>

Viajes::Viajes()
    : conductor(Conductor()), taxi(Taxi()), dineroGenerado(0.0), numViajes(0) {
    inicio = "";
}

Viajes::Viajes(Conductor conductor, Taxi taxi, double dineroGenerado)
    : conductor(std::move(conductor)), taxi(std::move(taxi)), dineroGenerado(dineroGenerado), numViajes(1) {
    inicio = obtenerHoraActual();
}

Viajes::Viajes(Conductor conductor, Taxi taxi, double dineroGenerado, std::string inicio, int numViajes)
    : conductor(std::move(conductor)), taxi(std::move(taxi)), dineroGenerado(dineroGenerado),
      inicio(std::move(inicio)), numViajes(numViajes) {
}

// Obtener la hora actual
std::string Viajes::obtenerHoraActual() {
    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    std::tm *tiempoLocal = std::localtime(&tiempoActual);

    std::ostringstream oss;
    oss << std::put_time(tiempoLocal, "%d/%m/%Y");
    return oss.str();
}

std::string Viajes::toString() const {
    std::ostringstream oss;
    oss << "Conductor: " << conductor.getNombre()
            << ", Taxi: " << taxi.getPlaca()
            << ", Inicio: " << inicio
            << ", Dinero generado: $" << dineroGenerado;
    return oss.str();
}

double Viajes::getDineroGenerado() const {
    return dineroGenerado;
}

const std::string &Viajes::getInicio() const {
    return inicio;
}

Conductor Viajes::getConductor() const {
    return conductor;
}

Taxi Viajes::getTaxi() const {
    return taxi;
}

int Viajes::getNumViajes() const {
    return numViajes;
}



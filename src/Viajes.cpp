#include "Viajes.h"
#include <chrono>
#include <iomanip>
#include <sstream>

// Constructor
Viajes::Viajes(Conductor& conductor, Taxi& taxi, double dineroGenerado)
    : conductor(conductor), taxi(taxi), dineroGenerado(dineroGenerado) {
    inicio = obtenerHoraActual();
    fin = "";
}

// Finalizar viaje
void Viajes::finalizarViaje() {
    fin = obtenerHoraActual();
}

// Obtener la hora actual
std::string Viajes::obtenerHoraActual() {
    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    std::ostringstream oss;
    oss << std::put_time(tiempoLocal, "%d/%m/%Y %H:%M");
    return oss.str();
}

// Convertir a cadena de texto
std::string Viajes::toString() const {
    std::ostringstream oss;
    oss << "Conductor: " << conductor.getNombre()
        << ", Taxi: " << taxi.getPlaca()
        << ", Inicio: " << inicio
        << ", Fin: " << (fin.empty() ? "En curso" : fin)
        << ", Dinero generado: $" << dineroGenerado;
    return oss.str();
}

// Getters
double Viajes::getDineroGenerado() const {
    return dineroGenerado;
}

const std::string& Viajes::getInicio() const {
    return inicio;
}

const std::string& Viajes::getFin() const {
    return fin;
}

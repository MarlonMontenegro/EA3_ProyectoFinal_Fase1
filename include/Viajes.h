#ifndef VIAJES_H
#define VIAJES_H

#include <string>
#include <vector>
#include "Conductor.h"
#include "Taxi.h"

class Viajes {
private:
    Conductor conductor; // Ahora es un objeto, no una referencia
    Taxi taxi; // Ahora es un objeto, no una referencia
    std::string inicio;
    double dineroGenerado;
    int numViajes;

    static std::string obtenerHoraActual();

public:
    // Constructores
    Viajes();

    Viajes(Conductor conductor, Taxi taxi, double dineroGenerado);

    Viajes(Conductor conductor, Taxi taxi, double dineroGenerado, std::string inicio, int numViajes);

    // Métodos
    std::string toString() const;

    // Getters
    double getDineroGenerado() const;

    const std::string &getInicio() const;

    Conductor getConductor() const;
    Taxi getTaxi() const;
    int getNumViajes() const;

    void listadoDeViajes();
};

#endif // VIAJES_H

#ifndef VIAJES_H
#define VIAJES_H

#include <string>
#include "Conductor.h"
#include "Taxi.h"

class Viajes {
private:
    Conductor& conductor;
    Taxi& taxi;
    std::string inicio;
    std::string fin;
    double dineroGenerado;

    static std::string obtenerHoraActual();

public:
    Viajes(Conductor& conductor, Taxi& taxi, double dineroGenerado);
    void finalizarViaje();
    std::string toString() const;
    double getDineroGenerado() const;
    const std::string& getInicio() const;
    const std::string& getFin() const;
};

#endif // VIAJES_H

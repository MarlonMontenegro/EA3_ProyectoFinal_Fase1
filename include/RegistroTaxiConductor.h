#ifndef REGISTRO_TAXI_CONDUCTOR_H
#define REGISTRO_TAXI_CONDUCTOR_H

#include <string>
#include "Taxi.h"
#include "Conductor.h"

class RegistroTaxiConductor {
public:
    Conductor conductor;
    Taxi taxi;

    RegistroTaxiConductor(Conductor c, Taxi t);
    RegistroTaxiConductor();

    void mostrarInfo() const;
    std::string toString() const;
};

#endif // REGISTRO_TAXI_CONDUCTOR_H

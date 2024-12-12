#include "RegistroTaxiConductor.h"
#include <iostream>

RegistroTaxiConductor::RegistroTaxiConductor(Conductor c, Taxi t)
    : conductor(std::move(c)), taxi(std::move(t)) {}

RegistroTaxiConductor::RegistroTaxiConductor() : conductor(), taxi() {}

void RegistroTaxiConductor::mostrarInfo() const {
    conductor.mostrarInformacion(); // Llama al método de la clase Conductor

    taxi.mostrarInformacion(); // Llama al método de la clase Taxi

    std::cout << "========================================" << std::endl;
}
std::string RegistroTaxiConductor::toString() const {
    return taxi.getPlaca() + "\t" +
           taxi.getModelo() + "\t" +
           taxi.getNumeroMotor() + "\t" +
           std::to_string(taxi.getAnio()) + "\t" +
           taxi.getCategoria() + "\t" +
           conductor.getNombre() + "\t" +
           conductor.getDocumentoIdentidad() + "\t" +
           conductor.getTelefono() + "\t" +
           conductor.getNumeroSeguroSocial();
}

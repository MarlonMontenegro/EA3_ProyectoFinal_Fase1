#include "Conductor.h"
#include <iostream>


Conductor::Conductor()
    : nombreCompleto(""), documento(""), seguroSocial(""), telefono("") {
    // Constructor predeterminado que inicializa los atributos con valores vacíos o por defecto
}


// Getters
std::string Conductor::getNombre() const { return nombreCompleto; }
std::string Conductor::getDocumentoIdentidad() const { return documento; }
std::string Conductor::getNumeroSeguroSocial() const { return seguroSocial; }
std::string Conductor::getTelefono() const { return telefono; }

// Métodos para mostrar informacion del conductor.
void Conductor::mostrarInformacion() const {
    std::cout << "Conductor: " << nombreCompleto << "\n"
            << "Documento de Identidad: " << documento << "\n"
            << "Seguro Social: " << seguroSocial << "\n"
            << "Teléfono: " << telefono << std::endl;
}

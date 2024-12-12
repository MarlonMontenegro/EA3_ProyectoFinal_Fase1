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


// Método para mostrar la información del conductor
void Conductor::mostrarInformacion() const {
    std::cout << "\n=============================" << std::endl;
    std::cout << "   Informacion del Conductor " << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Nombre completo:     " << nombreCompleto << std::endl;
    std::cout << "Documento de Identidad: " << documento << std::endl;
    std::cout << "Seguro Social:       " << seguroSocial << std::endl;
    std::cout << "Telefono:            " << telefono << std::endl;
}

std::istream &operator>>(std::istream &is, Conductor &conductor) {
    is >> conductor.nombreCompleto;
    return is;
}
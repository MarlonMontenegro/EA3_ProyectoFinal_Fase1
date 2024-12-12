#include "ArchivoManager.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <RegistroTaxiConductor.h>

void ArchivoManager::guardarRegistroUnico(const RegistroTaxiConductor &registro) const {
    std::ofstream archivo(path, std::ios::app); // Abrir en modo agregar

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << path << std::endl;
        return;
    }

    if (archivo.tellp() == 0) {
        archivo << std::left
                << std::setw(10) << "Index"
                << std::setw(15) << "Placa"
                << std::setw(20) << "Modelo"
                << std::setw(20) << "Motor"
                << std::setw(10) << "Año"
                << std::setw(15) << "Categoria"
                << std::setw(25) << "Nombre del Conductor"
                << std::setw(20) << "Documento de Identidad"
                << std::setw(15) << "Telefono"
                << std::setw(15) << "Seguro Social"
                << "\n";
    }

    int currentIndex = 0;
    std::ifstream leerArchivo(path);
    std::string linea;
    while (std::getline(leerArchivo, linea)) {
        if (!linea.empty() && linea.find("Index") == std::string::npos) {
            currentIndex++;
        }
    }
    leerArchivo.close();

    archivo << std::left
            << std::setw(10) << currentIndex
            << std::setw(15) << registro.taxi.getPlaca()
            << std::setw(20) << registro.taxi.getModelo()
            << std::setw(20) << registro.taxi.getNumeroMotor()
            << std::setw(10) << registro.taxi.getAnio()
            << std::setw(15) << registro.taxi.getCategoria()
            << std::setw(25) << registro.conductor.getNombre()
            << std::setw(20) << registro.conductor.getDocumentoIdentidad()
            << std::setw(15) << registro.conductor.getTelefono()
            << std::setw(15) << registro.conductor.getNumeroSeguroSocial()
            << "\n";

    archivo.close();

    std::cout << "Registro guardado con índice: " << currentIndex << " en el archivo: " << path << std::endl;
}

void ArchivoManager::guardarViajeIndividual(const Viajes &viaje) {
    const std::string path_viajes = "../data/TRANSACTION_LOG.txt";

    bool archivoVacio = true;
    std::ifstream archivoLectura(path_viajes);
    if (archivoLectura.is_open()) {
        archivoVacio = archivoLectura.peek() == std::ifstream::traits_type::eof(); // Verifica si el archivo está vacío
        archivoLectura.close();
    }

    std::ofstream archivo(path_viajes, std::ios::app);
    if (archivo.is_open()) {
        if (archivoVacio) {
            archivo << std::left << std::setw(20) << "Conductor"
                    << std::setw(15) << "Taxi"
                    << std::setw(20) << "Inicio"
                    << std::setw(20) << "Dinero Generado"
                    << std::setw(15) << "Num Viajes"
                    << "\n";
        }

        archivo << std::left
                << std::setw(15) << viaje.getConductor().getNombre()
                << std::setw(15) << viaje.getTaxi().getPlaca()
                << std::setw(20) << viaje.getInicio()
                << std::setw(20) << std::fixed << std::setprecision(2) << viaje.getDineroGenerado()
                << std::setw(15) << viaje.getNumViajes()
                << "\n";

        archivo.close();
        std::cout << "Viaje guardado en formato de tabla en el archivo: " << path_viajes << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para guardar el viaje." << std::endl;
    }
}
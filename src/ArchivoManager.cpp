#include "ArchivoManager.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <RegistroTaxiConductor.h>


void ArchivoManager::guardarRegistrosEnArchivo(const std::vector<RegistroTaxiConductor> &registros) const {
    std::ofstream archivo(path, std::ios::app); // Abrir en modo de añadir
    if (archivo.is_open()) {
        // Escribir encabezados solo si el archivo está vacío
        archivo.seekp(0, std::ios::end); // Mover al final del archivo

        if (archivo.tellp() == 0) {
            // Si está vacío, escribir encabezados
            archivo <<
                    "Index\tPlaca\tModelo\tNúmero de Motor\tAño\tCategoría\tNombre del Conductor\tDocumento de Identidad\tTeléfono\tSeguro Social\n";
        }

        // Obtener el número actual de registros en el archivo para calcular el índice
        int currentIndex = 0;
        std::ifstream leerArchivo(path);
        std::string linea;
        while (std::getline(leerArchivo, linea)) {
            if (!linea.empty() && linea.find("Index") == std::string::npos) {
                currentIndex++;
            }
        }
        leerArchivo.close();

        // Guardar los registros con índices
        for (const auto &registro: registros) {
            archivo << currentIndex++ << "\t" << registro.toString() << "\n";
        }

        archivo.close();
        std::cout << "Registros guardados correctamente en: " << path << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo: " << path << std::endl;
    }
}

void ArchivoManager::guardarRegistroUnico(const RegistroTaxiConductor &registro) const {
    std::ofstream archivo(path, std::ios::app); // Abrir en modo agregar
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << path << std::endl;
        return;
    }

    if (archivo.tellp() == 0) {
        // Si está vacío, escribir encabezados
        archivo <<
                "Index\tPlaca\tModelo\tNúmero de Motor\tAño\tCategoría\tNombre del Conductor\tDocumento de Identidad\tTeléfono\tSeguro Social\n";
    }

    // Calcular el índice actual
    int currentIndex = 0;
    std::ifstream leerArchivo(path); // Reabrir en modo lectura para contar líneas
    std::string linea;
    while (std::getline(leerArchivo, linea)) {
        if (!linea.empty() && linea.find("Index") == std::string::npos) {
            currentIndex++;
        }
    }
    leerArchivo.close();

    // Escribir el registro con el índice calculado
    archivo << currentIndex << "\t" << registro.toString() << "\n";
    archivo.close();

    std::cout << "Registro guardado con índice: " << currentIndex << " en el archivo: " << registro.taxi.getPlaca() <<
            std::endl;
}

void ArchivoManager::guardarViajes(const std::vector<Viajes> &viajes) {
    std::string path_viajes = "../data/TRANSACTION_LOG.txt";

    std::ofstream archivo(path_viajes, std::ios::app); // Abrir en modo de añadir

    if (archivo.is_open()) {
        for (const auto &viaje: viajes) {
            archivo << viaje.toString() << "\n";
        }
        std::cout << "Registros guardados correctamente en: " << path_viajes << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo: " << path_viajes << std::endl;

    }
}

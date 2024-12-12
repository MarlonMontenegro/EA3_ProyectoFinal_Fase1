#include "FlotaManager.h"

#include <algorithm>
#include <ArchivoManager.h>
#include <fstream>
#include <iomanip>
#include <UserInterface.h>
#include <RegistroTaxiConductor.h>
#include <sstream>

std::vector<Viajes> FlotaManager::historialViajes;

void FlotaManager::registrarTaxiYConductor() {
    const Taxi taxi = UserInterface::registrarTaxi();
    const Conductor conductor = UserInterface::registrarConductor();
    const RegistroTaxiConductor registro(conductor, taxi);
    agregarRegistro(registro);

    std::cout << "\nTaxi y conductor registrados correctamente.\n" << std::endl;
}

void FlotaManager::agregarRegistro(const RegistroTaxiConductor &registro) {
    // Verificar duplicados en el vector
    const auto it = std::find_if(registros.begin(), registros.end(),
                                 [&registro](const RegistroTaxiConductor &existing) {
                                     return existing.taxi.getPlaca() == registro.taxi.getPlaca();
                                 });

    if (it != registros.end()) {
        std::cout << "El registro ya existe: " << registro.taxi.getPlaca() << std::endl;
        return; // Salir si ya existe
    }

    // Agregar al vector principal
    registros.push_back(registro);

    // Clasificar por categoría
    if (registro.taxi.getCategoria() == "ejecutiva") {
        taxisDisponiblesEjecutivos.push_back(registro);
    } else {
        taxisDisponiblesTradicionales.push_back(registro);
    }

    // Guardar en el archivo
    const ArchivoManager archivoManager("../data/CARS_STORAGE.txt");
    archivoManager.guardarRegistroUnico(registro);

    std::cout << "\nRegistro agregado y guardado exitosamente.\n" << std::endl;
}

void FlotaManager::mostrarTabla() const {
    std::cout << "=====================================================================\n";
    std::cout << "                  Registros                         \n";
    std::cout << "=====================================================================\n";
    std::cout << "Index\tPlaca\t\tModelo\t\tCategoria\tConductor\n";
    std::cout << "---------------------------------------------------------------------\n";
    for (size_t i = 0; i < registros.size(); ++i) {
        const auto &registro = registros[i];
        std::cout << i << "\t"
                << registro.taxi.getPlaca() << "\t\t"
                << registro.taxi.getModelo() << "\t\t"
                << registro.taxi.getCategoria() << "\t"
                << registro.conductor.getNombre() << "\n";
    }
}

void FlotaManager::mostrarRegistroPorIndex(int index) const {
    if (index >= 0 && index < static_cast<int>(registros.size())) {
        std::cout << "====================================================\n";
        std::cout << "                  Registro                         \n";
        std::cout << "====================================================\n\n";
        registros[index].mostrarInfo(); // Retornar el registro en la posición indicada
    } else {
        throw std::out_of_range("Índice fuera de rango.");
    }
}

void FlotaManager::iniciarViaje() {
    ArchivoManager archivo;
    const int eleccionDeCategoria = UserInterface::seleccionarCategoria();
    const double tarifa = UserInterface::seleccionTarifa();

    if (eleccionDeCategoria == 1) {
        if (!taxisDisponiblesTradicionales.empty()) {
            // Obtener el taxi y realizar el viaje
            RegistroTaxiConductor &registroTradicional = taxisDisponiblesTradicionales.front();

            const Viajes nuevoViaje(registroTradicional.conductor, registroTradicional.taxi, tarifa);
            archivo.guardarViajeIndividual(nuevoViaje);
            historialViajes.push_back(nuevoViaje);

            // Actualizar en registros
            for (auto &registro: registros) {
                if (registro.taxi.getPlaca() == registroTradicional.taxi.getPlaca()) {
                    registro = registroTradicional; // Copiar datos actualizados
                    break;
                }
            }

            // Mover a taxis en ruta
            taxisEnRuta.push_back(registroTradicional);
            taxisDisponiblesTradicionales.pop_front();
        } else {
            std::cout << "No hay taxis tradicionales disponibles.\n";
        }
    } else if (eleccionDeCategoria == 2) {
        if (!taxisDisponiblesEjecutivos.empty()) {
            // Obtener el taxi y realizar el viaje
            RegistroTaxiConductor &registroEjecutivo = taxisDisponiblesEjecutivos.front();

            Viajes nuevoViaje(registroEjecutivo.conductor, registroEjecutivo.taxi, tarifa);
            archivo.guardarViajeIndividual(nuevoViaje);

            historialViajes.push_back(nuevoViaje);

            // Actualizar en registros
            for (auto &registro: registros) {
                if (registro.taxi.getPlaca() == registroEjecutivo.taxi.getPlaca()) {
                    registro = registroEjecutivo; // Copiar datos actualizados
                    break;
                }
            }

            // Mover a taxis en ruta
            taxisEnRuta.push_back(registroEjecutivo);
            taxisDisponiblesEjecutivos.pop_front();
        } else {
            std::cout << "No hay taxis ejecutivos disponibles.\n";
        }
    } else {
        std::cout << "Opción inválida. Seleccione 1 para Tradicional o 2 para Ejecutivo.\n";
    }
}

void FlotaManager::mostrarDetallesDelConductor() const {
    mostrarTabla();
    int index;
    std::cout << "\nIngrese el ID del conductor que quiere ver...\n";
    std::cin >> index;
    mostrarRegistroPorIndex(index);
}

void FlotaManager::mostrarTaxisEnRuta() const {
    if (taxisEnRuta.empty()) {
        std::cout << "No hay taxis en ruta.\n";
        return;
    }

    std::cout << "Taxis en ruta:\n";
    std::cout << "Index\tConductor\tTaxi\n";
    for (size_t i = 0; i < taxisEnRuta.size(); ++i) {
        const auto &taxi = taxisEnRuta[i];
        std::cout << i << "\t"
                << taxi.conductor.getNombre() << "\t\t"
                << taxi.taxi.getPlaca() << "\t\t\t\n";
    }
}

void FlotaManager::mostrarTaxisDisponibles() const {
    // Calcular el número de taxis disponibles
    const int taxisEjecutivos = taxisDisponiblesEjecutivos.size();
    const int taxisTradicionales = taxisDisponiblesTradicionales.size();

    // Mostrar los resultados
    std::cout << "-----------------------------" << std::endl;
    std::cout << "   Taxis Disponibles         " << std::endl;
    std::cout << "-----------------------------" << std::endl;

    if (taxisEjecutivos > 0) {
        std::cout << "Taxis ejecutivos disponibles: " << taxisEjecutivos << std::endl;
    } else {
        std::cout << "Taxis ejecutivos disponibles: Ninguno" << std::endl;
    }

    if (taxisTradicionales > 0) {
        std::cout << "Taxis tradicionales disponibles: " << taxisTradicionales << std::endl;
    } else {
        std::cout << "Taxis tradicionales disponibles: Ninguno" << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
}

void FlotaManager::finalizarViaje() {
    int index;
    bool indexIncorrecto = true;
    ArchivoManager archivo;
    Viajes viaje;
    mostrarTaxisEnRuta();

    std::cout << "Ingrese el viaje a finalizar: ";
    std::cin >> index;

    while (indexIncorrecto) {
        if (index >= 0 && index < taxisEnRuta.size()) {
            // Guardar el registro.
            RegistroTaxiConductor elRegistro = taxisEnRuta[index];

            // Eliminar el registro del vector de taxis en ruta.
            taxisEnRuta.erase(taxisEnRuta.begin() + index);

            // Registrar en el deque correspondiente a su categoría.
            if (elRegistro.taxi.getCategoria() == "ejecutiva") {
                taxisDisponiblesEjecutivos.push_back(elRegistro);
            } else {
                taxisDisponiblesTradicionales.push_back(elRegistro);
            }
            indexIncorrecto = false;
        } else {
            std::cout << "Índice fuera de rango. Intente nuevamente: ";
            std::cin >> index;
        }
    }
    std::cout << "Viaje finalizado." << std::endl;
}

void FlotaManager::cargarRegistrosDesdeArchivo() {
    const std::string archivoPath = "../data/CARS_STORAGE.txt";
    std::ifstream archivo(archivoPath);

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo: " << archivoPath << std::endl;
        return;
    }

    std::string linea;

    // Leer y saltar la primera línea (encabezados)
    std::getline(archivo, linea);

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue; // Saltar líneas vacías

        // Flujos de entrada para extraer datos
        std::istringstream stream(linea);

        std::string placa, numMotor, modelo, categoria, nombre, documento, telefono, seguroSocial;
        int anio, index;

        // Leer datos de la línea
        stream >> index >> placa >> modelo >> numMotor >> anio >> categoria
                >> nombre >> documento >> telefono >> seguroSocial;

        // Crear objetos e inicializar
        Taxi taxi(placa, numMotor, modelo, anio);

        Conductor conductor(nombre, documento, seguroSocial, telefono);

        RegistroTaxiConductor registro(conductor, taxi);

        // Cargar el registro a los vectores
        registros.push_back(registro);

        if (categoria == "ejecutiva") {
            taxisDisponiblesEjecutivos.push_back(registro);
        } else {
            taxisDisponiblesTradicionales.push_back(registro);
        }
    }

    archivo.close();
    std::cout << "Registros cargados exitosamente desde el archivo." << std::endl;
}

void FlotaManager::cargarViajeDesdeArchvio() {
    const std::string archivoPath = "../data/TRANSACTION_LOG.txt";
    std::ifstream archivo(archivoPath);

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo: " << archivoPath << std::endl;
        return;
    }

    std::string linea;

    // Saltar encabezados
    std::getline(archivo, linea);

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;

        std::istringstream stream(linea);

        std::string nombreConductor, placaTaxi, inicio;
        double dineroGenerado;
        int numeroDeViaje;

        // Leer datos del flujo a variables temporales
        stream >> nombreConductor >> placaTaxi >> inicio >> dineroGenerado >> numeroDeViaje;

        // Crear objetos temporales
        Conductor conductor(nombreConductor, "", "", "");
        Taxi taxi(placaTaxi, "", "", 2010);

        // Crear el viaje y añadirlo al historial
        Viajes viaje(conductor, taxi, dineroGenerado, inicio, numeroDeViaje);
        historialViajes.push_back(viaje);
    }

    archivo.close();
    std::cout << "Viajes cargados exitosamente desde el archivo." << std::endl;
}

void FlotaManager::listadoDeViajes() const {
    std::cout << "=====================================\n";
    std::cout << "                  Viajes             \n";
    std::cout << "=====================================\n";
    std::cout << "Index\tConductor\tPlaca\tDinero\tFecha\n";
    std::cout << "--------------------------------------\n";
    for (size_t i = 0; i < historialViajes.size(); i++) {
        const auto &viaje = historialViajes[i];
        std::cout
                << i << "\t"
                << viaje.getConductor().getNombre() << "\t"
                << viaje.getTaxi().getPlaca() << "\t"
                << viaje.getDineroGenerado() << "\t"
                << viaje.getInicio() << "\n";
    }
}


void FlotaManager::viajesVehiculoEspecifico() {
    std::string placa;
    mostrarTabla();
    double suma = 0;

    std::cout << "Ingrese el numero de placa de taxi: ";
    std::getline(std::cin >> std::ws, placa);

    bool hayViajes = false;

    std::cout << "=====================================================================\n";
    std::cout << std::setw(15) << "Conductor"
            << std::setw(15) << "Placa"
            << std::setw(15) << "Fecha"
            << std::setw(15) << "Dinero"
            << "\n";
    std::cout << "---------------------------------------------------------------------\n";

    for (const auto &viaje: historialViajes) {
        if (viaje.getTaxi().getPlaca() == placa) {
            suma += viaje.getDineroGenerado();
            hayViajes = true;

            std::cout << std::setw(15) << viaje.getConductor().getNombre()
                    << std::setw(15) << viaje.getTaxi().getPlaca()
                    << std::setw(15) << viaje.getInicio()
                    << std::setw(15) << std::fixed << std::setprecision(2) << viaje.getDineroGenerado()
                    << "\n";
        }
    }
    if (!hayViajes) {
        std::cout << "No se encontraron viajes para el taxi con la placa: " << placa << std::endl;
    } else {
        std::cout << "---------------------------------------------------------------------\n";
        std::cout << "Total Dinero Generado: $" << std::fixed << std::setprecision(2) << suma << "\n";
        std::cout << "=====================================================================\n";
    }
}

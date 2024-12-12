#ifndef ARCHIVOMANAGER_H
#define ARCHIVOMANAGER_H

#include <RegistroTaxiConductor.h>
#include <string>
#include <utility>
#include <Viajes.h>

class ArchivoManager {
    std::string path;

public:
    ArchivoManager() = default;

    explicit ArchivoManager(std::string _path) : path(std::move(_path)) {
    }


    void guardarRegistroUnico(const RegistroTaxiConductor &registro) const;


    static void guardarViajeIndividual(const Viajes &viaje);

    void leerListadoDeViajes();
};

#endif // ARCHIVOMANAGER_H

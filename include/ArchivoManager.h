#ifndef ARCHIVOMANAGER_H
#define ARCHIVOMANAGER_H

#include <RegistroTaxiConductor.h>
#include <string>
#include <utility>
#include <vector>
#include <Viajes.h>

class ArchivoManager {
    std::string path;

public:
    ArchivoManager() = default;

    explicit ArchivoManager(std::string _path) : path(std::move(_path)) {
    }

    void guardarRegistrosEnArchivo(const std::vector<RegistroTaxiConductor> &registros) const;

    void guardarRegistroUnico(const RegistroTaxiConductor &registro) const;


    static void guardarViajes(const std::vector<Viajes> &viajes) ;


};

#endif // ARCHIVOMANAGER_H

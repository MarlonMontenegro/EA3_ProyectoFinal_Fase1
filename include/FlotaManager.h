#ifndef FLOTAMANAGER_H
#define FLOTAMANAGER_H

#include <vector>
#include "RegistroTaxiConductor.h"
#include <deque>
#include <Viajes.h>

class FlotaManager {
private:
    std::vector<RegistroTaxiConductor> registros;
    std::vector<RegistroTaxiConductor> taxisEnRuta;

    std::deque<RegistroTaxiConductor> taxisDisponiblesEjecutivos;
    std::deque<RegistroTaxiConductor> taxisDisponiblesTradicionales;

    static std::vector<Viajes> historialViajes;

public:
    void agregarRegistro(const RegistroTaxiConductor &registro);

    void mostrarTabla() const;

    void mostrarRegistroPorIndex(int index) const;

    void iniciarViaje();

    void finalizarViaje();

    void registrarTaxiYConductor();

    void mostrarDetallesDelConductor() const;

    void mostrarTaxisEnRuta() const;

    void mostrarTaxisDisponibles() const;

    void cargarRegistrosDesdeArchivo();

    static void cargarViajeDesdeArchvio();

    void viajesVehiculoEspecifico();

    void listadoDeViajes() const;
};


#endif //FLOTAMANAGER_H

#include <FlotaManager.h>
#include <UserInterface.h>
#include "./include/Taxi.h"

int main() {
    int opcion = 0;
    int opcionReportes = 0;

    FlotaManager manager;
    UserInterface interface;

    manager.cargarRegistrosDesdeArchivo();
    manager.cargarViajeDesdeArchvio();


    do {
        interface.menu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                manager.registrarTaxiYConductor();
                break;
            case 2:
                manager.mostrarTabla();
                break;
            case 3:
                manager.mostrarDetallesDelConductor();
                break;
            case 4:
                manager.iniciarViaje();
                break;
            case 5:
                manager.mostrarTaxisEnRuta();
                break;
            case 6:
                manager.mostrarTaxisDisponibles();
                break;
            case 7:
                manager.finalizarViaje();
                break;
            case 8:
                interface.menuReportes();

                do {
                    std::cin >> opcionReportes;
                    switch (opcionReportes) {
                        case 1:
                            manager.listadoDeViajes();
                            break;
                        case 2:
                            manager.viajesVehiculoEspecifico();
                            break;
                        case 5:
                            std::cout << "Regresando al menu principal..." << std::endl;
                            interface.menu();
                            break;
                        default:
                            std::cout << "Opcion invalida, por favor ingresa una opcion valida." << std::endl;
                            break;
                    }
                } while (opcionReportes != 5);

                break;
            case 9:
                std::cout << "Gracias por usar el sistema. Hasta pronto....." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida, por favor ingresa una opcion valida." << std::endl;
                break;
        }
    } while (opcion != 8);
}

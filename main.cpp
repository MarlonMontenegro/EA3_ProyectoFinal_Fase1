#include <ArchivoManager.h>
#include <FlotaManager.h>
#include <UserInterface.h>
#include "./include/Taxi.h"

int main() {
    int opcion = 0;
    FlotaManager manager;
    UserInterface interface;

    const ArchivoManager archivo_manager("../data/CARS_STORAGE.txt");
    manager.cargarRegistrosDesdeArchivo();


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
                break;
            case 9:
                std::cout << "Gracias por usar el sistema. Hasta pronto....." << std::endl;
                break;
            default:
                std::cout << "Opción invalida, por favor ingresa una opcion valida." << std::endl;
                break;
        }
    } while (opcion != 8);
}

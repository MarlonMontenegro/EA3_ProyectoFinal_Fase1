#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <Conductor.h>
#include <Taxi.h>

class UserInterface {
public:
    static int seleccionarCategoria();

    static double seleccionTarifa();

    static Taxi registrarTaxi();

    static Conductor registrarConductor();

    static void menu();

    static void menuReportes();

    static void limpiarPantalla();

};

#endif //INPUTMANAGER_H

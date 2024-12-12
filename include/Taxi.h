#ifndef TAXI_H
#define TAXI_H

#include <string>
#include <iostream>

class Taxi {
private:
    std::string placa;
    std::string numMotor;
    std::string modelo;
    int anio;
    std::string categoria;

public:


    Taxi();

    // Constructor con los parámetros necesarios
    Taxi(std::string placa, std::string numeroMotor, std::string modelo, int anio);
    friend std::istream &operator>>(std::istream &is, Taxi &taxi);


    // Getters
    std::string getPlaca() const;

    std::string getNumeroMotor() const;

    std::string getModelo() const;

    int getAnio() const;

    // Métodos
    void asignarCategoria();

    void mostrarInformacion() const;

    // Obtener la categoría
    std::string getCategoria() const;
};

#endif // TAXI_H

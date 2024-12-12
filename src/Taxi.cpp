#include "../include/Taxi.h"


Taxi::Taxi()
    : placa(""), numMotor(""), modelo(""), anio(2010), categoria("") {
    // Constructor predeterminado que inicializa los atributos con valores vacíos o por defecto
}

Taxi::Taxi(std::string placa, std::string numeroMotor, std::string modelo, int anio)
    : placa(std::move(placa)), numMotor(std::move(numeroMotor)), modelo(std::move(modelo)), anio(anio) {
    asignarCategoria();
}

// Métodos Getter
std::string Taxi::getPlaca() const { return placa; }
std::string Taxi::getNumeroMotor() const { return numMotor; }
std::string Taxi::getModelo() const { return modelo; }
int Taxi::getAnio() const { return anio; }

// Método para asignar la categoría del taxi según el año
void Taxi::asignarCategoria() {
    bool categoriaIncorrecta = true;

    while (categoriaIncorrecta) {
        if (anio > 2024) {
            std::cerr << "Error: No se puede asignar un anio mayor al actual.\n";
            std::cout << "Por favor, ingrese un anioo valido (menor o igual a 2024): ";
            std::cin >> anio; // Solicita nuevamente el año
        } else if (anio >= 2015) {
            categoria = "ejecutiva";
            categoriaIncorrecta = false;
        } else if (anio >= 2010) {
            categoria = "tradicional";
            categoriaIncorrecta = false;
        } else {
            std::cerr << "Error: Anio no valido. (" << anio << ") Por favor, ingrese un anio dentro del rango aceptado.\n" << std::endl;
            std::cout << "Por favor, ingrese un nuevo anio: " << std::endl;
            std::cin >> anio; // Solicita nuevamente el año
        }
    }
}

// Método para mostrar la información del taxi
void Taxi::mostrarInformacion() const {
    std::cout << "\n=============================" << std::endl;
    std::cout << "   Informacion del Taxi      " << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Placa:           " << placa << std::endl;
    std::cout << "Numero de motor: " << numMotor << std::endl;
    std::cout << "Modelo:          " << modelo << std::endl;
    std::cout << "Anio:             " << anio << std::endl;
    std::cout << "Categoria:       " << categoria << std::endl;
    std::cout << "=============================" << std::endl;
}


// Método para obtener la categoría
std::string Taxi::getCategoria() const {
    return categoria;
}

std::istream &operator>>(std::istream &is, Taxi &taxi) {
    is >> taxi.placa >> taxi.numMotor >> taxi.modelo >> taxi.anio;
    return is;
}

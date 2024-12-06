#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include <string>

class Conductor {
private:
    std::string nombreCompleto;
    std::string documento;
    std::string seguroSocial;
    std::string telefono;

public:
    Conductor();

    Conductor(const std::string &nombre,
              const std::string &documento, const std::string &seguroSocial,
              const std::string &telefono)
        : nombreCompleto(nombre), documento(documento),
          seguroSocial(seguroSocial), telefono(telefono) {
    }


    std::string getNombre() const;

    std::string getDocumentoIdentidad() const;

    std::string getNumeroSeguroSocial() const;

    std::string getTelefono() const;

    void mostrarInformacion() const;
};

#endif // CONDUCTOR_H

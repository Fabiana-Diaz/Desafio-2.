#ifndef HUESPED_H
#define HUESPED_H

#include <string>
#include "reservacion.h"
using namespace std;

class Huesped {
private:
    string documento;
    int antiguedad;
    float puntuacion;

    Reservacion reservaciones[20];
    int cantidadReservas;

public:
    Huesped();
    Huesped(const string& documento, int antiguedad, float puntuacion);

    // Getters
    string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;
    int getCantidadReservas() const;
    Reservacion getReserva(int i) const;

    // Setters
    void setPuntuacion(float nuevaPuntuacion);

    // Funcionalidades
    bool agregarReserva(const Reservacion& nuevaReserva);
    bool reservaSeCruza(const Reservacion& nuevaReserva) const;
    void mostrarReservas() const;
    void mostrarInformacion() const;
};

#endif

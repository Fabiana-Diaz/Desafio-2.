#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>
#include "alojamiento.h"
#include "fecha.h"
using namespace std;

class Anfitrion {
private:
    string nombre;
    string documento;
    int antiguedad;
    float puntuacion;
    Alojamiento** alojamientos;
    int capacidadMaxima;
    int cantidadActual;

public:
    Anfitrion(); // Constructor por defecto
    Anfitrion(const string& nombre, const string& documento, int antiguedad, float puntuacion, int capacidad);
    ~Anfitrion(); // Destructor

    // Getters
    string getNombre() const;
    string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;
    int getCantidadAlojamientos() const;

    // Métodos de gestión
    bool agregarAlojamiento(Alojamiento* nuevo);
    Alojamiento* getAlojamiento(int indice) const;

    // Mostrar
    void mostrarInformacion() const;
    void mostrarAlojamientos() const;
    void mostrarReservasEnRango(const Fecha& inicio, const Fecha& fin) const;

};

#endif

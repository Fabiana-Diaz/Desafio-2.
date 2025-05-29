#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include "reservacion.h"
using namespace std;

class Alojamiento {
private:
    string nombre;
    string codigo;
    string direccion;
    string departamento;
    string municipio;
    string tipo;
    float calificacion;
    string anfitrion;
    string* amenidades;
    int cantidadAmenidades;

    Reservacion reservas[50];   // máximo 50 reservas por alojamiento
    int cantidadReservas;

public:
    // Constructores y destructor
    Alojamiento();
    Alojamiento(const string& nombre, const string& codigo, const string& direccion,
                const string& departamento, const string& municipio, const string& tipo,
                float calificacion, string* amenidades, int cantidadAmenidades,
                const string& anfitrion);
    ~Alojamiento();

    // Getters
    string getNombre() const;
    string getCodigo() const;
    string getDireccion() const;
    string getDepartamento() const;
    string getMunicipio() const;
    string getTipo() const;
    float getCalificacion() const;
    string getAnfitrion() const;
    int getCantidadAmenidades() const;
    string getAmenidad(int index) const;

    // Reservas
    bool agregarReserva(const Reservacion& r);
    int getCantidadReservas() const;
    Reservacion getReserva(int indice) const;

    // Serialización y visualización
    string serializar() const;
    void mostrar() const;

    // Carga desde texto plano
    static Alojamiento parsearDesdeLinea(const string& linea);
};

#endif

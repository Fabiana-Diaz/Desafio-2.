#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
using namespace std;

class Alojamiento {
private:
    string nombre;
    string codigo;
    string direccion;
    string departamento;
    string municipio;
    string tipo; // casa o apartamento
    float puntuacion;
    string amenidades[6];
    int cantidadAmenidades;
    string nombreAnfitrion;

public:
    Alojamiento(); // Constructor por defecto

    Alojamiento(const string& nombre,
                const string& codigo,
                const string& direccion,
                const string& departamento,
                const string& municipio,
                const string& tipo,
                float puntuacion,
                string amenidades[], int cantidadAmenidades,
                const string& nombreAnfitrion);

    // Getters
    string getNombre() const;
    string getCodigo() const;
    string getDireccion() const;
    string getDepartamento() const;
    string getMunicipio() const;
    string getTipo() const;
    float getPuntuacion() const;
    int getCantidadAmenidades() const;
    string getAmenidad(int index) const;
    string getNombreAnfitrion() const;

    // Mostrar y serializar
    void mostrar() const;
    string serializar() const;
};

#endif

#include "alojamiento.h"
#include <iostream>
using namespace std;

Alojamiento::Alojamiento() {
    nombre = "";
    codigo = "";
    direccion = "";
    departamento = "";
    municipio = "";
    tipo = "";
    puntuacion = 0.0f;
    cantidadAmenidades = 0;
    nombreAnfitrion = "";
}

Alojamiento::Alojamiento(const string& _nombre, const string& _codigo,
                         const string& _direccion,
                         const string& _departamento, const string& _municipio,
                         const string& _tipo, float _puntuacion,
                         string _amenidades[], int _cantidadAmenidades,
                         const string& _nombreAnfitrion) {
    nombre = _nombre;
    codigo = _codigo;
    direccion = _direccion;
    departamento = _departamento;
    municipio = _municipio;
    tipo = _tipo;
    puntuacion = _puntuacion;
    cantidadAmenidades = _cantidadAmenidades;
    for (int i = 0; i < _cantidadAmenidades; ++i) {
        amenidades[i] = _amenidades[i];
    }
    nombreAnfitrion = _nombreAnfitrion;
}

// Getters
string Alojamiento::getNombre() const { return nombre; }
string Alojamiento::getCodigo() const { return codigo; }
string Alojamiento::getDireccion() const { return direccion; }
string Alojamiento::getDepartamento() const { return departamento; }
string Alojamiento::getMunicipio() const { return municipio; }
string Alojamiento::getTipo() const { return tipo; }
float Alojamiento::getPuntuacion() const { return puntuacion; }
int Alojamiento::getCantidadAmenidades() const { return cantidadAmenidades; }
string Alojamiento::getAmenidad(int index) const {
    if (index >= 0 && index < cantidadAmenidades) return amenidades[index];
    return "";
}
string Alojamiento::getNombreAnfitrion() const { return nombreAnfitrion; }

// Mostrar
void Alojamiento::mostrar() const {
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Ubicacion: " << municipio << ", " << departamento << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Puntuacion: " << puntuacion << " / 5.0" << endl;
    cout << "Anfitrion: " << nombreAnfitrion << endl;
    cout << "Amenidades: ";
    for (int i = 0; i < cantidadAmenidades; ++i) {
        cout << amenidades[i];
        if (i < cantidadAmenidades - 1) cout << ", ";
    }
    cout << endl;
}

// Serializar para archivo
string Alojamiento::serializar() const {
    string linea = codigo + "|" + nombre + "|" + direccion + "|" + departamento + "|" + municipio + "|"
                   + tipo + "|" + to_string(puntuacion) + "|";

    for (int i = 0; i < cantidadAmenidades; ++i) {
        linea += amenidades[i];
        if (i < cantidadAmenidades - 1) linea += ",";
    }

    linea += "|" + nombreAnfitrion;
    return linea;
}

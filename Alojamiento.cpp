#include "alojamiento.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor por defecto
Alojamiento::Alojamiento() {
    nombre = codigo = direccion = departamento = municipio = tipo = anfitrion = "";
    calificacion = 0.0f;
    amenidades = nullptr;
    cantidadAmenidades = 5;
    cantidadReservas = 0;
}

// Constructor con parámetros
Alojamiento::Alojamiento(const string& nombre, const string& codigo, const string& direccion,
                         const string& departamento, const string& municipio, const string& tipo,
                         float calificacion, string* amenidades, int cantidadAmenidades,
                         const string& anfitrion) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->direccion = direccion;
    this->departamento = departamento;
    this->municipio = municipio;
    this->tipo = tipo;
    this->calificacion = calificacion;
    this->anfitrion = anfitrion;

    this->cantidadAmenidades = cantidadAmenidades;
    this->amenidades = new string[cantidadAmenidades];
    for (int i = 0; i < cantidadAmenidades; ++i) {
        this->amenidades[i] = amenidades[i];
    }

    cantidadReservas = 0;
}

// Destructor
Alojamiento::~Alojamiento() {
}

// Getters
string Alojamiento::getNombre() const { return nombre; }
string Alojamiento::getCodigo() const { return codigo; }
string Alojamiento::getDireccion() const { return direccion; }
string Alojamiento::getDepartamento() const { return departamento; }
string Alojamiento::getMunicipio() const { return municipio; }
string Alojamiento::getTipo() const { return tipo; }
float Alojamiento::getCalificacion() const { return calificacion; }
string Alojamiento::getAnfitrion() const { return anfitrion; }
int Alojamiento::getCantidadAmenidades() const { return cantidadAmenidades; }

string Alojamiento::getAmenidad(int index) const {
    if (index >= 0 && index < cantidadAmenidades) return amenidades[index];
    return "";
}

// Mostrar información
void Alojamiento::mostrar() const {
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Ubicacion: " << municipio << ", " << departamento << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Puntuacion: " << calificacion << " / 5.0" << endl;
    cout << "Anfitrion: " << anfitrion << endl;

    cout << "Amenidades: ";
    if (amenidades != nullptr && cantidadAmenidades > 0 && cantidadAmenidades <= 100) {
        for (int i = 0; i < cantidadAmenidades; ++i) {
            cout << amenidades[i];
            if (i < cantidadAmenidades - 1) cout << ", ";
        }
    } else {
        cout << "(sin amenidades o error)";
    }
    cout << endl;
}


// Cargar desde línea de texto
Alojamiento Alojamiento::parsearDesdeLinea(const string& linea) {
    stringstream ss(linea);
    string nombre, codigo, direccion, departamento, municipio, tipo, califStr, anfitrion, amenStr;

    getline(ss, nombre, '|');
    getline(ss, codigo, '|');
    getline(ss, direccion, '|');
    getline(ss, departamento, '|');
    getline(ss, municipio, '|');
    getline(ss, tipo, '|');
    getline(ss, califStr, '|');
    getline(ss, anfitrion, '|');
    getline(ss, amenStr);

    float calificacion = stof(califStr);

    stringstream ssAmen(amenStr);
    string amenidad;
    string amenidadesTmp[20];
    int count = 0;
    while (getline(ssAmen, amenidad, ';') && count < 20) {
        amenidadesTmp[count++] = amenidad;
    }

    if (count <= 0 || count > 100) count = 0;

    string* amenities = nullptr;
    if (count > 0) {
        amenities = new string[count];
        for (int i = 0; i < count; ++i) {
            amenities[i] = amenidadesTmp[i];
        }
    }


    Alojamiento a(nombre, codigo, direccion, departamento, municipio, tipo, calificacion, amenities, count, anfitrion);
    delete[] amenities;
    return a;
}

// Manejo de reservaciones
bool Alojamiento::agregarReserva(const Reservacion& r) {
    if (cantidadReservas < 50) {
        reservas[cantidadReservas++] = r;
        return true;
    }
    return false;
}

int Alojamiento::getCantidadReservas() const {
    return cantidadReservas;
}

Reservacion Alojamiento::getReserva(int indice) const {
    if (indice >= 0 && indice < cantidadReservas) {
        return reservas[indice];
    }
    return Reservacion();
}

string Alojamiento::serializar() const {
    string resultado = nombre + "|" + codigo + "|" + direccion + "|" + departamento + "|" + municipio + "|"
                       + tipo + "|" + to_string(calificacion) + "|" + anfitrion + "|";
    for (int i = 0; i < cantidadAmenidades; ++i) {
        resultado += amenidades[i];
        if (i < cantidadAmenidades - 1) resultado += ";";
    }
    return resultado;
}



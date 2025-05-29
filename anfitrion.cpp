// anfitrion.cpp
#include "anfitrion.h"
#include <iostream>
#include "reservacion.h"
using namespace std;

// Constructor por defecto
Anfitrion::Anfitrion() {
    nombre = "";
    documento = "";
    antiguedad = 0;
    puntuacion = 0.0f;
    capacidadMaxima = 10;
    cantidadActual = 0;
    alojamientos = new Alojamiento*[capacidadMaxima];
}

// Constructor con parámetros
Anfitrion::Anfitrion(const string& nombre, const string& documento, int antiguedad, float puntuacion, int capacidad) {
    this->nombre = nombre;
    this->documento = documento;
    this->antiguedad = antiguedad;
    this->puntuacion = puntuacion;
    this->capacidadMaxima = capacidad;
    this->cantidadActual = 0;
    this->alojamientos = new Alojamiento*[capacidadMaxima];
}

// Destructor
Anfitrion::~Anfitrion() {
    if (alojamientos != nullptr) {
        for (int i = 0; i < cantidadActual; ++i) {
            delete alojamientos[i];  // liberar cada Alojamiento creado con new
        }
        delete[] alojamientos;
    }
}




// Getters
string Anfitrion::getNombre() const {
    return nombre;
}

string Anfitrion::getDocumento() const {
    return documento;
}

int Anfitrion::getAntiguedad() const {
    return antiguedad;
}

float Anfitrion::getPuntuacion() const {
    return puntuacion;
}

int Anfitrion::getCantidadAlojamientos() const {
    return cantidadActual;
}

// Agrega un alojamiento al arreglo dinámico
bool Anfitrion::agregarAlojamiento(Alojamiento* nuevo) {
    if (nuevo == nullptr || cantidadActual >= capacidadMaxima) return false;
    alojamientos[cantidadActual++] = nuevo;
    return true;
}


// Obtener un puntero a un alojamiento por índice
Alojamiento* Anfitrion::getAlojamiento(int indice) const {
    if (indice < 0 || indice >= cantidadActual) return nullptr;
    return alojamientos[indice];
}

// Muestra los datos del anfitrión
void Anfitrion::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Documento del anfitrion: " << documento << endl;
    cout << "Antiguedad: " << antiguedad << " meses" << endl;
    cout << "Puntuacion: " << puntuacion << " / 5.0" << endl;
    cout << "Cantidad de alojamientos: " << cantidadActual << endl;
}

// Muestra todos sus alojamientos
void Anfitrion::mostrarAlojamientos() const {
    if (cantidadActual == 0) {
        cout << "Este anfitrion no tiene alojamientos registrados." << endl;
        return;
    }

    for (int i = 0; i < cantidadActual; ++i) {
        cout << "\nAlojamiento #" << (i + 1) << ":" << endl;
        alojamientos[i]->mostrar();
        cout << "-----------------------------" << endl;
    }
}


void Anfitrion::mostrarReservasEnRango(const Fecha& inicio, const Fecha& fin) const {
    cout << "Reservas activas entre ";
    inicio.mostrarExtendido();
    cout << " y ";
    fin.mostrarExtendido();

    bool hayReservas = false;

    for (int i = 0; i < cantidadActual; ++i) {
        Alojamiento* aloj = alojamientos[i];
        if (aloj) {
            for (int j = 0; j < aloj->getCantidadReservas(); ++j) {
                Reservacion r = aloj->getReserva(j);
                Fecha entrada = r.getFechaEntrada();
                if (entrada >= inicio && entrada <= fin) {
                    r.mostrarResumen();
                    hayReservas = true;
                }
            }
        }
    }

    if (!hayReservas) {
        cout << "No hay reservas en ese rango para este anfitrión.\n";
    }
}

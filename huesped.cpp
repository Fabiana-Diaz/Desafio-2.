#include "huesped.h"
#include "contador_iteraciones.h"
#include "consumo_memoria.h"

#include <iostream>
using namespace std;

// Constructor por defecto
Huesped::Huesped() {
    documento = "";
    antiguedad = 0;
    puntuacion = 0.0f;
    cantidadReservas = 0;
     ConsumoMemoria::agregar(sizeof(Huesped) + sizeof(Reservacion) * 20);
}

// Constructor con parámetros
Huesped::Huesped(const string& documento,
                 int antiguedad,
                 float puntuacion) {
    this->documento = documento;
    this->antiguedad = antiguedad;
    this->puntuacion = puntuacion;
    this->cantidadReservas = 0;
     ConsumoMemoria::agregar(sizeof(Huesped) + sizeof(Reservacion) * 20);
}

// Getters
string Huesped::getDocumento() const {
    return documento;
}

int Huesped::getAntiguedad() const {
    return antiguedad;
}

float Huesped::getPuntuacion() const {
    return puntuacion;
}

int Huesped::getCantidadReservas() const {
    return cantidadReservas;
}

Reservacion Huesped::getReserva(int i) const {
    if (i >= 0 && i < cantidadReservas) {
        return reservaciones[i];
    }
    return Reservacion(); // reserva vacía por seguridad
}

// Setters
void Huesped::setPuntuacion(float nuevaPuntuacion) {
    puntuacion = nuevaPuntuacion;
}

// Validar si la nueva reserva se cruza con las existentes
bool Huesped::reservaSeCruza(const Reservacion& nuevaReserva) const {
    Fecha entradaNueva = nuevaReserva.getFechaEntrada();
    Fecha salidaNueva = nuevaReserva.getFechaSalida();

    for (int i = 0; i < cantidadReservas; ++i) {
        ContadorIteraciones::incrementar();
        Fecha entradaExistente = reservaciones[i].getFechaEntrada();
        Fecha salidaExistente = reservaciones[i].getFechaSalida();

        // Verificamos si hay cruce de fechas
        if (!(salidaNueva < entradaExistente || entradaNueva > salidaExistente)) {
            return true; // Se cruzan
        }
    }
    return false; // No hay cruce
}


// Agregar reserva si no hay cruce
bool Huesped::agregarReserva(const Reservacion& nuevaReserva) {
    if (cantidadReservas >= 20) return false;
    if (reservaSeCruza(nuevaReserva)) return false;

    reservaciones[cantidadReservas++] = nuevaReserva;
    return true;
}

// Mostrar reservas con sus anotaciones
void Huesped::mostrarReservas() const {
    if (cantidadReservas == 0) {
        cout << "No hay reservas activas." << endl;
        return;
    }

    for (int i = 0; i < cantidadReservas; ++i) {
        ContadorIteraciones::incrementar();
        cout << "Reserva #" << (i + 1) << ":" << endl;
        reservaciones[i].mostrarResumen();
        cout << "----------------------" << endl;
    }
}

// Mostrar info general del huésped
void Huesped::mostrarInformacion() const {
    cout << "Documento: " << documento << endl;
    cout << "Antiguedad: " << antiguedad << " meses" << endl;
    cout << "Puntuacion: " << puntuacion << " / 5.0" << endl;
    cout << "Cantidad de Reservas: " << cantidadReservas << endl;
}

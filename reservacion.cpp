#include "reservacion.h"
#include "consumo_memoria.h"
#include "contador_iteraciones.h"
#include "consumo_memoria.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Reservacion::Reservacion() {
    codigoReserva = "";
    codigoAlojamiento = "";
    documentoHuesped = "";
    fechaEntrada = Fecha(); // 01/01/2023
    duracionNoches = 0;
    fechaPago = Fecha();
    metodoPago = "";
    montoTotal = 0.0f;
    anotacion = "";
     ConsumoMemoria::agregar(sizeof(Reservacion));
}

// Constructor con parámetros
Reservacion::Reservacion(const string& codigoReserva,
                         const string& codigoAlojamiento,
                         const string& documentoHuesped,
                         const Fecha& fechaEntrada,
                         int duracionNoches,
                         const Fecha& fechaPago,
                         const string& metodoPago,
                         float montoTotal,
                         const string& anotacion) {
    this->codigoReserva = codigoReserva;
    this->codigoAlojamiento = codigoAlojamiento;
    this->documentoHuesped = documentoHuesped;
    this->fechaEntrada = fechaEntrada;
    this->duracionNoches = duracionNoches;
    this->fechaPago = fechaPago;
    this->metodoPago = metodoPago;
    this->montoTotal = montoTotal;
    this->anotacion = anotacion.substr(0, 1000); // máx 1000 caracteres
     ConsumoMemoria::agregar(sizeof(Reservacion));
}

// Getters
string Reservacion::getCodigoReserva() const {
    return codigoReserva;
}

string Reservacion::getCodigoAlojamiento() const {
    return codigoAlojamiento;
}

string Reservacion::getDocumentoHuesped() const {
    return documentoHuesped;
}

Fecha Reservacion::getFechaEntrada() const {
    return fechaEntrada;
}

Fecha Reservacion::getFechaSalida() const {
    return fechaEntrada.sumarDias(duracionNoches);
}

Fecha Reservacion::getFechaPago() const {
    return fechaPago;
}

int Reservacion::getDuracion() const {
    return duracionNoches;
}

string Reservacion::getMetodoPago() const {
    return metodoPago;
}

float Reservacion::getMontoTotal() const {
    return montoTotal;
}

string Reservacion::getAnotacion() const {
    return anotacion;
}

// Setter
void Reservacion::setAnotacion(const string& nuevaAnotacion) {
    anotacion = nuevaAnotacion.substr(0, 1000);
}

// Mostrar resumen completo
void Reservacion::mostrarResumen() const {
    cout << "Codigo de Reservacion: " << codigoReserva << endl;
    cout << "Codigo del Alojamiento: " << codigoAlojamiento << endl;
    cout << "Documento del Huesped: " << documentoHuesped << endl;

    cout << "Fecha de Entrada: ";
    fechaEntrada.mostrarExtendido();

    cout << "Fecha de Salida: ";
    getFechaSalida().mostrarExtendido();

    cout << "Duracion: " << duracionNoches << " noches" << endl;

    cout << "Fecha de Pago: ";
    fechaPago.mostrarExtendido();

    cout << "Metodo de Pago: " << metodoPago << endl;
    cout << "Monto Total: $" << montoTotal << endl;
    cout << "Anotacion del huésped: " << anotacion << endl;
}

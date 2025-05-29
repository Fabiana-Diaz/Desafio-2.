#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>
#include "fecha.h"
using namespace std;

class Reservacion {
private:
    string codigoReserva;         // Identificador único de la reservación
    string codigoAlojamiento;     // Código del alojamiento reservado
    string documentoHuesped;      // Documento del huésped que reserva
    Fecha fechaEntrada;           // Fecha de entrada (tipo Fecha)
    int duracionNoches;           // Cantidad de noches de la reserva
    Fecha fechaPago;              // Fecha en la que se realizó el pago
    string metodoPago;            // "pse" o "TCredito"
    float montoTotal;             // Precio total de la reservación
    string anotacion;             // Comentario del huésped (máx 1000 caracteres)

public:
    // Constructores
    Reservacion(); // Por defecto
    Reservacion(const string& codigoReserva,
                const string& codigoAlojamiento,
                const string& documentoHuesped,
                const Fecha& fechaEntrada,
                int duracionNoches,
                const Fecha& fechaPago,
                const string& metodoPago,
                float montoTotal,
                const string& anotacion = "");

    // Getters
    string getCodigoReserva() const;
    string getCodigoAlojamiento() const;
    string getDocumentoHuesped() const;
    Fecha getFechaEntrada() const;
    Fecha getFechaSalida() const; // = fechaEntrada + duración
    Fecha getFechaPago() const;
    int getDuracion() const;
    string getMetodoPago() const;
    float getMontoTotal() const;
    string getAnotacion() const;
    Reservacion getReserva(int indice) const;


    // Setters
    void setAnotacion(const string& nuevaAnotacion);

    // Mostrar resumen de la reservación
    void mostrarResumen() const;
};

#endif

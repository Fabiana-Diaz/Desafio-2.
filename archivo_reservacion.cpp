#include "archivo_reservacion.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Función auxiliar para convertir fecha en formato entero YYYYMMDD
int fechaAEntero(const Fecha& f) {
    return f.getAnio() * 10000 + f.getMes() * 100 + f.getDia();
}

// Función auxiliar para reconstruir fecha desde entero YYYYMMDD
Fecha fechaDesdeEntero(int valor) {
    int anio = valor / 10000;
    int mes = (valor / 100) % 100;
    int dia = valor % 100;
    return Fecha(dia, mes, anio);
}

// Cargar reservaciones desde archivo
int cargarReservacionesDesdeArchivo(Reservacion* lista, int max) {
    ifstream archivo("reservaciones.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir reservaciones.txt. Se creará uno nuevo al guardar.\n";
        return 0;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea) && contador < max) {
        stringstream ss(linea);
        string codigo, codAloj, docHuesped, metodo, anotacion;
        int fechaEntradaInt, duracion, fechaPagoInt;
        float monto;

        getline(ss, codigo, '|');
        getline(ss, codAloj, '|');
        getline(ss, docHuesped, '|');
        ss >> fechaEntradaInt; ss.ignore();
        ss >> duracion; ss.ignore();
        ss >> fechaPagoInt; ss.ignore();
        getline(ss, metodo, '|');
        ss >> monto; ss.ignore();
        getline(ss, anotacion);

        Fecha fEntrada = fechaDesdeEntero(fechaEntradaInt);
        Fecha fPago = fechaDesdeEntero(fechaPagoInt);

        lista[contador++] = Reservacion(
            codigo, codAloj, docHuesped, fEntrada, duracion, fPago, metodo, monto, anotacion
            );
    }

    archivo.close();
    return contador;
}

// Guardar todas las reservaciones en archivo
void guardarReservacionesEnArchivo(const Reservacion* lista, int cantidad) {
    ofstream archivo("reservaciones.txt");
    if (!archivo.is_open()) {
        cerr << "Error al guardar reservaciones.txt\n";
        return;
    }

    for (int i = 0; i < cantidad; ++i) {
        const Reservacion& r = lista[i];
        archivo << r.getCodigoReserva() << '|'
                << r.getCodigoAlojamiento() << '|'
                << r.getDocumentoHuesped() << '|'
                << fechaAEntero(r.getFechaEntrada()) << '|'
                << r.getDuracion() << '|'
                << fechaAEntero(r.getFechaPago()) << '|'
                << r.getMetodoPago() << '|'
                << r.getMontoTotal() << '|'
                << r.getAnotacion() << '\n';
    }

    archivo.close();
}

#include <iostream>
#include "alojamiento.h"
#include "anfitrion.h"
#include "huesped.h"
#include "reservacion.h"
#include "menu.h"  //  Incluye el header del menú

// Declaraciones de funciones para cargar y guardar datos
int cargarAlojamientosDesdeArchivo(Alojamiento[], int);
void guardarAlojamientosEnArchivo(Alojamiento[], int);
int cargarAnfitrionesDesdeArchivo(Anfitrion[], int, Alojamiento[], int);
void guardarAnfitrionesEnArchivo(const Anfitrion[], int);
int cargarHuespedesDesdeArchivo(Huesped[], int);
void guardarHuespedesEnArchivo(const Huesped[], int);
int cargarReservacionesDesdeArchivo(Reservacion[], int);
void guardarReservacionesEnArchivo(const Reservacion[], int);

int main() {
    const int MAX = 100;
    Alojamiento alojamientos[MAX];
    Anfitrion anfitriones[MAX];
    Huesped huespedes[MAX];
    Reservacion reservas[MAX];
    int cantidadAlojamientos = 0;
    int cantidadAnfitriones = 0;
    int cantidadHuespedes = 0;
    int cantidadReservas = 0;

    // Cargar datos desde archivos
    cantidadAlojamientos = cargarAlojamientosDesdeArchivo(alojamientos, MAX);
    cantidadAnfitriones = cargarAnfitrionesDesdeArchivo(anfitriones, MAX, alojamientos, cantidadAlojamientos);
    cantidadHuespedes = cargarHuespedesDesdeArchivo(huespedes, MAX);
    cantidadReservas = cargarReservacionesDesdeArchivo(reservas, MAX);

    // Asignar reservaciones cargadas a huéspedes
    for (int i = 0; i < cantidadReservas; ++i) {
        string doc = reservas[i].getDocumentoHuesped();
        for (int j = 0; j < cantidadHuespedes; ++j) {
            if (huespedes[j].getDocumento() == doc) {
                huespedes[j].agregarReserva(reservas[i]);
                break;
            }
        }
    }

    std::cout << "\nArchivos cargados correctamente.\n";
    std::cout << cantidadAlojamientos << " alojamientos, "
              << cantidadAnfitriones << " anfitriones, "
              << cantidadHuespedes << " huespedes, "
              << cantidadReservas << " reservas.\n";

    // Iniciar el menú principal del sistema
    menu(alojamientos, cantidadAlojamientos,
         anfitriones, cantidadAnfitriones,
         huespedes, cantidadHuespedes,
         reservas, cantidadReservas);

    return 0;
}



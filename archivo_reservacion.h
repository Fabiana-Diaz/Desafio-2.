#ifndef ARCHIVO_RESERVACION_H
#define ARCHIVO_RESERVACION_H

#include "reservacion.h"

int cargarReservacionesDesdeArchivo(Reservacion* lista, int max);
void guardarReservacionesEnArchivo(const Reservacion* lista, int cantidad);
void guardarReservacionesEnArchivo(const Reservacion*, int);

#endif

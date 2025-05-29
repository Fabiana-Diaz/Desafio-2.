#ifndef ARCHIVO_HUESPED_H
#define ARCHIVO_HUESPED_H

#include "huesped.h"

int cargarHuespedesDesdeArchivo(Huesped* huespedes, int max);
void guardarHuespedesEnArchivo(const Huesped* huespedes, int cantidad);

#endif

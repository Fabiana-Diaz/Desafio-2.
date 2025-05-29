#ifndef MENU_H
#define MENU_H

#include "alojamiento.h"
#include "anfitrion.h"
#include "huesped.h"
#include "reservacion.h"

void menu(Alojamiento* alojamientos, int& cantidadAlojamientos,
          Anfitrion* anfitriones, int& cantidadAnfitriones,
          Huesped* huespedes, int& cantidadHuespedes,
          Reservacion* reservas, int& cantidadReservas);

#endif

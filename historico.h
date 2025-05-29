#ifndef HISTORICO_H
#define HISTORICO_H

#include "fecha.h"
#include "reservacion.h"
#include <string>

void actualizarHistorico(Reservacion* reservas, int& totalReservas, const Fecha& corte, const std::string& nombreArchivo);

#endif

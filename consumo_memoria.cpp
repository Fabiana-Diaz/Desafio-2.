// consumo_memoria.cpp
#include "consumo_memoria.h"

int ConsumoMemoria::memoriaTotal = 0;

void ConsumoMemoria::agregar(int bytes) {
    memoriaTotal += bytes;
}

int ConsumoMemoria::obtener() {
    return memoriaTotal;
}

void ConsumoMemoria::reiniciar() {
    memoriaTotal = 0;
}

#include "contador_iteraciones.h"

int ContadorIteraciones::iteraciones = 0;
int ContadorIteraciones::total = 0;

void ContadorIteraciones::incrementar(int cantidad) {
    iteraciones += cantidad;
    total += cantidad;
}

int ContadorIteraciones::obtener() {
    return iteraciones;
}

void ContadorIteraciones::reiniciar() {
    iteraciones = 0;
}

int ContadorIteraciones::obtenerTotal() {
    return total;
}




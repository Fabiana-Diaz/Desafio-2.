#ifndef CONTADOR_ITERACIONES_H
#define CONTADOR_ITERACIONES_H

class ContadorIteraciones {
private:
    static int iteraciones;
    static int total;
public:
    static void incrementar(int cantidad = 1);
    static int obtener();
    static void reiniciar();
    static int obtenerTotal();
};

#endif


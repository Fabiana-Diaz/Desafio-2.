// consumo_memoria.h
#ifndef CONSUMO_MEMORIA_H
#define CONSUMO_MEMORIA_H

class ConsumoMemoria {
private:
    static int memoriaTotal;
public:
    static void agregar(int bytes);
    static int obtener();
    static void reiniciar();
};

#endif


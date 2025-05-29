#ifndef FECHA_H
#define FECHA_H

#include <string>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructores
    Fecha();
    Fecha(int d, int m, int a);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Comparaciones (para ordenamiento o verificación de fechas)
    bool igual(const Fecha& otra) const;
    bool menorQue(const Fecha& otra) const;
    bool menorIgualQue(const Fecha& otra) const;
    bool mayorQue(const Fecha& otra) const;
    bool mayorIgualQue(const Fecha& otra) const;

    // Métodos útiles
    void mostrarExtendido() const;
    int toEntero() const; // Representación YYYYMMDD
    Fecha sumarDias(int n) const;

    // Sobrecarga para comparación (se define *fuera* de la clase)
    friend bool operator<(const Fecha& a, const Fecha& b);
    friend bool operator<=(const Fecha& a, const Fecha& b);
    friend bool operator>(const Fecha& a, const Fecha& b);
    friend bool operator>=(const Fecha& a, const Fecha& b);
};

#endif

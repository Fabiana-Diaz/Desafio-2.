#include "fecha.h"
#include "contador_iteraciones.h"
#include "consumo_memoria.h"

#include <iostream>
#include <iomanip>

using namespace std;

// Constructor por defecto: asigna una fecha inválida por defecto (opcionalmente puedes usar fecha actual si deseas)
Fecha::Fecha() : dia(1), mes(1), anio(2000) {
ConsumoMemoria::agregar(sizeof(Fecha));
}
// Constructor con parámetros
Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
    ConsumoMemoria::agregar(sizeof(Fecha));}

// Getters
int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }

// Método que devuelve un entero con formato AAAAMMDD (útil para comparar)
int Fecha::toEntero() const {
    return anio * 10000 + mes * 100 + dia;
}

// Mostrar la fecha en formato: "martes, 27 de mayo del 2025"
void Fecha::mostrarExtendido() const {
    string dias[] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
    string meses[] = {"", "enero", "febrero", "marzo", "abril", "mayo", "junio",
                      "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    // Algoritmo de Zeller para obtener el día de la semana
    int a = (14 - mes) / 12;
    int y = anio - a;
    int m = mes + 12 * a - 2;
    int d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    cout << dias[d] << ", " << dia << " de " << meses[mes] << " del " << anio << endl;
}

// Comparaciones personalizadas
bool Fecha::igual(const Fecha& otra) const {
    return dia == otra.dia && mes == otra.mes && anio == otra.anio;
}

bool Fecha::menorQue(const Fecha& otra) const {
    return toEntero() < otra.toEntero();
}

bool Fecha::menorIgualQue(const Fecha& otra) const {
    return toEntero() <= otra.toEntero();
}

bool Fecha::mayorQue(const Fecha& otra) const {
    return toEntero() > otra.toEntero();
}

bool Fecha::mayorIgualQue(const Fecha& otra) const {
    return toEntero() >= otra.toEntero();
}

// Sumar días a una fecha (versión simplificada, sin considerar meses diferentes)
Fecha Fecha::sumarDias(int n) const {
    // Suponiendo 30 días por mes (simplificación)
    int totalDias = dia + n;
    int nuevoDia = totalDias;
    int nuevoMes = mes;
    int nuevoAnio = anio;

    while (nuevoDia > 30) {
        ContadorIteraciones::incrementar();
        nuevoDia -= 30;
        nuevoMes++;
        if (nuevoMes > 12) {
            nuevoMes = 1;
            nuevoAnio++;
        }
    }

    return Fecha(nuevoDia, nuevoMes, nuevoAnio);
}

// Sobrecarga de operadores (fuera de la clase)
bool operator<(const Fecha& a, const Fecha& b) {
    return a.toEntero() < b.toEntero();
}

bool operator<=(const Fecha& a, const Fecha& b) {
    return a.toEntero() <= b.toEntero();
}

bool operator>(const Fecha& a, const Fecha& b) {
    return a.toEntero() > b.toEntero();
}

bool operator>=(const Fecha& a, const Fecha& b) {
    return a.toEntero() >= b.toEntero();
}

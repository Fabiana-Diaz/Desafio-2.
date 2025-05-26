#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

    static const char* nombresDias[7];
    static const char* nombresMeses[12];
public:
    // Constructores
    Fecha(); // Fecha por defecto
    Fecha(int d, int m, int a);

    // Métodos de acceso
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

     // Métodos funcionales
    bool esAnteriorA(const Fecha& otra) const;
    bool esIgualA(const Fecha& otra) const;

    Fecha sumarDias(int cantidad) const; // devuelve nueva fecha

    void mostrarExtendido() const; // imprime: "lunes, 15 de mayo del 2025"

 // Utilidades
    int calcularDiaSemana() const; // 0=domingo, 1=lunes,...
    bool esFechaValida() const;

    // Operadores sobrecargados
    bool operator<(const Fecha& otra) const;
    bool operator==(const Fecha& otra) const;
};



#endif // FECHA_H

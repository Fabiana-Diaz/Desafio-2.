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
#endif // FECHA_H

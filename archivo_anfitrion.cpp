// archivo_anfitrion.cpp
#include "anfitrion.h"
#include "alojamiento.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Cargar anfitriones desde archivo y vincular sus alojamientos
int cargarAnfitrionesDesdeArchivo(Anfitrion* anfitriones, int maxAnfitriones, Alojamiento* alojamientos, int cantidadAlojamientos) {
    ifstream archivo("anfitriones.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de anfitriones." << endl;
        return 0;
    }

    string linea;
    int count = 0;

    while (getline(archivo, linea) && count < maxAnfitriones) {
        stringstream ss(linea);
        string nombre, documento, codigosStr;
        int antiguedad;
        float puntuacion;

        getline(ss, nombre, '|');
        getline(ss, documento, '|');
        ss >> antiguedad;
        ss.ignore(); // ignora el '|'
        ss >> puntuacion;
        ss.ignore(); // ignora el '|'
        getline(ss, codigosStr);

        // Crear anfitrión y agregar al arreglo
        Anfitrion a(nombre, documento, antiguedad, puntuacion, 10);

        // Procesar los códigos de alojamiento y asociarlos
        stringstream codigosSS(codigosStr);
        string codigo;
        while (getline(codigosSS, codigo, ',')) {
            for (int i = 0; i < cantidadAlojamientos; ++i) {
                if (alojamientos[i].getCodigo() == codigo) {
                    Alojamiento* ptr = new Alojamiento(alojamientos[i]);
                    a.agregarAlojamiento(ptr);
                }
            }
        }

        anfitriones[count++] = a;
    }

    archivo.close();
    return count;
}

// Guardar anfitriones en archivo
void guardarAnfitrionesEnArchivo(const Anfitrion anfitriones[], int cantidad) {
    ofstream archivo("anfitriones.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de anfitriones para guardar." << endl;
        return;
    }

    for (int i = 0; i < cantidad; ++i) {
        archivo << anfitriones[i].getDocumento() << "|"
                << anfitriones[i].getAntiguedad() << "|"
                << anfitriones[i].getPuntuacion() << "|"
                << anfitriones[i].getNombre() << endl;
    }

    archivo.close();
}

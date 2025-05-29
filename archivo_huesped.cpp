#include <fstream>
#include <sstream>
#include "archivo_huesped.h"
#include "contador_iteraciones.h"

int cargarHuespedesDesdeArchivo(Huesped* huespedes, int max) {
    ifstream archivo("huespedes.txt");
    if (!archivo.is_open()) return 0;

    string linea;
    int count = 0;

    while (getline(archivo, linea) && count < max) {
        ContadorIteraciones::incrementar();
        stringstream ss(linea);
        string doc;
        int ant;
        float punt;

        getline(ss, doc, '|');
        ss >> ant;
        ss.ignore(); // Saltar '|'
        ss >> punt;

        huespedes[count++] = Huesped(doc, ant, punt);
    }

    archivo.close();
    return count;
}

void guardarHuespedesEnArchivo(const Huesped* huespedes, int cantidad) {
    ofstream archivo("huespedes.txt");

    for (int i = 0; i < cantidad; ++i) {
        ContadorIteraciones::incrementar();
        archivo << huespedes[i].getDocumento() << "|"
                << huespedes[i].getAntiguedad() << "|"
                << huespedes[i].getPuntuacion() << endl;
    }

    archivo.close();
}

#include <iostream>
#include "alojamiento.h"
using namespace std;

// Declaraciones de funciones externas (archivo_alojamiento.cpp)
int cargarAlojamientosDesdeArchivo(Alojamiento[], int);
void guardarAlojamientosEnArchivo(Alojamiento[], int);

int main() {
    const int MAX = 100;
    Alojamiento alojamientos[MAX];
    int cantidad = 0;

    // 1. Cargar alojamientos desde archivo
    cantidad = cargarAlojamientosDesdeArchivo(alojamientos, MAX);
    cout << "Se cargaron " << cantidad << " alojamientos desde el archivo." << endl;

    // 2. Mostrar los alojamientos cargados
    for (int i = 0; i < cantidad; ++i) {
        cout << "\nAlojamiento #" << (i + 1) << ":" << endl;
        alojamientos[i].mostrar();
        cout << "--------------------------" << endl;
    }

    // 3. Agregar un nuevo alojamiento (de prueba)
    cout << "\nAgregando un alojamiento nuevo..." << endl;

    string nuevasAmenidades[3] = {"piscina", "wifi", "parqueadero"};
    Alojamiento nuevo("Cabania el Lago", "CBN123", "Km 7 via Guatape",
                      "Antioquia", "Guatape", "casa", 4.7,
                      nuevasAmenidades, 3, "Carlos Gómez");

    alojamientos[cantidad++] = nuevo;

    // 4. Guardar todos los alojamientos nuevamente
    guardarAlojamientosEnArchivo(alojamientos, cantidad);
    cout << "Todos los alojamientos fueron guardados exitosamente." << endl;

    return 0;
}

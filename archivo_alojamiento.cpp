#include "alojamiento.h"
#include <iostream>
#include <fstream>
#include <stdexcept> // Para manejar errores de conversión

using namespace std;

// Función para guardar alojamientos en archivo
void guardarAlojamientosEnArchivo(Alojamiento alojamientos[], int cantidad) {
    ofstream archivo("alojamientos.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    for (int i = 0; i < cantidad; ++i) {
        archivo << alojamientos[i].serializar() << endl;
    }

    archivo.close();
}

// Función para cargar alojamientos desde archivo
int cargarAlojamientosDesdeArchivo(Alojamiento alojamientos[], int maxAlojamientos) {
    ifstream archivo("alojamientos.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de alojamientos." << endl;
        return 0;
    }

    string linea;
    int count = 0;

    while (getline(archivo, linea) && count < maxAlojamientos) {
        if (linea.empty()) continue; // Ignorar líneas vacías

        string temp[9]; // Cada línea debe tener 9 campos
        int campo = 0;
        string valor = "";

        for (size_t i = 0; i <= linea.length(); ++i) {
            if (i == linea.length() || linea[i] == '|') {
                temp[campo++] = valor;
                valor = "";
            } else {
                valor += linea[i];
            }
        }

        if (campo < 9) {
            cout << "Línea inválida (faltan campos): " << linea << endl;
            continue; // Salta líneas mal formateadas
        }

        float puntuacion = 0.0;
        try {
            puntuacion = stof(temp[6]); // Campo 6 = puntuación
        } catch (invalid_argument& e) {
            cout << "Error: puntuación inválida en la línea → " << linea << endl;
            puntuacion = 0.0f;
        }

        // Procesar amenidades separadas por comas
        string amenidades[6];
        int cantidadAmenidades = 0;
        string amenidad = "";

        for (size_t i = 0; i <= temp[7].length(); ++i) {
            if (i == temp[7].length() || temp[7][i] == ',') {
                if (!amenidad.empty() && cantidadAmenidades < 6) {
                    amenidades[cantidadAmenidades++] = amenidad;
                }
                amenidad = "";
            } else {
                amenidad += temp[7][i];
            }
        }

        // Crear el objeto Alojamiento
        alojamientos[count] = Alojamiento(temp[1], // nombre
                                          temp[0], // código
                                          temp[2], // dirección
                                          temp[3], // departamento
                                          temp[4], // municipio
                                          temp[5], // tipo
                                          puntuacion,
                                          amenidades,
                                          cantidadAmenidades,
                                          temp[8]); // nombreAnfitrion
        count++;
    }

    archivo.close();
    return count;
}

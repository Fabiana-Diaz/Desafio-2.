#include <iostream>
#include <fstream>
#include <string>
#include "historico.h"
#include "reservacion.h"
#include "contador_iteraciones.h"
#include "consumo_memoria.h"

using namespace std;


void actualizarHistorico(Reservacion* reservas, int& totalReservas, const Fecha& corte, const string& nombreArchivo) {
    // Paso 1: Verificar que la fecha de corte NO sea menor que la más reciente en el archivo histórico
    ifstream verificador(nombreArchivo);
    string primeraLinea;
    if (getline(verificador, primeraLinea) && !primeraLinea.empty()) {
        int anio = stoi(primeraLinea.substr(0, 4));
        int mes = stoi(primeraLinea.substr(5, 2));
        int dia = stoi(primeraLinea.substr(8, 2));
        Fecha fechaMasReciente(dia, mes, anio);

        if (corte < fechaMasReciente) {
            cout << "[ERROR] La fecha de corte es menor que la fecha más reciente en el histórico.\n";
            verificador.close();
            return;
        }
    }
    verificador.close();

    // Paso 2: Crear archivo temporal para el nuevo histórico
    ofstream temp("temp_historico.txt");
    ifstream original(nombreArchivo);

    // Paso 3: Mover las reservaciones pasadas
    for (int i = 0; i < totalReservas; ) {
        ContadorIteraciones::incrementar();
        if (reservas[i].getFechaEntrada() < corte) {
            Fecha f = reservas[i].getFechaEntrada();
            temp << f.getAnio() << "-"
                 << (f.getMes() < 10 ? "0" : "") << f.getMes() << "-"
                 << (f.getDia() < 10 ? "0" : "") << f.getDia()
                 << " | CodigoResv: " << reservas[i].getCodigoReserva()
                 << " | Alojamiento: " << reservas[i].getCodigoAlojamiento()
                 << " | Huesped: " << reservas[i].getDocumentoHuesped()
                 << " | Noches: " << reservas[i].getDuracion()
                 << " | Monto: " << reservas[i].getMontoTotal()
                 << " | MetodoPago: " << reservas[i].getMetodoPago()
                 << endl;

            for (int j = i; j < totalReservas - 1; j++) {
                ContadorIteraciones::incrementar();
                reservas[j] = reservas[j + 1];
            }
            totalReservas--;
        } else {
            i++;
        }
    }

    // Paso 4: Copiar las líneas anteriores del histórico
    string linea;
    while (getline(original, linea)) {
        ContadorIteraciones::incrementar();
        temp << linea << endl;
    }

    original.close();
    temp.close();

    // Paso 5: Reemplazar el archivo viejo por el nuevo
    remove(nombreArchivo.c_str());
    rename("temp_historico.txt", nombreArchivo.c_str());
}

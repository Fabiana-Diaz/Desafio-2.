#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "alojamiento.h"
#include "anfitrion.h"
#include "huesped.h"
#include "reservacion.h"
#include "fecha.h"
#include "contador_iteraciones.h"
#include "archivo_reservacion.h"

using namespace std;



void reservarAlojamiento(Huesped* huespedes, int cantidadHuespedes,
                         Alojamiento* alojamientos, int cantidadAlojamientos,
                         Reservacion* reservas, int& cantidadReservas);

void anularReservacion(Reservacion* reservas, int& cantidadReservas, const string& docUsuario);
void consultarReservasAnfitrion(const Anfitrion* anfitriones, int cantidadAnfitriones);
void actualizarHistorico(Reservacion* reservas, int& cantidadReservas, const Fecha& corte, const string& nombreArchivo);


void menu(Alojamiento* alojamientos, int& cantidadAlojamientos,
          Anfitrion* anfitriones, int& cantidadAnfitriones,
          Huesped* huespedes, int& cantidadHuespedes,
          Reservacion* reservas, int& cantidadReservas) {

    int tipoUsuario;
    cout << "Seleccione su rol:\n1. Huesped\n2. Anfitrion\nOpcion: ";
    cin >> tipoUsuario;
    cin.ignore();

    string doc;
    bool encontrado = false;

    if (tipoUsuario == 1) {
        cout << "Ingrese su documento: ";
        getline(cin, doc);
        Huesped* h = nullptr;
        for (int i = 0; i < cantidadHuespedes; ++i) {
            ContadorIteraciones::incrementar();
            if (huespedes[i].getDocumento() == doc) {
                h = &huespedes[i];
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Huesped no registrado.\n";
            return;
        }

        int opcion;
        do {
            cout << "\nMenu Huesped:\n1. Reservar alojamiento\n2. Anular reservacion\n0. Salir\nOpcion: ";
            cin >> opcion;
            switch (opcion) {
            case 1:
                reservarAlojamiento(huespedes, cantidadHuespedes, alojamientos, cantidadAlojamientos, reservas, cantidadReservas);
                break;
            case 2:
                anularReservacion(reservas, cantidadReservas, doc);
                break;
            }
        } while (opcion != 0);
        ContadorIteraciones::incrementar();

    } else if (tipoUsuario == 2) {
        cout << "Ingrese su documento: ";
        getline(cin, doc);
        Anfitrion* a = nullptr;
        for (int i = 0; i < cantidadAnfitriones; ++i) {
            ContadorIteraciones::incrementar();
            if (anfitriones[i].getDocumento() == doc) {
                a = &anfitriones[i];
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Anfitrion no registrado.\n";
            return;
        }

        int opcion;
        do {
            cout << "\nMenu Anfitrion:\n1. Anular reservacion\n2. Consultar reservaciones\n3. Actualizar historico\n0. Salir\nOpcion: ";
            cin >> opcion;
            switch (opcion) {
            case 1:
                anularReservacion(reservas, cantidadReservas, doc);
                break;
            case 2:
                consultarReservasAnfitrion(anfitriones, cantidadAnfitriones);
                break;
            case 3: {
                int dia, mes, anio;
                cout << "Fecha de corte para el histórico (DD MM AAAA): ";
                cin >> dia >> mes >> anio;
                Fecha corte(dia, mes, anio);
                actualizarHistorico(reservas, cantidadReservas, corte, "historico.txt");
                break;
            }
            }
        } while (opcion != 0);
        ContadorIteraciones::incrementar();
    } else {
        cout << "Opción inválida.\n";
    }
}


void anularReservacion(Reservacion* reservas, int& cantidadReservas, const string& docUsuario) {
    string codigo;
    cout << "Ingrese el codigo de reservacion a anular: ";
    cin >> codigo;

    for (int i = 0; i < cantidadReservas; ++i) {
        ContadorIteraciones::incrementar();
        if (reservas[i].getCodigoReserva() == codigo && reservas[i].getDocumentoHuesped() == docUsuario) {
            for (int j = i; j < cantidadReservas - 1; ++j) {
                reservas[j] = reservas[j + 1];
            }
            cantidadReservas--;
            cout << "Reservacion anulada.\n";
            return;
        }
    }
    cout << "Reservacion no encontrada o no autorizada.\n";
}

void consultarReservasAnfitrion(const Anfitrion* anfitriones, int cantidadAnfitriones) {
    string documento;
    cout << "\nIngrese su documento como anfitrion: ";
    cin >> documento;

    const Anfitrion* anfitrionEncontrado = nullptr;

    for (int i = 0; i < cantidadAnfitriones; ++i) {
        ContadorIteraciones::incrementar();
        if (anfitriones[i].getDocumento() == documento) {
            anfitrionEncontrado = &anfitriones[i];
            break;
        }
    }

    if (!anfitrionEncontrado) {
        cout << "Anfitrion no encontrado.\n";
        return;
    }

    int fechaInicioInt, fechaFinInt;
    cout << "Ingrese la fecha de inicio del rango (YYYYMMDD): ";
    cin >> fechaInicioInt;
    cout << "Ingrese la fecha de fin del rango (YYYYMMDD): ";
    cin >> fechaFinInt;

    Fecha inicio(fechaInicioInt % 100, (fechaInicioInt / 100) % 100, fechaInicioInt / 10000);
    Fecha fin(fechaFinInt % 100, (fechaFinInt / 100) % 100, fechaFinInt / 10000);

    anfitrionEncontrado->mostrarReservasEnRango(inicio, fin);
}

void actualizarHistorico(Reservacion* reservas, int& cantidadReservas) {
    int dia, mes, anio;
    cout << "Fecha de corte (DD MM YYYY): ";
    cin >> dia >> mes >> anio;
    Fecha corte(dia, mes, anio);

    for (int i = 0; i < cantidadReservas; ) {
        ContadorIteraciones::incrementar();
        if (reservas[i].getFechaSalida() < corte) {
            // Aquí se escribiría la reservación al archivo histórico (no implementado aún)
            for (int j = i; j < cantidadReservas - 1; ++j) {
                reservas[j] = reservas[j + 1];
            }
            cantidadReservas--;
        } else {
            ++i;
        }
    }
    cout << "Historico actualizado.\n";
}

void reservarAlojamiento(Huesped* huespedes, int cantidadHuespedes,
                         Alojamiento* alojamientos, int cantidadAlojamientos,
                         Reservacion* reservas, int& cantidadReservas) {
    string documento;
    cout << "Ingrese su documento para validar la reserva: ";
    cin >> documento;

    // Buscar huesped
    Huesped* h = nullptr;
    for (int i = 0; i < cantidadHuespedes; ++i) {
        ContadorIteraciones::incrementar();
        if (huespedes[i].getDocumento() == documento) {
            h = &huespedes[i];
            break;
        }
    }
    if (!h) {
        cout << "Huesped no encontrado.\n";
        return;
    }

    // Ingresar criterios de búsqueda
    string municipio;
    int noches;
    cout << "Municipio de destino: ";
    cin.ignore();
    getline(cin, municipio);
    cout << "Cantidad de noches: ";
    cin >> noches;

    int dia, mes, anio;
    cout << "Fecha de entrada (DD MM YYYY): ";
    cin >> dia >> mes >> anio;
    Fecha entrada(dia, mes, anio);

    // Opcional: filtros
    float costoMax;
    float puntMin;
    char usarFiltro;
    cout << "¿Desea usar filtros? (s/n): ";
    cin >> usarFiltro;

    bool usarCosto = false, usarPuntuacion = false;
    if (usarFiltro == 's' || usarFiltro == 'S') {
        cout << "¿Filtrar por costo maximo? (s/n): ";
        cin >> usarFiltro;
        if (usarFiltro == 's' || usarFiltro == 'S') {
            usarCosto = true;
            cout << "Costo maximo por noche: ";
            cin >> costoMax;
        }

        cout << "¿Filtrar por puntuacion minima del anfitrion? (s/n): ";
        cin >> usarFiltro;
        if (usarFiltro == 's' || usarFiltro == 'S') {
            usarPuntuacion = true;
            cout << "Puntuacion mínima del anfitrion: ";
            cin >> puntMin;
        }
    }

    // Buscar alojamientos disponibles
    cout << "\nAlojamientos disponibles:\n";
    int encontrados = 0;
    for (int i = 0; i < cantidadAlojamientos; ++i) {
        ContadorIteraciones::incrementar();
        Alojamiento& a = alojamientos[i];

        if (a.getMunicipio() != municipio) continue;

        if (usarCosto || usarPuntuacion) {
            if (usarCosto /* && a.getCosto() > costoMax */) continue; // si tienes getCosto()
            if (usarPuntuacion && a.getCalificacion() < puntMin) continue;
        }

        // Validar disponibilidad
        bool disponible = true;
        Fecha salida = entrada.sumarDias(noches);
        for (int j = 0; j < a.getCantidadReservas(); ++j) {
            ContadorIteraciones::incrementar();
            Reservacion r = a.getReserva(j);
            if (!(r.getFechaSalida() < entrada || r.getFechaEntrada() > salida)) {
                disponible = false;
                break;
            }
        }

        if (disponible) {
            a.mostrar();
            ++encontrados;
        }
    }

    if (encontrados == 0) {
        cout << "No se encontraron alojamientos disponibles con esos criterios.\n";
        return;
    }

    // Reservar
    string codigoAlojamiento;
    cout << "Ingrese el codigo del alojamiento que desea reservar: ";
    cin >> codigoAlojamiento;

    Alojamiento* seleccionado = nullptr;
    for (int i = 0; i < cantidadAlojamientos; ++i) {
        ContadorIteraciones::incrementar();
        if (alojamientos[i].getCodigo() == codigoAlojamiento) {
            seleccionado = &alojamientos[i];
            break;
        }
    }

    if (!seleccionado) {
        cout << "Alojamiento no encontrado.\n";
        return;
    }

    // Verificar conflictos de fechas
    Fecha salida = entrada.sumarDias(noches);
    for (int j = 0; j < seleccionado->getCantidadReservas(); ++j) {
        ContadorIteraciones::incrementar();
        Reservacion r = seleccionado->getReserva(j);
        if (!(r.getFechaSalida() < entrada || r.getFechaEntrada() > salida)) {
            cout << "Ese alojamiento no esta disponible en ese rango.\n";
            return;
        }
    }

    // Crear reservación
    string codigoReserva = "R" + to_string(1000 + cantidadReservas); // ejemplo básico
    Fecha fechaPago = entrada; // suposición
    string metodoPago;
    cout << "Metodo de pago (pse/TCredito): ";
    cin >> metodoPago;

    float montoTotal = noches * 100000; // ejemplo fijo
    string anotacion;
    cout << "Comentario de la estadia: ";
    cin.ignore();
    getline(cin, anotacion);

    Reservacion nueva(codigoReserva, codigoAlojamiento, documento, entrada, noches,
                      fechaPago, metodoPago, montoTotal, anotacion);

    reservas[cantidadReservas++] = nueva;
    seleccionado->agregarReserva(nueva);

    cout << "Reservacion confirmada. Codigo: " << codigoReserva << endl;
    nueva.mostrarResumen();
    guardarReservacionesEnArchivo(reservas, cantidadReservas);

}

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alojamiento.cpp \
        anfitrion.cpp \
        archivo_alojamiento.cpp \
        archivo_anfitrion.cpp \
        archivo_huesped.cpp \
        archivo_reservacion.cpp \
        consumo_memoria.cpp \
        contador_iteraciones.cpp \
        fecha.cpp \
        historico.cpp \
        huesped.cpp \
        main.cpp \
        menu.cpp \
        reservacion.cpp

HEADERS += \
    alojamiento.h \
    anfitrion.h \
    archivo_huesped.h \
    archivo_reservacion.h \
    consumo_memoria.h \
    contador_iteraciones.h \
    fecha.h \
    historico.h \
    huesped.h \
    menu.h \
    reservacion.h

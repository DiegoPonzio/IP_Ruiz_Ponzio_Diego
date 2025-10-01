#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// Definicion de nuestras estructuras

// Estructura para manejar las reservas
typedef struct {
    int tipo_habitacion; // 1 = Sencilla, 2 = Doble, 3 = Suite
    int numero_huesped;
    int numero_personas;
    char celular[15];
    float costo_noche;
    int numero_noches;
    float costo_subtotal;
    float costo_total;
} Reserva;

typedef struct {
    int acum_sencilla;
    float total_sencilla;
} HabitacionSencilla;

typedef struct {
    int acum_doble;
    float total_doble;
} HabitacionDoble;

typedef struct {
    int acum_suite;
    float total_suite;
} HabitacionSuite;

// Estructura para manejar el resumen del dia
typedef struct {
    HabitacionSencilla sencilla;
    HabitacionDoble doble;
    HabitacionSuite suite;
} Hotel;

#endif
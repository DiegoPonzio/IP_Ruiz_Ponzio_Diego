#include <stdio.h>
#include <math.h>
#include <stdbool.h> // Se incluye la libreria stdbool.h para usar el tipo de dato booleano
#include "estructuras.h"


float CalcularCostoNoche(int tipo_habitacion)
{
    switch (tipo_habitacion)
    {
        case 1:
            return 100;
        case 2:
            return 250;
        case 3:
            return 500;
        default:
            return 0;
    }
}

float CalcularCostoTotal(float costo_subtotal)
{
    const float iva = 0.16; // 16% de IVA
    const float impuesto = 0.12; // 12% de impuesto local

    // Aplicamos el IVA y el impuesto local al costo subtotal
    return costo_subtotal * (1 + iva + impuesto);
}

Reserva Reservar()
{
    // Creamos nuestro tipo Reserva
    Reserva nueva_reserva;
    nueva_reserva.numero_noches = (rand() % 10) + 1; // Generamos un numero aleatorio entre 1 y 10

    printf("==============================================\n");
    printf("    Seleccione una opcion (0 para regresar):  \n");
    printf("1 = Sencilla: $100\n");
    printf("2 = Doble: $250\n");
    printf("3 = Suite: $500\n");
    scanf("%d", &nueva_reserva.tipo_habitacion);
    printf("Numero de huesped: ");
    scanf("%d", &nueva_reserva.numero_huesped);
    printf("Numero de personas: ");
    scanf("%d", &nueva_reserva.numero_personas);
    printf("Numero de celular: ");
    scanf("%s", nueva_reserva.celular);
    
    nueva_reserva.costo_noche = CalcularCostoNoche(nueva_reserva.tipo_habitacion);
    nueva_reserva.costo_subtotal = nueva_reserva.costo_noche * nueva_reserva.numero_noches;
    nueva_reserva.costo_total =  CalcularCostoTotal(nueva_reserva.costo_subtotal);


    printf("Costo por Noche: $%.2f\n", nueva_reserva.costo_noche);
    printf("Noches Generadas: %d\n", nueva_reserva.numero_noches);
    printf("Costo Subtotal: $%.2f\n", nueva_reserva.costo_subtotal);
    printf("Costo Total: $%.2f\n", nueva_reserva.costo_total);
    printf("==============================================\n");

    return nueva_reserva;
}

void Bienvenida()
{
    printf("================================\n");
    printf("  Bienvenido al hotel Holiday   \n");
    printf("================================\n");
}

void Resumen(Hotel hotel, int tipo)
{
    char *nombre_tipo = tipo == 1 ? "del Dia" : "Total";
    printf("==============================================\n");
    printf("        Resumen %s en el hotel          \n", nombre_tipo);
    printf("==============================================\n");
    printf("Tipo de Habitacion | No. Reservas | Ingresos  \n");
    printf("==============================================\n");
    printf("Sencilla           |      %d      | $%.2f\n", hotel.sencilla.acum_sencilla, hotel.sencilla.total_sencilla);
    printf("Doble              |      %d      | $%.2f\n", hotel.doble.acum_doble, hotel.doble.total_doble);
    printf("Suite              |      %d      | $%.2f\n", hotel.suite.acum_suite, hotel.suite.total_suite);
    printf("==============================================\n");
}

Hotel CalcularDia(Hotel hotel, Reserva reserva)
{
    switch (reserva.tipo_habitacion)
    {
        case 1:
            hotel.sencilla.acum_sencilla++;
            hotel.sencilla.total_sencilla += reserva.costo_total;
            break;
        case 2:
            hotel.doble.acum_doble++;
            hotel.doble.total_doble += reserva.costo_total;
            break;
        case 3:
            hotel.suite.acum_suite++;
            hotel.suite.total_suite += reserva.costo_total;
            break;
        default:
            break;
    }
    return hotel;
}

Hotel ReservacionDia()
{
    // Durante un dia, el hotel puede tener multiples reservas
    int continuar = 1;
    Hotel hotel = {0}; // Inicializamos el hotel con 0 reservas y 0 ingresos

    while (continuar)
    {
        Reserva nueva_reserva = Reservar();
        hotel = CalcularDia(hotel, nueva_reserva);

        printf("Desea realizar otra reserva? (1 = Si, 0 = No): ");
        scanf("%d", &continuar);
    }

    Resumen(hotel, 1);
    return hotel;
}

Hotel CalcularFinDia(Hotel hotel, Hotel ReservasDia)
{
    // Al finalizar el dia, se suman las reservas y los ingresos del dia al total del hotel
    hotel.sencilla.acum_sencilla += ReservasDia.sencilla.acum_sencilla;
    hotel.sencilla.total_sencilla += ReservasDia.sencilla.total_sencilla;
    hotel.doble.acum_doble += ReservasDia.doble.acum_doble;
    hotel.doble.total_doble += ReservasDia.doble.total_doble;
    hotel.suite.acum_suite += ReservasDia.suite.acum_suite;
    hotel.suite.total_suite += ReservasDia.suite.total_suite;
    
    return hotel;
}

int main()
{
    const int ciclo = 30; // Numero de iteraciones del ciclo principal
    Hotel hotel = {0}; // Inicializamos el hotel con 0 reservas y 0 ingresos

    Bienvenida();
    for (int i = 0; i < ciclo; i++)
    {
        printf("Dia %d\n", i + 1);

        // Por cada iteracion, se simula un dia en el hotel
        // En la variable hotel, se acumulan las reservas y los ingresos
        // Se calcula el resumen del dia al finalizar las reservas
        hotel = CalcularFinDia(hotel, ReservacionDia());

        printf("\n");
        printf("Fin del dia %d\n", i + 1);
        printf("\n");
        printf("Presione Enter para continuar al siguiente dia...\n");
        getchar(); // Captura el salto de linea pendiente
    }

    Resumen(hotel, 2); // Al finalizar el ciclo, se muestra el resumen total del hotel
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" // Importas las definiciones

int main() {
    int opcion;
    Resultado* listaTotal = malloc(0); // arreglo vacío inicialmente
    int totalIndex = 0;

    Bienvenida();

    do
    {
        printf("Seleccione una opcion (0 para salir):\n");
        printf("1 = Fisica\n");
        printf("2 = geometria\n");
        printf("3 = matematicas\n");
        scanf("%d", &opcion);

        Resultado* nuevos = NULL;

        switch (opcion)
        {
            case 1:
                nuevos = Fisica();
                break;
            case 2:
                nuevos = Geometria();
                break;
            case 3:
                nuevos = Matematicas();
                break;
            case 0:
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        if (nuevos) {
            // Usamos la función para agregar resultados al arreglo total
            listaTotal = AgregarResultados(listaTotal, &totalIndex, nuevos);
            free(nuevos); // liberar memoria temporal
        }

    } while (opcion != 0);
    
    // Imprimir todos los resultados al final
    if (totalIndex > 0) {
        LimpiarPantalla();
        ImprimirResultados(listaTotal, totalIndex);
    } else {
        printf("No se realizaron operaciones.\n");
    }

    free(listaTotal); // liberar memoria final

    Despedida();
    return 0;
}
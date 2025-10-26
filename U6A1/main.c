#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" // Importas las definiciones

int main() {
    int opcionMenu;
    Alumno* alumnos = NULL;
    int numAlumnos = 0;

    Bienvenida();

    do
    {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Agregar nuevo alumno\n");
        printf("2. Leer alumnos desde archivo de TEXTO\n");
        printf("3. Leer alumnos desde archivo BINARIO\n");
        printf("4. Guardar alumnos en archivo de TEXTO\n");
        printf("5. Guardar alumnos en archivo BINARIO\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcionMenu);

        switch (opcionMenu) {
            case 1:
                LimpiarPantalla();
                alumnos = EjecutarAlumnos(&numAlumnos);
                break;
            case 2:
                LimpiarPantalla();
                alumnos = LeerTexto("output/alumnos.txt", &numAlumnos);

                // Imprimir los alumnos leídos
                for (int i = 0; i < numAlumnos; i++) {
                    ImprimirAlumnoConResultados(&alumnos[i]);
                }
                break;
            case 3:
                LimpiarPantalla();
            
                alumnos = LeerBinario("output/alumnos.bin", &numAlumnos);
                
                // Imprimir los alumnos leídos
                for (int i = 0; i < numAlumnos; i++) {
                    ImprimirAlumnoConResultados(&alumnos[i]);
                }
                break;
            case 4:
                LimpiarPantalla();
                if (numAlumnos > 0) {
                    GuardarTexto("output/alumnos.txt", alumnos, numAlumnos);
                    printf("\n Datos guardados correctamente en texto.\n");
                } else {
                    printf("\n No hay datos para guardar.\n");
                }
                break;
            case 5:
                LimpiarPantalla();
                if (numAlumnos > 0) {
                    GuardarBinario("output/alumnos.bin", alumnos, numAlumnos);
                    printf("\n Datos guardados correctamente en binario.\n");
                } else {
                    printf("\n No hay datos para guardar.\n");
                }
                break;
            case 0:
                LimpiarPantalla();
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
                break;
        }
    } while (opcionMenu != 0);
    
    // Liberar memoria
    for (int i = 0; i < numAlumnos; i++) {
        free(alumnos[i].resultados);
    }
    free(alumnos);

    Despedida();
    return 0;
}

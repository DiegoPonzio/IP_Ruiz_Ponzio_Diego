#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones.h" // Importas las definiciones

// Funcion parametrizada para realizar la suma de dos numeros
double CalculoSuma(double a, double b) {
    return a + b;
}

// Función para limpiar la pantalla
void LimpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Mensaje de bienvenida al iniciar el programa
void Bienvenida() {
    printf("==================================================\n");
    printf("    SISTEMA DE FISICA, GEOMETRIA Y MATEMATICAS    \n");
    printf("==================================================\n");
}

// Mensaje de despedida al salir del programa
void Despedida() {
    printf("===================================\n");
    printf("    Gracias por usar el sistema!   \n");
    printf("===================================\n");
}

// Mensaje de regreso al menu principal
void Regresando() {
    printf("=======================================\n");
    printf("    Regresando al menu principal...    \n");
    printf("=======================================\n");
}

// Genera los calculos de fisica: velocidad, tiempo y distancia
Resultado* Fisica() {
    int opcion;
    int capacidad = 3;  // tamaño inicial
    double distancia, velocidad, tiempo;
    int index = 0;

    // Creamos un arreglo para almacenar los resultados
    Resultado* resultados = malloc(capacidad * sizeof(Resultado));
    if (!resultados) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    do {
        printf("Seleccione una opcion (0 para regresar):\n");
        printf("---- FISICA ----\n");
        printf("1 = Calcular Velocidad\n");
        printf("2 = Calcular Tiempo\n");
        printf("3 = Calcular Distancia\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 3 && index >= capacidad) {
            capacidad *= 2;
            resultados = realloc(resultados, capacidad * sizeof(Resultado));
            if (!resultados) {
                printf("Error al reasignar memoria.\n");
                return NULL;
            }
        }

        switch (opcion) {
            case 1:
                printf("Ingrese la distancia (D): ");
                scanf("%lf", &distancia);
                printf("Ingrese el tiempo (T): ");
                scanf("%lf", &tiempo);
                velocidad = distancia / tiempo;
                printf("Formula: V = D / T\n");
                printf("Resultado: Velocidad = %.2lf\n", velocidad);

                strcpy(resultados[index].categoria, "Fisica");
                strcpy(resultados[index].operacion, "Velocidad");
                strcpy(resultados[index].formula, "V = D / T");
                strcpy(resultados[index].parametros[0].nombre, "Distancia");
                resultados[index].parametros[0].valor = distancia;
                strcpy(resultados[index].parametros[1].nombre, "Tiempo");
                resultados[index].parametros[1].valor = tiempo;
                resultados[index].resultado = velocidad;
                index++;
                break;

            case 2:
                printf("Ingrese la distancia (D): ");
                scanf("%lf", &distancia);
                printf("Ingrese la velocidad (V): ");
                scanf("%lf", &velocidad);
                tiempo = distancia / velocidad;
                printf("Formula: T = D / V\n");
                printf("Resultado: Tiempo = %.2lf\n", tiempo);

                strcpy(resultados[index].categoria, "Fisica");
                strcpy(resultados[index].operacion, "Tiempo");
                strcpy(resultados[index].formula, "T = D / V");
                strcpy(resultados[index].parametros[0].nombre, "Distancia");
                resultados[index].parametros[0].valor = distancia;
                strcpy(resultados[index].parametros[1].nombre, "Velocidad");
                resultados[index].parametros[1].valor = velocidad;
                resultados[index].resultado = tiempo;
                index++;
                break;

            case 3:
                printf("Ingrese la velocidad (V): ");
                scanf("%lf", &velocidad);
                printf("Ingrese el tiempo (T): ");
                scanf("%lf", &tiempo);
                distancia = velocidad * tiempo;
                printf("Formula: D = V * T\n");
                printf("Resultado: Distancia = %.2lf\n", distancia);

                strcpy(resultados[index].categoria, "Fisica");
                strcpy(resultados[index].operacion, "Distancia");
                strcpy(resultados[index].formula, "D = V * T");
                strcpy(resultados[index].parametros[0].nombre, "Velocidad");
                resultados[index].parametros[0].valor = velocidad;
                strcpy(resultados[index].parametros[1].nombre, "Tiempo");
                resultados[index].parametros[1].valor = tiempo;
                resultados[index].resultado = distancia;
                index++;
                break;

            case 0:
                Regresando();
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        printf("\n");
    } while (opcion != 0);

    LimpiarPantalla();

    // Marcar el final con categoria vacía
    if (index < capacidad) {
        resultados[index].categoria[0] = '\0';
    }

    return resultados;
}

// Genera los calculos de matematicas: suma, residuo y potencia
Resultado* Matematicas() {
    int opcion;
    double num1 = 0, num2 = 0, resultado = 0;
    int capacidad = 3;
    int index = 0;

    Resultado* resultados = malloc(capacidad * sizeof(Resultado));
    if (!resultados) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    do {
        printf("Seleccione una opcion (0 para regresar):\n");
        printf("---- Matematicas ----\n");
        printf("1 = Suma de dos numeros\n");
        printf("2 = Residuo de dos numeros\n");
        printf("3 = Potencia de un numero a la n\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion >=1 && opcion <=3 && index >= capacidad) {
            capacidad *= 2;
            resultados = realloc(resultados, capacidad * sizeof(Resultado));
            if (!resultados) {
                printf("Error al reasignar memoria.\n");
                return NULL;
            }
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el primer numero: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo numero: ");
                scanf("%lf", &num2);
                resultado = CalculoSuma(num1, num2);
                printf("Formula: S = A + B\n");
                printf("Resultado: Suma = %.2lf\n", resultado);

                strcpy(resultados[index].categoria, "Matematicas");
                strcpy(resultados[index].operacion, "Suma");
                strcpy(resultados[index].formula, "S = A + B");
                strcpy(resultados[index].parametros[0].nombre, "A");
                resultados[index].parametros[0].valor = num1;
                strcpy(resultados[index].parametros[1].nombre, "B");
                resultados[index].parametros[1].valor = num2;
                resultados[index].resultado = resultado;
                index++;
                break;

            case 2:
                printf("Ingrese el primer numero: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo numero: ");
                scanf("%lf", &num2);
                resultado = fmod(num1, num2);
                printf("Formula: R = A %% B\n");
                printf("Resultado: Residuo = %.2lf\n", resultado);

                strcpy(resultados[index].categoria, "Matematicas");
                strcpy(resultados[index].operacion, "Residuo");
                strcpy(resultados[index].formula, "R = A %% B");
                strcpy(resultados[index].parametros[0].nombre, "A");
                resultados[index].parametros[0].valor = num1;
                strcpy(resultados[index].parametros[1].nombre, "B");
                resultados[index].parametros[1].valor = num2;
                resultados[index].resultado = resultado;
                index++;
                break;

            case 3:
                printf("Ingrese la base (A): ");
                scanf("%lf", &num1);
                printf("Ingrese el exponente (B): ");
                scanf("%lf", &num2);
                resultado = pow(num1, num2);
                printf("Formula: P = A ^ B\n");
                printf("Resultado: Potencia = %.2lf\n", resultado);

                strcpy(resultados[index].categoria, "Matematicas");
                strcpy(resultados[index].operacion, "Potencia");
                strcpy(resultados[index].formula, "P = A ^ B");
                strcpy(resultados[index].parametros[0].nombre, "Base");
                resultados[index].parametros[0].valor = num1;
                strcpy(resultados[index].parametros[1].nombre, "Exponente");
                resultados[index].parametros[1].valor = num2;
                resultados[index].resultado = resultado;
                index++;
                break;

            case 0:
                Regresando();
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        printf("\n");

    } while (opcion != 0);

    LimpiarPantalla();
    
    // Marcar el final con categoria vacía
    if (index < capacidad) {
        resultados[index].categoria[0] = '\0';
    }

    return resultados;
}

// Genera los calculos de geometria: area de circulo, area total de cono y area total de cubo
Resultado* Geometria() {
    int opcion;
    double radio = 0, lado = 0, altura = 0, area = 0;
    const double PI = 3.1416;

    int capacidad = 3;
    int index = 0;
    Resultado* resultados = malloc(capacidad * sizeof(Resultado));
    if (!resultados) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    do {
        printf("Seleccione una opcion (0 para regresar):\n");
        printf("---- GEOMETRIA ----\n");
        printf("1 = Area de un circulo\n");
        printf("2 = Area total de un cono\n");
        printf("3 = Area total de un cubo\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion >=1 && opcion <=3 && index >= capacidad) {
            capacidad *= 2;
            resultados = realloc(resultados, capacidad * sizeof(Resultado));
            if (!resultados) {
                printf("Error al reasignar memoria.\n");
                return NULL;
            }
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el radio (r): ");
                scanf("%lf", &radio);
                area = PI * pow(radio, 2);
                printf("Formula: A = PI * r^2\n");
                printf("Resultado: Area del circulo = %.2lf\n", area);

                strcpy(resultados[index].categoria, "Geometria");
                strcpy(resultados[index].operacion, "Area Circulo");
                strcpy(resultados[index].formula, "A = PI * r^2");
                strcpy(resultados[index].parametros[0].nombre, "Radio");
                resultados[index].parametros[0].valor = radio;
                strcpy(resultados[index].parametros[1].nombre, "N/A");
                resultados[index].parametros[1].valor = 0;
                resultados[index].resultado = area;
                index++;
                break;

            case 2:
                printf("Ingrese el radio (r): ");
                scanf("%lf", &radio);
                printf("Ingrese la altura (h): ");
                scanf("%lf", &altura);
                double generatriz = sqrt(radio * radio + altura * altura);
                area = PI * radio * (radio + generatriz);
                printf("Formula: A = π*r*(r + g)\n");
                printf("Resultado: Area total del cono = %.2lf\n", area);

                strcpy(resultados[index].categoria, "Geometria");
                strcpy(resultados[index].operacion, "Area Cono");
                strcpy(resultados[index].formula, "A = π*r*(r + g)");
                strcpy(resultados[index].parametros[0].nombre, "Radio");
                resultados[index].parametros[0].valor = radio;
                strcpy(resultados[index].parametros[1].nombre, "Altura");
                resultados[index].parametros[1].valor = altura;
                resultados[index].resultado = area;
                index++;
                break;

            case 3:
                printf("Ingrese el lado (L): ");
                scanf("%lf", &lado);
                area = 6 * pow(lado, 2);
                printf("Formula: A = 6 * L^2\n");
                printf("Resultado: Area total del cubo = %.2lf\n", area);

                strcpy(resultados[index].categoria, "Geometria");
                strcpy(resultados[index].operacion, "Area Cubo");
                strcpy(resultados[index].formula, "A = 6 * L^2");
                strcpy(resultados[index].parametros[0].nombre, "Lado");
                resultados[index].parametros[0].valor = lado;
                strcpy(resultados[index].parametros[1].nombre, "N/A");
                resultados[index].parametros[1].valor = 0;
                resultados[index].resultado = area;
                index++;
                break;

            case 0:
                Regresando();
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        printf("\n");

    } while (opcion != 0);

    LimpiarPantalla();

    // Marcar el final con categoria vacía
    if (index < capacidad) {
        resultados[index].categoria[0] = '\0';
    }

    return resultados;
}

// Función para agregar nuevos resultados a la lista total
Resultado* AgregarResultados(Resultado* total, int* totalIndex, Resultado* nuevos) {
    int capacidad = *totalIndex + 3; // capacidad inicial aproximada
    int i = 0;

    // Contar los elementos en nuevos
    while (nuevos[i].categoria[0] != '\0') i++;
    int nNuevos = i;

    // Reasignar memoria para total
    total = realloc(total, (*totalIndex + nNuevos) * sizeof(Resultado));
    if (!total) {
        printf("Error al reasignar memoria.\n");
        return NULL;
    }

    // Copiar los resultados
    for (int j = 0; j < nNuevos; j++) {
        total[*totalIndex + j] = nuevos[j];
    }

    *totalIndex += nNuevos;
    return total;
}

// Función para imprimir la tabla de Resultados
void ImprimirResultados(Resultado *lista, int n)
{
    printf("==========================================================================================================================\n");
    printf("%-15s | %-25s | %-20s | %-20s | %-15s | %-10s\n",
        "Categoria", "Operacion", "Param1", "Param2", "Formula", "Resultado");
    printf("==========================================================================================================================\n");

    for (int i = 0; i < n; i++) {
        char param1[20], param2[20];

        // Usamos strncpy para copiar y asegurar tamaño máximo
        snprintf(param1, sizeof(param1), "%s = %.2f", 
            lista[i].parametros[0].nombre, 
            lista[i].parametros[0].valor);

        param1[sizeof(param1)-1] = '\0';

        // Verificamos si el segundo parámetro está vacío
        if (strlen(lista[i].parametros[1].nombre) == 0) {
            snprintf(param2, sizeof(param2), "N/A");
        } else {
            snprintf(param2, sizeof(param2), "%s = %.2f", 
                    lista[i].parametros[1].nombre, 
                    lista[i].parametros[1].valor);
        }

        param2[sizeof(param2)-1] = '\0';

        printf("%-15s | %-25s | %-20s | %-20s | %-15s | %.2f\n",
            lista[i].categoria,
            lista[i].operacion,
            param1,
            param2,
            lista[i].formula,
            lista[i].resultado);
    }

    printf("==========================================================================================================================\n");
}
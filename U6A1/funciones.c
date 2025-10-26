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

// Imprimir Datos del alumno y sus Resultados
void ImprimirAlumnoConResultados(Alumno *a)
{
    printf("\n Alumno: %s %s\n", a->nombre, a->apellidos);
    printf("Número de resultados: %d\n\n", a->numResultados);

    if (a->numResultados > 0)
        ImprimirResultados(a->resultados, a->numResultados);
    else
        printf("(Sin resultados disponibles)\n");
}

// Función para guardar los resultados en un archivo de texto
void GuardarTexto(const char* nombreArchivo, Alumno* alumnos, int numAlumnos) {
    // Abrir el archivo en modo texto para escritura
    FILE* f = fopen(nombreArchivo, "w");

    // Verificar si el archivo se abrió correctamente
    if (!f) {
        perror("Error al abrir el archivo para escritura");
        return;
    }

    // Escribir la cantidad de alumnos
    fprintf(f, "%d\n", numAlumnos);

    // Iterar sobre cada alumno
    for (int i = 0; i < numAlumnos; i++) {
        // Nombre, apellidos y número de resultados, separados por '|'
        fprintf(f, "%s|%s|%d\n",
                alumnos[i].nombre,
                alumnos[i].apellidos,
                alumnos[i].numResultados);

        // Iterar sobre los resultados de cada alumno estos los separados por '|' para que sea mas facil de leer
        for (int j = 0; j < alumnos[i].numResultados; j++) {
            Resultado r = alumnos[i].resultados[j];

            r.categoria[strcspn(r.categoria, "\n")] = 0;
            r.operacion[strcspn(r.operacion, "\n")] = 0;
            r.formula[strcspn(r.formula, "\n")] = 0;
            r.parametros[0].nombre[strcspn(r.parametros[0].nombre, "\n")] = 0;
            r.parametros[1].nombre[strcspn(r.parametros[1].nombre, "\n")] = 0;

            fprintf(f, "%s|%s|%s|%s|%.2f|%s|%.2f|%.2f\n",
                    r.categoria,
                    r.operacion,
                    r.formula,
                    r.parametros[0].nombre,
                    r.parametros[0].valor,
                    r.parametros[1].nombre,
                    r.parametros[1].valor,
                    r.resultado);
        }
    }

    fclose(f);
}

// Función para leer los resultados de un archivo de texto
Alumno* LeerTexto(const char *nombreArchivo, int *numAlumnos) {
    // Abrir el archivo en modo lectura
    FILE *f = fopen(nombreArchivo, "r");

    // Verificar si el archivo se abrió correctamente
    if (!f) {
        perror("Error al abrir el archivo de texto");
        return NULL;
    }
    
    // Leer el número de alumnos
    if (fscanf(f, "%d\n", numAlumnos) != 1) {
        printf("Error: formato de archivo incorrecto.\n");
        fclose(f);
        return NULL;
    }

    // Reservar memoria para los alumnos
    Alumno *alumnos = malloc((*numAlumnos) * sizeof(Alumno));

    // Verificar si la memoria se asignó correctamente
    if (!alumnos) {
        perror("Error al reservar memoria");
        fclose(f);
        return NULL;
    }

    // Leer los resultados de cada alumno
    for (int i = 0; i < *numAlumnos; i++) {
        // Leer la línea con nombre, apellidos y número de resultados
        char linea[256];
        if (!fgets(linea, sizeof(linea), f)) break;

        // Parsear los datos (nombre y apellidos pueden tener espacios)
        // Ejemplo de línea: "Diego|Ruiz|3"
        char *token = strtok(linea, "|");
        if (!token) continue;
        strcpy(alumnos[i].nombre, token);

        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(alumnos[i].apellidos, token);

        token = strtok(NULL, "|");
        if (!token) continue;
        alumnos[i].numResultados = atoi(token);

        // Reservar memoria para resultados
        alumnos[i].resultados = malloc(alumnos[i].numResultados * sizeof(Resultado));

        // Leer cada resultado
        for (int j = 0; j < alumnos[i].numResultados; j++) {
            if (!fgets(linea, sizeof(linea), f)) break;
            // Parsear los datos del resultado
            // Ejemplo:
            // Fisica|Velocidad|V = D/T|D|9.8|T|2.5|30.6
            token = strtok(linea, "|");
            if (!token) continue;
            strcpy(alumnos[i].resultados[j].categoria, token);

            token = strtok(NULL, "|");
            if (!token) continue;
            strcpy(alumnos[i].resultados[j].operacion, token);

            token = strtok(NULL, "|");
            if (!token) continue;
            strcpy(alumnos[i].resultados[j].formula, token);

            token = strtok(NULL, "|");
            if (!token) continue;
            strcpy(alumnos[i].resultados[j].parametros[0].nombre, token);

            token = strtok(NULL, "|");
            if (!token) continue;
            alumnos[i].resultados[j].parametros[0].valor = atof(token);

            token = strtok(NULL, "|");
            if (!token) continue;
            strcpy(alumnos[i].resultados[j].parametros[1].nombre, token);

            token = strtok(NULL, "|");
            if (!token) continue;
            alumnos[i].resultados[j].parametros[1].valor = atof(token);

            token = strtok(NULL, "|");
            if (!token) continue;
            alumnos[i].resultados[j].resultado = atof(token);
        }
    }

    // Cerrar el archivo
    fclose(f);

    // Devolver la lista de alumnos
    return alumnos;
}

// Función para guardar los resultados en un archivo binario
void GuardarBinario(const char *nombreArchivo, Alumno *alumnos, int numAlumnos) {
    // Abrir el archivo en modo binario para escritura
    FILE *f = fopen(nombreArchivo, "wb");

    // Verificar si el archivo se abrió correctamente
    if (!f) {
        perror("Error al abrir archivo binario");
        return;
    }

    // Guardar el número de alumnos
    fwrite(&numAlumnos, sizeof(int), 1, f);

    for (int i = 0; i < numAlumnos; i++) {
        // Guardar los campos "simples" del alumno
        fwrite(alumnos[i].nombre, sizeof(alumnos[i].nombre), 1, f);
        fwrite(alumnos[i].apellidos, sizeof(alumnos[i].apellidos), 1, f);
        fwrite(&alumnos[i].numResultados, sizeof(int), 1, f);

        // Guardar los resultados
        for (int j = 0; j < alumnos[i].numResultados; j++) {
            Resultado *r = &alumnos[i].resultados[j];

            fwrite(r->categoria, sizeof(r->categoria), 1, f);
            fwrite(r->operacion, sizeof(r->operacion), 1, f);
            fwrite(r->formula, sizeof(r->formula), 1, f);

            // Parametros
            fwrite(r->parametros[0].nombre, sizeof(r->parametros[0].nombre), 1, f);
            fwrite(&r->parametros[0].valor, sizeof(double), 1, f);
            fwrite(r->parametros[1].nombre, sizeof(r->parametros[1].nombre), 1, f);
            fwrite(&r->parametros[1].valor, sizeof(double), 1, f);

            // Resultado final
            fwrite(&r->resultado, sizeof(double), 1, f);
        }
    }

    // Cerrar el archivo
    fclose(f);

    // Confirmar que los datos se guardaron correctamente
    printf("Datos guardados correctamente en binario: %s\n", nombreArchivo);
}

// Función para leer los resultados de un archivo binario
Alumno* LeerBinario(const char *nombreArchivo, int *numAlumnos) {
    // Abrir el archivo en modo binario para lectura
    FILE *f = fopen(nombreArchivo, "rb");

    // Verificar si el archivo se abrió correctamente
    if (!f) {
        perror("Error al abrir archivo binario");
        return NULL;
    }

    // Leer número de alumnos
    fread(numAlumnos, sizeof(int), 1, f);

    // Reservar memoria para los alumnos
    Alumno *alumnos = malloc((*numAlumnos) * sizeof(Alumno));
    // Verificar si la memoria se asignó correctamente
    if (!alumnos) {
        perror("Error al reservar memoria");
        fclose(f);
        return NULL;
    }

    for (int i = 0; i < *numAlumnos; i++) {
        // Leer campos del alumno (sin puntero)
        fread(alumnos[i].nombre, sizeof(alumnos[i].nombre), 1, f);
        fread(alumnos[i].apellidos, sizeof(alumnos[i].apellidos), 1, f);
        fread(&alumnos[i].numResultados, sizeof(int), 1, f);

        // Reservar memoria para los resultados
        alumnos[i].resultados = malloc(alumnos[i].numResultados * sizeof(Resultado));
        if (!alumnos[i].resultados) {
            perror("Error al reservar memoria para resultados");
            // Liberar lo que se había reservado
            for (int k = 0; k < i; k++) free(alumnos[k].resultados);
            free(alumnos);
            fclose(f);
            return NULL;
        }

        // Leer resultados campo por campo
        for (int j = 0; j < alumnos[i].numResultados; j++) {
            Resultado *r = &alumnos[i].resultados[j];

            fread(r->categoria, sizeof(r->categoria), 1, f);
            fread(r->operacion, sizeof(r->operacion), 1, f);
            fread(r->formula, sizeof(r->formula), 1, f);

            fread(r->parametros[0].nombre, sizeof(r->parametros[0].nombre), 1, f);
            fread(&r->parametros[0].valor, sizeof(double), 1, f);
            fread(r->parametros[1].nombre, sizeof(r->parametros[1].nombre), 1, f);
            fread(&r->parametros[1].valor, sizeof(double), 1, f);

            fread(&r->resultado, sizeof(double), 1, f);
        }
    }

    // Cerrar el archivo
    fclose(f);

    // Devolver la lista de alumnos
    return alumnos;
}

// Función para la creacion de los resultados de un alumno
Resultado* EjecutarOperaciones(int* totalResultados)
{
    int opcion;
    Resultado* listaTotal = malloc(0); // arreglo vacío inicialmente
    *totalResultados = 0;

    do
    {
        printf("\n===================================\n");
        printf("Seleccione una opcion (0 para salir):\n");
        printf("1 = Fisica\n");
        printf("2 = Geometria\n");
        printf("3 = Matematicas\n");
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

        if (nuevos)
        {
            listaTotal = AgregarResultados(listaTotal, totalResultados, nuevos);
            free(nuevos); // liberar memoria temporal
        }

    } while (opcion != 0);

    return listaTotal; // devolvemos todos los resultados y su cantidad
}

Alumno* EjecutarAlumnos(int* totalAlumnos)
{
    int opcion;
    Alumno* listaTotal = malloc(0); // arreglo vacío inicialmente
    *totalAlumnos = 0;

    do
    {
        printf("\n===================================\n");
        printf("Seleccione una opcion (0 para salir):\n");
        printf("1 = Agregar nuevo alumno\n");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            Alumno nuevoAlumno;
            printf("Ingrese el nombre del alumno: ");
            scanf("%s", nuevoAlumno.nombre);
            printf("Ingrese los apellidos del alumno: ");
            scanf("%s", nuevoAlumno.apellidos);

            int numResultados = 0;
            nuevoAlumno.resultados = EjecutarOperaciones(&numResultados);
            nuevoAlumno.numResultados = numResultados;

            // Reasignar memoria para listaTotal
            listaTotal = realloc(listaTotal, (*totalAlumnos + 1) * sizeof(Alumno));
            listaTotal[*totalAlumnos] = nuevoAlumno;
            (*totalAlumnos)++;
        }
        else if (opcion != 0)
        {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return listaTotal; // devolvemos todos los alumnos y su cantidad
}
#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para almacenar los parámetros de las operaciones
typedef struct {
    char nombre[30];
    double valor;
} ParametrosDato;


// Estructura para almacenar los resultados de las operaciones y donde pertenece
typedef struct {
    char categoria[20];
    char operacion[40];
    char formula[20];
    ParametrosDato parametros[2];
    double resultado;
} Resultado;

// Estructura para almacenar la información del alumno y sus resultados
typedef struct {
    char nombre[50];
    char apellidos[50];
    Resultado* resultados;
    int numResultados;
} Alumno;

// Funcion para calcular la suma de dos números
double CalculoSuma(double a, double b);

// Función para limpiar la pantalla
void LimpiarPantalla();

// Genera los calculos de geometria: area de circulo, area total de cono y area total de cubo
Resultado* Geometria();

// Genera los calculos de matematicas: suma, residuo y potencia
Resultado* Matematicas();

// Genera los calculos de fisica: velocidad, tiempo y distancia
Resultado* Fisica();

// Mensaje de regreso al menu principal
void Regresando();

// Mensaje de despedida al salir del programa
void Despedida();

// Mensaje de bienvenida al iniciar el programa
void Bienvenida();

// Función para imprimir la tabla de Resultados
void ImprimirResultados(Resultado *lista, int n);

// Imprimir Datos del alumno y sus Resultados
void ImprimirAlumnoConResultados(Alumno *a);

// Función para agregar nuevos resultados a la lista total
Resultado* AgregarResultados(Resultado* total, int* totalIndex, Resultado* nuevos);

// Función para guardar los resultados en un archivo de texto
void GuardarTexto(const char *nombreArchivo, Alumno *alumnos, int numAlumnos);

// Función para leer los resultados de un archivo de texto
Alumno* LeerTexto(const char *nombreArchivo, int *numAlumnos);

// Función para guardar los resultados en un archivo binario
void GuardarBinario(const char *nombreArchivo, Alumno *alumnos, int numAlumnos);

// Función para leer los resultados de un archivo binario
Alumno* LeerBinario(const char *nombreArchivo, int *numAlumnos);

// Función para la creacion de los resultados de un alumno
Resultado* EjecutarOperaciones(int* totalResultados);

Alumno* EjecutarAlumnos(int* totalAlumnos);
#endif
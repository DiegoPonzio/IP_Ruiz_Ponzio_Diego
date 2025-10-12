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

Resultado* AgregarResultados(Resultado* total, int* totalIndex, Resultado* nuevos); 
#endif
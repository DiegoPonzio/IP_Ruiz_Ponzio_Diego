#include <stdio.h>
#include <math.h>

void Bienvenida() {
    printf("==================================================\n");
    printf("    SISTEMA DE FISICA, GEOMETRIA Y MATEMATICAS    \n");
    printf("==================================================\n");
}

void Despedida() {
    printf("===================================\n");
    printf("    Gracias por usar el sistema!   \n");
    printf("===================================\n");
}

void Regresando() {
    printf("=======================================\n");
    printf("    Regresando al menu principal...    \n");
    printf("=======================================\n");
}

void Fisica() {
    int opcion;
    double distancia, velocidad, tiempo;

    do
    {
        printf("Seleccione una opcion (0 para regresar):\n");
        printf("---- FISICA ----\n");
        printf("1 = Calcular Velocidad\n");
        printf("2 = Calcular Tiempo\n");
        printf("3 = Calcular Distancia\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                printf("Ingrese la distancia (D): ");
                scanf("%lf", &distancia);
                printf("Ingrese el tiempo (T): ");
                scanf("%lf", &tiempo);
                velocidad = distancia / tiempo;
                printf("Formula: V = D / T\n");
                printf("Resultado: Velocidad = %.2lf\n", velocidad);
                break;
            case 2:
                printf("Ingrese la distancia (D): ");
                scanf("%lf", &distancia);
                printf("Ingrese la velocidad (V): ");
                scanf("%lf", &velocidad);
                tiempo = distancia / velocidad;
                printf("Formula: T = D / V\n");
                printf("Resultado: Tiempo = %.2lf\n", tiempo);
                break;
            case 3:
                printf("Ingrese la velocidad (V): ");
                scanf("%lf", &velocidad);
                printf("Ingrese el tiempo (T): ");
                scanf("%lf", &tiempo);
                distancia = velocidad * tiempo;
                printf("Formula: D = V * T\n");
                printf("Resultado: Distancia = %.2lf\n", distancia);
                break;
            case 0:
                Regresando();
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        printf("\n");
    } while (opcion != 0);
}

void Matematicas() {
    int opcion;
    double num1, num2, resultado;

    do
    {
        printf("Seleccione una opcion (0 para regresar):\n");
        printf("---- Matematicas ----\n");
        printf("1 = Suma de dos numeros\n");
        printf("2 = Residuo de dos numeros\n");
        printf("3 = Potencia de un numero a la n\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                printf("Ingrese el primer numero: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 + num2;
                printf("Formula: S = A + B\n");
                printf("Resultado: Suma = %.2lf\n", resultado);
                break;
            case 2:
                printf("Ingrese el primer numero: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo numero: ");
                scanf("%lf", &num2);
                resultado = fmod(num1, num2);
                printf("Formula: R = A %% B\n");
                printf("Resultado: Residuo = %.2lf\n", resultado);
                break;
            case 3:
                printf("Ingrese la base (A): ");
                scanf("%lf", &num1);
                printf("Ingrese el exponente (B): ");
                scanf("%lf", &num2);
                resultado = pow(num1, num2);
                printf("Formula: P = A ^ B\n");
                printf("Resultado: Potencia = %.2lf\n", resultado);
                break;
            case 0:
                Regresando();
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        printf("\n");
    } while (opcion != 0);
}

void Geometria() {
    int opcion;
    double radio, lado, altura, area;
    const double PI = 3.1416;

    do
    {
        printf("Seleccione una opcion (0 para regresar):\n");
        printf("---- GEOMETRIA ----\n");
        printf("1 = Area de un circulo\n");
        printf("2 = Area total de un cono\n");
        printf("3 = Area total de un cubo\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                printf("Ingrese el radio (r): ");
                scanf("%lf", &radio);
                area = PI * pow(radio, 2);
                printf("Formula: A = PI * r^2\n");
                printf("Resultado: Area del circulo = %.2lf\n", area);
                break;
            case 2:
                printf("Ingrese el radio (r): ");
                scanf("%lf", &radio);
                printf("Ingrese la altura (h): ");
                scanf("%lf", &altura);
                float generatriz = sqrt(radio * radio + altura * altura);

                area = PI * radio * (radio + generatriz);
                printf("Formula: A =  π*r*(r + g)\n");
                printf("Resultado: Area total del cono = %.2lf\n", area);
                break;
            case 3:
                printf("Ingrese el lado (L): ");
                scanf("%lf", &lado);
                area = 6 * pow(lado, 2);
                printf("Formula: A = 6 * L^2\n");
                printf("Resultado: Area total del cubo = %.2lf\n", area);
                break;
            case 0:
                Regresando();
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
}

int main() {
    int opcion;
    Bienvenida();
    do
    {
        printf("Seleccione una opcion (0 para salir):\n");
        printf("1 = Fisica\n");
        printf("2 = geometria\n");
        printf("3 = matematicas\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                Fisica();
                break;
            case 2:
                Geometria();
                break;
            case 3:
                Matematicas();
                break;
            case 0:
                Despedida();
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
    
    return 0;
}
#include <stdio.h>
#include <stdbool.h> // Se incluye la libreria stdbool.h para usar el tipo de dato booleano

// Se crae la funcion Bienvenida que retorna un mensaje de bienvenida al usuario
// La funcion nos ayuda a mantener el codigo organizado y modular
const char* Bienvenida() {
    return "=====================================\n"
        "||  Sistema de La Gallina Feliz  ||\n"
        "=====================================\n"
        "|| Siga las instrucciones: ||\n";
}

const char* Despedida() {
    return
        "========================================\n"
        "||  Gracias por usar nuestro sistema!  ||\n"
        "=====================================\n";
}

const char* Cerar()
{
    return
        "============================================================================\n"
        "|| Presione 0 para cerrar el programa o 1 para continuar ||\n"
        "============================================================================\n";
}

int main() {
    const char producto[] = "Huevo";
    const float IVA = 0.16; // 16% de IVA

    // Variables para almacenar datos del producto y calculos
    // Se considera el uso de float para manejar decimales en costos
    float costo, subtotal, iva, descuento, total;
    
    // Se considera el uso de int para manejar cantidades enteras
    int cantidad, opcion;
    bool continuar =  true;

    printf("%s", Bienvenida());

    // Se hace un while para permitir multiples entradas de productos
    while (continuar)
    {
        /* code */
        printf("Ingrese el costo del %s: ", producto);
        scanf("%f", &costo);
        printf("Ingrese la cantidad de %s: ", producto);
        scanf("%d", &cantidad);

        // Calculos 
        subtotal = costo * cantidad;
        iva = subtotal * IVA;
        descuento = subtotal * 0.05;
        total = subtotal + iva - descuento;
        
        // Mostrar resultados
        printf("\nSubtotal: $%.2f\n", subtotal);
        printf("IVA (16%%): $%.2f\n", iva);
        printf("Descuento (5%%): $%.2f\n", descuento);
        printf("Total a pagar: $%.2f\n", total);

        // Preguntar si desea continuar
        printf("%s", Cerar());
        scanf("%d", &opcion);

        continuar = opcion != 0;
    }

    printf("%s", Despedida());
    return 0;
}
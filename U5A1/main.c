#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("¿Cuántos elementos quieres almacenar? ");
    
    int longitud;
    scanf("%d", &longitud);
    
    float* valores = (float*) malloc(longitud * sizeof(float));
    if (valores == NULL) {
        printf("No tienes tanta memoria.\n");
        return 1;
    }

    int i;

    for (i = 0; i < longitud; i++) {
        valores[i] = 5.55E5;
    }

    printf("Todo está correcto.\n");
    free(valores);
    return 0;
}
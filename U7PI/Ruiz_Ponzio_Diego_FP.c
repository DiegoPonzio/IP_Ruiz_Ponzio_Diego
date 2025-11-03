/*******************************************************
 * JUEGO DE TRIVIA EN CONSOLA
 * Autor: Diego Ruiz Ponzio
 * Descripción:
 *   - Las preguntas se leen dependiendo de la categoría elegida
 *   - Las preguntas están en "preguntas.txt" y "P_programacion.txt"
 *   - Cada jugador tiene 4 intentos antes de quedar fuera
 *   - El orden de los jugadores es aleatorio
 *   - Los resultados se guardan en "resultados.txt"
 *******************************************************/

#include <stdio.h>      // Para entrada/salida estándar (printf, scanf, fopen, fgets, etc.)
#include <stdlib.h>     // Para funciones generales como rand(), srand(), atoi(), malloc()
#include <string.h>     // Para manejar cadenas (strcpy, strtok, strcmp, etc.)
#include <time.h>       // Para obtener tiempo del sistema (se usa en srand(time(NULL)) para aleatoriedad)
#include <stdbool.h>    // Para usar el tipo booleano (true, false)

// --- Constantes del juego ---
#define MAX_PREGUNTAS 100     // Número máximo de preguntas que se pueden cargar
#define MAX_JUGADORES 4       // Número máximo de jugadores permitidos
#define MAX_TEXTO 256         // Longitud máxima para texto de preguntas, respuestas o nombres
#define MAX_INTENTOS 4        // Intentos disponibles por jugador
#define ARCHIVO_PREGUNTAS "preguntas.txt"  // Archivo de preguntas
#define ARCHIVO_PREGUNTAS_PROGRAMACION "P_programacion.txt" // Archivo de preguntas de programación
#define ARCHIVO_RESULTADOS "resultados.txt" // Archivo de resultados

// --- Estructura que almacena una pregunta del archivo ---
typedef struct {
    char pregunta[MAX_TEXTO];   // Texto de la pregunta
    char respuesta[MAX_TEXTO];  // Respuesta correcta
    int puntos;                 // Puntos que otorga si se responde bien
    char categoria[MAX_TEXTO];  // Categoría de la pregunta
} Pregunta;

// --- Estructura que representa a un jugador ---
typedef struct {
    char nombre[MAX_TEXTO];     // Nombre del jugador
    int puntaje;                // Puntos acumulados
    int intentos;               // Intentos restantes
    bool activo;                 // Indica si el jugador sigue en juego (1=activo, 0=fuera)
} Jugador;

/*******************************************************
 * FUNCIÓN: CargarPreguntas
 * Lee las preguntas desde un archivo de texto con formato:
 *  pregunta:respuesta:puntos
 * Retorna la cantidad de preguntas cargadas exitosamente.
 *******************************************************/

int CargarPreguntas(Pregunta preguntas[]) {
    // Pedimos de que categoria cargar las preguntas
    char categoria[MAX_TEXTO];
    printf("Seleccione la categoria de preguntas (general/programacion): ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = 0; // quitar salto de línea
    const char *archivoPreguntas = (strcmp(categoria, "programacion") == 0) ? ARCHIVO_PREGUNTAS_PROGRAMACION : ARCHIVO_PREGUNTAS;

    FILE *f = fopen(archivoPreguntas, "r"); // Abrir archivo en modo lectura
    if (!f) {
        perror("Error al abrir archivo de preguntas");
        return 0; // Retornar 0 si hubo error
    }

    int count = 0;
    char linea[512];

    // Leer línea por línea hasta llegar al final del archivo o al límite
    while (fgets(linea, sizeof(linea), f) && count < MAX_PREGUNTAS) {
        // Separar la línea en 3 partes usando ":" como delimitador
        char *pregunta = strtok(linea, ":");
        char *respuesta = strtok(NULL, ":");
        char *puntosStr = strtok(NULL, ":\n");

        // Si las tres partes existen, las guardamos en la estructura
        if (pregunta && respuesta && puntosStr) {
            strcpy(preguntas[count].pregunta, pregunta);
            strcpy(preguntas[count].respuesta, respuesta);
            preguntas[count].puntos = atoi(puntosStr); // Convertir puntos de string a int
            strcpy(preguntas[count].categoria, categoria); // Guardar la categoría
            count++;
        }
    }

    fclose(f);
    return count; // Retornar cuántas preguntas se leyeron correctamente
} 


/*******************************************************
 * FUNCIÓN: MezclarJugadores
 * Mezcla aleatoriamente el orden de los jugadores
 * usando el algoritmo de intercambio simple (swap aleatorio).
 *******************************************************/
void MezclarJugadores(Jugador jugadores[], int numJugadores) {
    for (int i = 0; i < numJugadores; i++) {
        int j = rand() % numJugadores; // Índice aleatorio
        // Intercambiar jugadores[i] con jugadores[j]
        Jugador temp = jugadores[i];
        jugadores[i] = jugadores[j];
        jugadores[j] = temp;
    }
}

/*******************************************************
 * FUNCIÓN: QuedanJugadoresActivos
 * Revisa si al menos un jugador sigue con intentos disponibles.
 * Retorna true si hay alguien activo, o false si todos están fuera.
 *******************************************************/
bool QuedanJugadoresActivos(Jugador jugadores[], int numJugadores) {
    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].activo) return true;
    }
    return false;
}

/*******************************************************
 * FUNCIÓN PRINCIPAL
 * Controla el flujo completo del juego.
 *******************************************************/
int main() {
    srand(time(NULL)); // Inicializar aleatoriedad

    Pregunta *preguntas = NULL;  // Usaremos malloc para asignar memoria después
    Jugador *jugadores = NULL;   // También para jugadores

    // --- Cargar preguntas dinámicamente ---
    preguntas = (Pregunta *)malloc(sizeof(Pregunta) * MAX_PREGUNTAS);
    if (preguntas == NULL) {
        printf("Error: no se pudo asignar memoria para las preguntas.\n");
        return 1;
    }

    int numPreguntas = CargarPreguntas(preguntas);
    if (numPreguntas == 0) {
        printf("No se pudieron cargar preguntas.\n");
        free(preguntas); // Liberamos memoria antes de salir
        return 1;
    }

    // --- Pedir número de jugadores ---
    int numJugadores = 0;
    char entrada[10];

    printf("    Bienvenido al juego de trivia !    \n\n");
    printf("Indique cuantas personas van a jugar (minimo 1, maximo 4):\n");

    do {
        printf("> ");
        fgets(entrada, sizeof(entrada), stdin);
        numJugadores = atoi(entrada);

        if (numJugadores < 1 || numJugadores > 4)
            printf("Valor no valido. Ingrese un número entre 1 y 4.\n");

    } while (numJugadores < 1 || numJugadores > 4);

    // --- Reservar memoria dinámica para jugadores ---
    jugadores = (Jugador *)malloc(sizeof(Jugador) * numJugadores);
    if (jugadores == NULL) {
        printf("Error: no se pudo asignar memoria para los jugadores.\n");
        free(preguntas);
        return 1;
    }

    // --- Pedir nombres de jugadores ---
    for (int i = 0; i < numJugadores; i++) {
        printf("Nombre del jugador %d: ", i + 1);
        fgets(jugadores[i].nombre, MAX_TEXTO, stdin);
        jugadores[i].nombre[strcspn(jugadores[i].nombre, "\n")] = 0;

        jugadores[i].puntaje = 0;
        jugadores[i].intentos = MAX_INTENTOS;
        jugadores[i].activo = true;
    }

    // --- Orden aleatorio ---
    MezclarJugadores(jugadores, numJugadores);

    printf("\nOrden de juego aleatorio:\n");
    for (int i = 0; i < numJugadores; i++)
        printf("%d. %s\n", i + 1, jugadores[i].nombre);

    printf("\nComienza la trivia!\n");

    int preguntaIndex = 0;

    // --- Ciclo principal ---
    while (preguntaIndex < numPreguntas && QuedanJugadoresActivos(jugadores, numJugadores)) {
        for (int j = 0; j < numJugadores && preguntaIndex < numPreguntas; j++) {
            if (!jugadores[j].activo) continue;

            printf("\nTurno de %s (Intentos restantes: %d)\n", jugadores[j].nombre, jugadores[j].intentos);
            printf("Pregunta: %s\n> ", preguntas[preguntaIndex].pregunta);

            char respuesta[MAX_TEXTO];
            fgets(respuesta, MAX_TEXTO, stdin);
            respuesta[strcspn(respuesta, "\n")] = 0;

            if (strcasecmp(respuesta, preguntas[preguntaIndex].respuesta) == 0) {
                printf("Correcto! +%d puntos\n", preguntas[preguntaIndex].puntos);
                jugadores[j].puntaje += preguntas[preguntaIndex].puntos;
            } else {
                jugadores[j].intentos--;
                printf("Incorrecto :( . La respuesta era: %s. Intentos restantes: %d\n",
                    preguntas[preguntaIndex].respuesta, jugadores[j].intentos);

                if (jugadores[j].intentos == 0) {
                    jugadores[j].activo = false;
                    printf("%s ha quedado fuera del juego.\n", jugadores[j].nombre);
                }
            }

            preguntaIndex++;
            if (preguntaIndex >= numPreguntas || !QuedanJugadoresActivos(jugadores, numJugadores))
                break;
        }
    }

    // --- Mostrar resultados ---
    printf("\n--- RESULTADOS FINALES ---\n");
    int maxPuntos = -1;
    int indiceGanador = -1;

    for (int i = 0; i < numJugadores; i++) {
        printf("%s: %d puntos\n", jugadores[i].nombre, jugadores[i].puntaje);
        if (jugadores[i].puntaje > maxPuntos) {
            maxPuntos = jugadores[i].puntaje;
            indiceGanador = i;
        }
    }

    if (indiceGanador != -1)
        printf("\nEl ganador es: %s con %d puntos !!!!\n",
            jugadores[indiceGanador].nombre, jugadores[indiceGanador].puntaje);
    else
        printf("\nNadie gano, todos quedaron fuera. :(\n");

    // --- Guardar resultados ---
    FILE *res = fopen(ARCHIVO_RESULTADOS, "w");
    if (res) {
        fprintf(res, "RESULTADOS DE LA TRIVIA (%s)\n\n", preguntas[0].categoria);
        for (int i = 0; i < numJugadores; i++) {
            fprintf(res, "%s: %d puntos (Intentos restantes: %d)\n",
                    jugadores[i].nombre, jugadores[i].puntaje, jugadores[i].intentos);
        }

        if (indiceGanador != -1)
            fprintf(res, "\nGANADOR: %s con %d puntos\n",
                    jugadores[indiceGanador].nombre, jugadores[indiceGanador].puntaje);
        else
            fprintf(res, "\nNadie gano, todos agotaron sus intentos.\n");

        fclose(res);
        printf("\n Resultados guardados en '%s'\n", ARCHIVO_RESULTADOS);
    } else {
        perror("Error al guardar resultados");
    }

    // --- Liberar memoria ---
    free(preguntas);
    free(jugadores);

    return 0;
}

#include <stdio.h>

#define FILAS 5
#define COLUMNAS 5

// Función para inicializar la sala de cine con todos los asientos disponibles
void inicializarSala(char sala[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            sala[i][j] = 'D'; // 'D' indica asiento disponible
        }
    }
}

// Función para mostrar la sala de cine
void mostrarSala(char sala[FILAS][COLUMNAS]) {
    printf("Sala de Cine:\n");
    printf("  ");
    for (int i = 0; i < COLUMNAS; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", sala[i][j]);
        }
        printf("\n");
    }
    printf("Pantalla está en la parte superior\n");
}

// Función para vender un asiento
void venderAsiento(char sala[FILAS][COLUMNAS], float *total, int *boletosVendidos, float precio) {
    int fila, columna;
    printf("Ingrese la fila del asiento a comprar (1-%d): ", FILAS);
    scanf("%d", &fila);
    printf("Ingrese la columna del asiento a comprar (1-%d): ", COLUMNAS);
    scanf("%d", &columna);

    if (fila < 1 || fila > FILAS || columna < 1 || columna > COLUMNAS) {
        printf("Asiento inválido. Intente nuevamente.\n");
    } else if (sala[fila - 1][columna - 1] == 'V') {
        printf("El asiento ya está vendido. Intente con otro.\n");
    } else {
        sala[fila - 1][columna - 1] = 'V'; // 'V' indica asiento vendido
        (*boletosVendidos)++;
        *total += precio;
        printf("Asiento vendido correctamente. Nuevo saldo: %.2f\n", *total);
    }
}

int main() {
    char sala[FILAS][COLUMNAS];
    int opcion;
    float total = 0.0;
    int boletosVendidos = 0;
    float precioBoleto;

    printf("Ingrese el precio del boleto: ");
    scanf("%f", &precioBoleto);

    inicializarSala(sala);

    do {
        printf("\n1. Mostrar sala\n");
        printf("2. Vender asiento\n");
        printf("3. Mostrar total vendido y número de boletos vendidos\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarSala(sala);
                break;
            case 2:
                venderAsiento(sala, &total, &boletosVendidos, precioBoleto);
                break;
            case 3:
                printf("Número de boletos vendidos: %d\n", boletosVendidos);
                printf("Monto total vendido: %.2f\n", total);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

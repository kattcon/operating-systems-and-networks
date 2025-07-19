#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int finishTime;
} Proceso;

int main() {
    Proceso procesos[MAX];
    int n;

    printf("Ingrese cantidad de procesos (máx %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        procesos[i].id = i + 1;
        printf("\nProceso P%d:\n", procesos[i].id);
        printf("  Tiempo de llegada: ");
        scanf("%d", &procesos[i].arrivalTime);
        printf("  Duración (burst time): ");
        scanf("%d", &procesos[i].burstTime);
    }

    // Ordenar por tiempo de llegada (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (procesos[j].arrivalTime > procesos[j + 1].arrivalTime) {
                Proceso temp = procesos[j];
                procesos[j] = procesos[j + 1];
                procesos[j + 1] = temp;
            }
        }
    }

    int tiempoActual = 0;
    for (int i = 0; i < n; i++) {
        if (procesos[i].arrivalTime > tiempoActual) {
            tiempoActual = procesos[i].arrivalTime;
        }

        procesos[i].waitingTime = tiempoActual - procesos[i].arrivalTime;
        procesos[i].finishTime = tiempoActual + procesos[i].burstTime;
        procesos[i].turnaroundTime = procesos[i].finishTime - procesos[i].arrivalTime;

        tiempoActual = procesos[i].finishTime;
    }

    printf("\nResultado (FCFS):\n");
    printf("ID | Llegada | Duración | Espera | Finaliza | Turnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d |   %2d    |   %2d     |   %2d   |    %2d     |     %2d\n",
               procesos[i].id,
               procesos[i].arrivalTime,
               procesos[i].burstTime,
               procesos[i].waitingTime,
               procesos[i].finishTime,
               procesos[i].turnaroundTime);
    }

    return 0;
}

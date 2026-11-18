#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


int total_veces = 0;
int contador = 0;
int intervalo = 0;

void fun_signal(int signum) {
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

   
    printf("Señal de alarma recibida a las %02d:%02d:%02d\n", 
           tm->tm_hour, tm->tm_min, tm->tm_sec);

    contador++;

    if (contador == total_veces) {
        printf("Alarma desactivada\n");
        exit(0);
    }
}

int main() {
    
    printf("¿Cuántas veces sonará la alarma?:\n");
    scanf("%d", &total_veces);

    printf("¿Cada cuántos segundos se repetirá la alarma?:\n");
    scanf("%d", &intervalo);

    
    signal(SIGALRM, fun_signal);

    printf("Alarma activada\n");
    
    

    while (1) {
        alarm(intervalo);
        pause();
    }

    return 0;
}

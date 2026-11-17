#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void fun_signal(int signum) {
   
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fichero = fopen("salidas.txt", "a");
    if (fichero == NULL) {
        perror("Error al abrir el fichero");
        return;
    }

    
    fprintf(fichero, "Señal SIGINT recibida a las %02d:%02d:%02d\n", 
            tm->tm_hour, tm->tm_min, tm->tm_sec);

    fclose(fichero);
}

int main() {
    
    signal(SIGINT, fun_signal);

    while (1) {
        pause();
    }

    return 0;
}

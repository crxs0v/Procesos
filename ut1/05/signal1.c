#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
void fun_signal(int signum){
   time_t t = time(NULL);
   struct tm *tm = localtime(&t);
  printf("\n Fin del proceso %d : %02d/%02d/%d %02d:%02d:%02d\n",
    getpid(), tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, 
    tm->tm_hour, tm->tm_min, tm->tm_sec);
  signal(SIGINT,SIG_DFL);   // Se "re-arma" la señal con su acción por defecto
}


void main(){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
  signal(SIGINT,fun_signal); // Esta línea registra la función manejadora para la señal SIGINT. A partir de aquí, si se pulsa Ctrl+C, se ejecutará fun_signal()
  printf("\n Inicio del proceso %d : %02d/%02d/%d %02d:%02d:%02d\n", 
           getpid(), tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, 
           tm->tm_hour, tm->tm_min, tm->tm_sec);
  pause();
  
}

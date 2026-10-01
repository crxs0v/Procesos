#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main() {
  pid_t proceso2, proceso3, proceso4, proceso5, proceso6;

  proceso2 = fork();

  if (proceso2 == -1) {
    printf("ERROR !!! No se ha podido crear el primer hijo...\n");
  } else if (proceso2 == 0) {
   proceso3 = fork();
    if (proceso3 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
    } else if (proceso3 == 0) {
        proceso5=fork();
        if (proceso5 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
    } else if (proceso5 == 0) {

    }
    }
   proceso4 = fork();
    if (proceso4 == -1) {
        printf("ERROR !!! No se ha podido crear P4...\n");
      } else if (proceso4 == 0) {
        proceso6=fork();
        if (proceso6 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
    } else if (proceso6 == 0) {
        printf("Soy el proceso P6 | PID: %d|PID DE MI ABUELO: %d",getpid());
    }
    }
   
  } else {//proceso padre

     
    wait(NULL);

    if (getpid() % 2 == 0) {
    printf("Soy el proceso P1, par | PID: %d  | PPID: %d\n", getpid(), getppid());
    } else {
    printf("Soy el proceso P1, impar | PID: %d \n", getpid());
    }
    printf("Todos mis hijos han terminado\n");
    
  }

  exit(0);
}

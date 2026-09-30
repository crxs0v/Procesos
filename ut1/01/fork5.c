#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main() {
  pid_t proceso2, proceso3;

  proceso2 = fork();

  if (proceso2 == -1) {
    printf("ERROR !!! No se ha podido crear el primer hijo...\n");
  }

  if (proceso2 == 0) {
   
    proceso3 = fork();

    if (proceso3 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
    }

    if (proceso3 == 0) {
    
      printf("Soy el proceso P3 | PID: %d | PPID: %d\n", getpid(), getppid());
    } else {
     
      wait(NULL);  
      printf("Soy el proceso P2 | PID: %d | PPID: %d\n", getpid(), getppid());
    }

  } else {
    
    wait(NULL);  
    printf("Soy el proceso P1 | PID: %d | PID Hijo: %d\n", getpid(), proceso2);
    printf("Todos mis hijos han terminado\n");
  }

  exit(0);
}

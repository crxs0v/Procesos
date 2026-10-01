#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main() {
  pid_t proceso2, proceso3, proceso4;
  int suma=0;

  proceso2 = fork();

  if (proceso2 == -1) {
    printf("ERROR !!! No se ha podido crear el primer hijo...\n");
  } else if (proceso2 == 0) {

    suma=getpid()+ getppid();
    printf("Soy el proceso P2| PID: %d | PPID: %d |suma: %d\n", getpid(), getppid(),suma);
   
    proceso3 = fork();
    if (proceso3 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
    } else if (proceso3 == 0) {
        suma=getpid()+ getppid();
        printf("Soy el proceso P3| PID: %d | PPID: %d| suma: %d\n", getpid(), getppid(),suma);
       
        proceso4 = fork();
        if (proceso4 == -1) {
        printf("ERROR !!! No se ha podido crear P4...\n");
      } else if (proceso4 == 0) {
        suma=getpid()+ getppid();
        printf("Soy el proceso P4| PID: %d | PPID: %d| suma: %d\n", getpid(), getppid(),suma);
       
      }else{
        wait(NULL);
      }
    }else{
        wait(NULL);
    }
   
  } else {//proceso padre
    wait(NULL);
   

    suma=getpid()+ getppid();
    
    printf("Soy el proceso P1| PID: %d | PPID: %d| suma: %d\n", getpid(), getppid(),suma);

   
    printf("Todos mis hijos han terminado\n");
  }

  exit(0);
}

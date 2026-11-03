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
  } 
  
  else if (proceso2 == 0) {
    pid_t abuelo = getpid();
   proceso3 = fork();
   

    if (proceso3 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
    } 
    else if (proceso3 == 0) {
        proceso5=fork();
        if (proceso5 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
        }else if (proceso5==0){
            printf("Soy el proceso P5 | PID: %d|PID DE MI ABUELO: %d\n",getpid(),abuelo);
        }else{
            //P3 espera a p5
            wait(NULL);
        }
    }else{
    proceso4 = fork();

    if (proceso4 == -1) {
        printf("ERROR !!! No se ha podido crear P4...\n");
    } 
    else if (proceso4 == 0) {
        proceso6=fork();
        if (proceso6 == -1) {
      printf("ERROR !!! No se ha podido crear el segundo hijo...\n");
        } else if (proceso6 == 0) {
        printf("Soy el proceso P6 | PID: %d|PID DE MI ABUELO: %d\n",getpid(),abuelo);
        }else{
            // P4 espera a p6
            wait(NULL);
        }
    }else{
        //pe espera a sus hijos
        wait(NULL);
        wait(NULL);
    }
   }
  } else {//proceso padre

     
    wait(NULL);
   
    printf("Soy el proceso P1");
    printf("Todos mis hijos han terminado");
    }
}

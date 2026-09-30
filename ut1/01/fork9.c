#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid_p2, pid_p3, pid_p4;
  
  pid_p2 = fork();

  if (pid_p2 == -1) {
    perror("Error al crear P2");
   
  } else if (pid_p2 == 0) {
    
    printf("P2: Comienza (PID: %d)\n", getpid());
    sleep(5);
    printf("P2: Termina tras 5 segundos\n");
  } else {
   
    pid_p3 = fork();

    if (pid_p3 == -1) {
      perror("Error al crear P3");
      
    } else if (pid_p3 == 0) {
  
      printf("P3: Comienza (PID: %d)\n", getpid());
      sleep(2);
      printf("P3: Termina tras 2 segundos\n");
    } else {
   
      pid_p4 = fork();

      if (pid_p4 == -1) {
        perror("Error al crear P4");
       
      } else if (pid_p4 == 0) {
       
        printf("P4: Comienza (PID: %d)\n", getpid());
        sleep(4);
        printf("P4: Termina tras 4 segundos\n");
      } else {
        
        wait(NULL);
        wait(NULL);
        wait(NULL);
        printf("P1: Todos mis hijos han terminado\n");
      }
    }
  }
a)Sí, con el numero dentro del sleep() podemos hacer que los procesos despierten antes o después
b)Al eliminar sleep cada ejecución será aleatoria dependiendo del sistema

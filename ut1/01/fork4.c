#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid_hijo1, pid_hijo2;

  pid_hijo1 = fork();
  

  if (pid_hijo1 == -1 ) 
  {
    printf("ERROR !!! No se ha podido crear el primer hijo...");
    exit(-1);       
  }
  
  if (pid_hijo1 == 0 ) 
  {        
  printf("Soy el proceso P2 | PID: %d | PPID: %d\n", getpid(), getppid());
    sleep(3); 
    exit(0);
  }
  else {   //Nos encontramos en Proceso padre 

    pid_hijo2 = fork();

    if (pid_hijo2 == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo2...");
    exit(-1); }
   
    if (pid_hijo2 == 0 ){          
    printf("Soy el proceso P3 | PID: %d | PPID: %d\n", getpid(), getppid());
    sleep(1); 
    exit(0);
    }else{
      wait(NULL); 
      wait(NULL);
    printf("Soy el proceso P1 | PID: %d | PPID: %d\n", getpid(), getppid());
    printf("Todos mis hijos han terminado\n");
    }  
  }
   exit(0);
}

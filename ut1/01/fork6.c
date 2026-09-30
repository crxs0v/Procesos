#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t proceso2, proceso3;

  proceso2 = fork();
  

  if (proceso2 == -1 ) 
  {
    printf("ERROR !!! No se ha podido crear el primer hijo...");
     
  }else if (proceso2 == 0 ) 
  {        
    sleep(10); 
    printf("Proceso 2 despierto. \n");

  }
  else {   //Nos encontramos en Proceso padre 

    proceso3 = fork();

    if (proceso3 == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo2...");
    }else if (proceso3 == 0 ){          
    printf("Soy el proceso P3 | PID: %d | PPID: %d\n", getpid(), getppid());
 
    }else{
      wait(NULL); 
      wait(NULL);
    printf("Soy el proceso P1\n");
    printf("Todos mis hijos han terminado\n");
    }  
  }
   exit(0);
}

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
  {   int suma = 0;
    for (int i = 1; i <= 100; i++) {
      suma += i;
    }     

     printf("Soy P2 (PID: %d) | Operacion: Suma del 1 al 100 | Resultado: %d\n",
           getpid(), suma);

  }
  else {   //Nos encontramos en Proceso padre 

    proceso3 = fork();

    if (proceso3 == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo2...");
    }else if (proceso3 == 0 ){   
        int suma = 0;
   for (int i = 101; i <= 200; i++) {
        suma += i;
    }       
    printf(
          "Soy P3 (PID: %d) | Operacion: Suma del 101 al 200 | Resultado: %d\n",
          getpid(), suma);
 
    }else{
      wait(NULL); 
      wait(NULL);
    printf("Todos los cálculos han finalizado\n");
    }  
  }
   exit(0);
}

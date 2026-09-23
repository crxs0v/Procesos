#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid == -1) 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...\n");
    exit(-1);       
  }
  if (pid == 0)  // Nos encontramos en Proceso hijo 
  {        
    printf("Soy el proceso HIJO \n");     
    printf("Mi PID es: %d \nEl PID de mi padre es: %d\n", getpid(), getppid());
  }
  else    // Nos encontramos en Proceso padre 
  { 
    wait(NULL); 
    printf("\nSoy el proceso PADRE \n");
   
    printf("Mi PID es: %d \nMi hijo tenía el PID: %d\n", getpid(), getppid());
    printf("El proceso hijo ha terminado\n");          
  }
  
  exit(0);
}


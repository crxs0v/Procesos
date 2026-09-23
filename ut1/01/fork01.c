#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo;

  pid = fork();

  if (pid == -1 ) 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (pid == 0 )  //Nos encontramos en Proceso hijo 
  {        
    printf("Soy el proceso HIJO \n");	  
    printf("Mi PID es: =%d \n El PID de mi padre es:  ppid=%d",getpid(),getppid());
  }
  else    //Nos encontramos en Proceso padre 
  { 
    wait(NULL); 
    printf("Soy el proceso PADRE \n");
   
    printf("Mi PID es: pid=%d \n El PID de mi padre es:  ppid=%d",getpid(),getppid());
    printf("El proceso hijo a terminado\n");          
  }
   exit(0);
}


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
    //pid y ppid getpid(), getppid()
    pid_hijo=getpid;
    pid_padre=getppid;
    printf("Mi PID es: pid=% \n El PID de mi padre es:  ppid=%",pid_hijo,pid_padre);
  }
  else    //Nos encontramos en Proceso padre 
  { 
    printf("Soy el proceso PADRE \n");
    pid_hijo = wait(NULL); //espera la finalización del proceso hijo
    //pid y ppid
    pid_hijo=getpid;
    pid_padre=getppid;
    printf("Mi PID es: pid=% \n El PID de mi padre es:  ppid=%",pid_hijo,pid_padre);
    printf("El proceso hijo a terminado\n");          
  }
   exit(0);
}


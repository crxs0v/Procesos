a)
                  [ Proceso Padre ]
                     (PID: 1000)
                     /         \
          pid1=fork()           pid2=fork()
                   /             \
                  v               v
         [ Proceso Hijo 1 ]    [ Proceso Hijo 2 ]
            (PID: 1001)           (PID: 1002)
b)
AAA 
BBB 
CCC 
CCC,
AAA 
CCC 
CCC
BBB, 
AAA se ejecuta siempre , CCC CCC se ejecuta 2 veces por el proceso padre y el proceso hij0 2, ahora la aparicion de B y C es aleatoria.
c)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
 pid2 = fork();
 if(pid2==0){
     printf("CCC \n");
 }
 wait(NULL);
 wait(NULL);
 printf("CCC \n");
 }
 exit(0);
}

a)     [ Proceso Padre ]
          (PID: 1000)
               |
               | fork()
               v
       [ Proceso Hijo ]
          (PID: 1001)
b)Hay 2 salidas posibles una es 
CCC
AAA
BBB
y la otra
CCC
BBB
AAA,
CCC se ejecuta siempre y el hijo o el padre se ejecuta en orden aleatorio cada vez que se ejecuta (pero se ejecutan los 2)
c) 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0){
 {
  wait(NULL);
 printf("AAA \n");
 } else{ printf("BBB \n");
 exit(0);
}

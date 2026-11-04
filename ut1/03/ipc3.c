#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
void main(){
int fd[2];
pipe(fd);
pid_t pid_hijo;
pid_hijo=fork();
char entrada[50];
if(pid_hijo==-1){
    printf("ERROR !!! No se ha podido crear el primer hijo...");   
}
else if (pid_hijo==0){
    close(fd[0]);//escribir
    time_t t;
    int numero1, numero2;

    srand((unsigned) time(&t));
    numero1=rand() % 50; 
    numero2=rand() % 50; 
    write(fd[1], &numero1 sizeof(numero1));
    write(fd[1], &numero2 sizeof(numero2));
    close(fd[1]);
    
    
}else{
    int numero1,num2ero;

    close(fd[1]);//leer
    read(fd[0], &numero1, sizeof(numero1));
    read(fd[0], &numero2, sizeof(numero2));

    close(fd[1]);
    wait(NULL);
    printf("\t%d + %d = %d\n",numero1,numero2,numero1+numero2);
    printf("\t%d - %d = %d\n",numero1,numero2,numero1-numero2);
    printf("\t%d * %d = %d\n",numero1,numero2,numero1*numero2);
    printf("\t%d / %d = %d\n",numero1,numero2,numero1/numero2);
}
}

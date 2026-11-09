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
int fdd[2];
pipe(fdd);
pid_t pid_hijo;
pid_hijo=fork();

if(pid_hijo==-1){
    printf("ERROR !!! No se ha podido crear el primer hijo...");   
}
else if (pid_hijo==0){

    close(fd[1]);//leer el pipe1
    close(fdd[0]);//escribir en el pipe2

    int num;
    read(fd[0], &num, sizeof(num));
    close(fd[0]);

    
    int factorial=1;
    if (num < 0) {
        printf("El número no puede ser negativo.");

    }
    else if (num==0 || num==1){
        factorial=1;
    }

    for (int i = 2; i <= num; i++)
    {
        factorial *= i;
    }

    write(fdd[1], &factorial, sizeof(factorial));
    close(fdd[1]);
    
}else{

    close(fd[0]);//escribir en el pipe1
    close(fdd[1]);//leer el pipe2

    time_t t;
    int num;
    srand((unsigned) time(&t));
    num=rand() % 10; 
    write(fd[1], &num ,sizeof(num));
    close(fd[1]);
    
    int factorial;
    read(fdd[0], &factorial, sizeof(factorial));
    close(fdd[0]);
    wait(NULL);
    printf("El proceso padre genera el número %d en el pipe1\nEl factorial calculado por el proceso hijo :%d! = %d\n",num,num,factorial);
    
    
}
}

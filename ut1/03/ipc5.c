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

    close(fd[0]);//escribir en el pipe1
    close(fdd[1]);//leer el pipe2
    int num;
    printf("Introduzca su número de DNI sin espacios y sin la letra.");
    scanf("%d",&num);
    write(fd[1],&num,sizeof(num));
    close (fd[1]);
  
    int dni;
    read(fdd[0], &dni, sizeof(dni));
    close(fdd[0]);
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    printf("La letra del DNI es %c",letra[dni]);
}else{

    close(fd[1]);//leer el pipe1
    close(fdd[0]);//escribir en el pipe2

    int num;
    read(fd[0], &num, sizeof(num));
    close(fd[0]);

    int dni= num % 23;
    
    write(fdd[1], &dni, sizeof(dni));
    close(fdd[1]);
    wait(NULL);
    
    
}
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main(){
int fd[2];
char buffer[50];
pid_t pid_hijo;
pipe(fd);
pid_hijo=fork();
if(pid_hijo==-1){
    printf("ERROR !!! No se ha podido crear el primer hijo...");
   
}else if (pid_hijo==0){
    close(fd[1]);
    printf("Soy el proceso hijo con pid: %d\n",getpid());
    read(fd[0], buffer, 25);
    printf("Fecha/hora: %s",buffer);
}else{
    close(fd[0]);
    write(fd[1], "Mon Oct 10 18:38:39 2022", 25);  
    wait(NULL);
}

}

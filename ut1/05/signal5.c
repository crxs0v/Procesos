#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int num = 0;
int pidP1=0;
int pidP2=0;
int pidP3=0;

void fun_signal(int signum) {

if(num==0){
printf("Mandando señal de terminación al proceso P2 con pid %d\n",pidP2);
printf("Mandando señal de terminación al proceso P3 con pid %d\n",pidP3);
printf("Fin proceso padre con pid %d\n",pidP1);
}
signal(SIGINT,SIG_DFL);

}


int main() {
  
int fd[2];
pipe(fd);
pid_t pid_hijo, pid_hijo2;
pid_hijo=fork();

if(pid_hijo==-1){
printf("ERROR !!! No se ha podido crear el primer hijo...");
}else if (pid_hijo==0){
pidP2=getpid();
close(fd[1]);//leer
read(fd[0], &num, sizeof(num));
close(fd[1]);
if(num%2==0 && num!=0){
printf("\tNúmero par %d recibido por el proceso P2 con pid %d\n",num,getpid());
}
}else{

pidP1=getpid();

signal(SIGUSR1,fun_signal);
close(fd[0]);//escribir

int num;
printf("Introduce un número:\n");
scanf("%d", &num);
write(fd[1], &num ,sizeof(num));
close(fd[1]);

if(num==0){
kill(getpid(),SIGUSR1);
return 0;}
}
pid_hijo2=fork();
if(pid_hijo==-1){
printf("ERROR !!! No se ha podido crear el primer hijo...");
}else if (pid_hijo2==0){
pidP3=0;

close(fd[1]);//leer
read(fd[0], &num, sizeof(num));
close(fd[1]);
if(num%2!=0){
printf("\tNúmero impar %d recibido por el proceso P3 con pid %d\n",num,getpid());
}
}
}

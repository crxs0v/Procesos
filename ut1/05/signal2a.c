#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


int tiempo=0;
void fun_signal(int signum){
    tiempo += 5;
   printf("Han transcurrido %d segundos\n",tiempo);
}


int main(){
  signal(SIGUSR1,fun_signal); 
  while(1){
    sleep(5);
    kill(getpid(),SIGUSR1);
  }
  return 0;
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


int tiempo=0;
void fun_signal(int signum){
    tiempo += 5;
   printf("Han transcurrido %d segundos\n",tiempo);
   alarm(5);
}


int main(){
  signal(SIGALRM,fun_signal); 
  alarm(5);
  while(1){
    pause();
  }
  return 0;
}

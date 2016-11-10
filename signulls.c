#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    int fd = open("log",O_CREAT|O_APPEND|O_WRONLY,0644);
    write(fd,"exiting: SIGINT",20);
    close(fd);
    exit(0);
  }
  else if(signo == SIGUSR1){
    printf("Parent's PID: %d \n",getppid());
  }
}

int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  while(1){
    printf("PID: %d\n",getpid());
    sleep(1);
  }
}

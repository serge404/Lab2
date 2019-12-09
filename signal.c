/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

char* turing = "Turing was right!\n";

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGINT,sigint_handler); // Register handler to handle SIGINT.
  signal(SIGALRM,handler); // Register handler to handle SIGALRM.
  while(1){
    alarm(1); // Schedule a SIGALRM for 1 second.
    sleep(1);
    printf("Turing was right!\n");
  }
	return 0; //never reached
}
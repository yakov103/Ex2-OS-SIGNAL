#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
int i = 1 ; 
int val = 10; 
void handle_sigint(int sig)
{
	if ( i == 1){
    printf("BOOM SIGNAL 2  %d\n", sig);
	i=0;
	}
}
void handler(int sig)
{
    val += 5;
}
pid_t pid;
int counter = 0;
void handler1(int sig)
{
    counter++;
    printf("Signal 3  SIGUSR  going to counter = %d\n", counter);
    /* Flushes the printed string to stdout */
    fflush(stdout);
    kill(pid, SIGUSR1);
}
void handler2(int sig)
{
    counter += 3;
    printf("Signal 4  SIGUSR OF SUN   going to counter =%d\n", counter);
    exit(0);
}
  

// send part of ex with 2 more signals . 
void second_part_signals (){
pid_t p;
    int status;
    signal(SIGUSR1, handler1);
    if ((pid = fork()) == 0)
    {
        signal(SIGUSR1, handler2);
        kill(getppid(), SIGUSR1);
        while(1) ;
    }
    if ((p = wait(&status)) > 0)
    {
        counter += 4;
        printf("counter = %d\n", counter);
		printf(" ok , now try to quit with CONTROL C one more time !!!!! \n"); 
		signal(SIGQUIT,handle_sigint);
    	while (i){
		} 
		
		printf("ok that was signal 5 so bye bye !" );
		exit(0); 
		    }




}


// here the process is start with 2 signals . 
int main (){

		
	int pid = fork(); 
	if (pid == -1){ 
		return 1; 
	}
	if (pid == 0 ){ 
		while (1)
		{
		printf("just waiting for Signnal 1  \n"); 
		usleep(50000);
		}
	
	}
	else {
		sleep(1);
		int pros = kill(pid , SIGKILL);
		printf("Boom!! signal 1 is done with SIGKILL \n"); 
		printf(" now try to stop us with  CONTROL+C \n");
		if (pros == 0 ){ 
  		signal(SIGINT, handle_sigint);
    	while (i){
		} 
		i= 2; 

 	   waitpid(pid, NULL, 0);
		second_part_signals();

		}
		wait (NULL);
			}

}

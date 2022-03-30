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
		pid_t pidpid;
		signal(SIGCHLD, handler);
    	if ((pidpid = fork()) == 0)
    	{
        val -= 3;
        exit(0);
   	 }    printf("val = %d\n", val);

    waitpid(pid, NULL, 0);


		}
		wait (NULL);
			}

}
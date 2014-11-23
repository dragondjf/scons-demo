#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void read_childproc(int sig)
{
	int status;
	pid_t id = waitpid(-1, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		printf("Remove proc id %d\n", id);
		printf("Child send: %d \n", WIFEXITED(status));
	}
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	
	struct sigaction act;
	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGCHLD, &act, 0);

	pid = fork();
	if (pid == 0)
	{
		puts("Hi, I'm child process 1 !");
		sleep(2);
		return 12;
	}
	else
	{
		printf("child proc id is: %d\n", pid);
		pid = fork();
		if (pid == 0)
		{
			puts("Hi, I'm child process 2!");
			sleep(2);
			return 24;
		}
		else
		{
			int i=0;
			printf("Child proc id is %d\n", pid);
			for (i = 0; i < 5; ++i)
			{
				printf("waiting...... %d\n", i);
				sleep(5);
			}
		}
	}
	return 0;
}
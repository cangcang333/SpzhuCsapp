#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	/* Child sleeps until SIGKILL signal received, then dies */
	if ((pid = fork()) == 0)
	{
		printf("In child\n");
		pause();	/* Wait for a signal to arrive */
		printf("control should never reach here!\n");
		exit(0);
	}

	printf("In parent\n");
	/* Parent sends a SIGKILL signal to a child */
//	kill(pid, SIGKILL);
	exit(0);
}

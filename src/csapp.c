
#include "csapp.h"

void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

pid_t Fork(void)
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		unix_error("Fork error");
	}
	return pid;
}

void Kill(pid_t pid, int signum)
{
	int rc;

	if ((rc = kill(pid, signum)) < 0)
	{
		unix_error("Kill error");
	}
}

void Pause()
{
	(void)pause();
	return;
}

unsigned int Alarm(unsigned int seconds)
{
	return alarm(seconds);
}


/************************************
 * Wrappers for Unix signal functions
 ************************************/
handler_t *Signal(int signum, handler_t *handler)
{
	struct sigaction action, old_action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);  /* Block sigs of type being handled */
	action.sa_flags = SA_RESTART;  /* Restart syscalls if possible */

	if (sigaction(signum, &action, &old_action) < 0)
	{
		unix_error("Signal error");
	}

	return(old_action.sa_handler);
}

void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
	if (sigprocmask(how, set, oldset) < 0)
	{
		unix_error("Sigprocmask error");
	}
	return;
}


void Sigemptyset(sigset_t *set)
{
	if (sigemptyset(set) < 0)
	{
		unix_error("Sigemptyset error");
	}
	return;
}

void Sigfillset(sigset_t *set)
{
	if (sigfillset(set) < 0)
	{
		unix_error("Sigfillset error");
	}
	return;
}

void Sigaddset(sigset_t *set, int signum)
{
	if (sigaddset(set, signum) < 0)
	{
		unix_error("Sigaddset error");
	}
	return;
}


void Sigdelset(sigset_t *set, int signum)
{
	if (sigdelset(set, signum) < 0)
	{
		unix_error("Sigdelset error");
	}
	return;
}

int Sigismember(const sigset_t *set, int signum)
{
	int rc;
	if ((rc = sigismember(set, signum)) < 0)
	{
		unix_error("Sigismember error");
	}
	return rc;
}

int Sigsuspend(const sigset_t *set)
{
	int rc = sigsuspend(set);  /* always return -1 */
	if (errno != EINTR)
	{
		unix_error("Sigsuspend error");
	}
	return rc;
}


unsigned int Sleep(unsigned int secs)
{
	unsigned int rc;

	if ((rc = sleep(secs)) < 0)
	{
		unix_error("sleep error");
	}
	return rc;
}


































#ifndef _CSAPP_H
#define _CSAPP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>

/* External variables */
extern char **environ;  /* defined by libc */

/* Misc constants */
#define MAXLINE  8192  /* Max text line length */
#define MAXBUF   8192  /* Max I/O buffer size */
#define LISTENQ  1024  /* Second argument to listen() */

void unix_error(char *msg);
void app_error(char *msg);

pid_t Fork(void);
void Execve(const char *filename, char *const argv[], char *const envp[]);
void Kill(pid_t pid, int signum);
void Pause();

unsigned int Alarm(unsigned int seconds);

typedef void handler_t(int);
handler_t *Signal(int signum, handler_t *handler);
void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
void Sigemptyset(sigset_t *set);
void Sigfillset(sigset_t *set);
void Sigaddset(sigset_t *set, int signum);
void Sigdelset(sigset_t *set, int signum);
int Sigismember(const sigset_t *set, int signum);
int Sigsuspend(const sigset_t *set);

unsigned int Sleep(unsigned int secs);

char *Fgets(char *ptr, int n, FILE *stream);

#endif

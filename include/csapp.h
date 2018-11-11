
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

void unix_error(char *msg);
pid_t Fork(void);

#endif

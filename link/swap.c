/*************************************************************************
	> File Name: swap.c
	> Author: 
	> Mail: 
	> Created Time: Sat Oct 27 13:23:01 2018
 ************************************************************************/

#include <stdio.h>

extern int buf[];

int *bufp0 = &buf[0];
int *bufp1;

void swap()
{
    int temp;

    bufp1 = &buf[1];
    temp = *bufp0;
    *bufp0 = *bufp1;
    *bufp1 = temp;
}

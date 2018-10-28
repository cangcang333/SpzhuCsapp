/*************************************************************************
	> File Name: addvec.c
	> Author: 
	> Mail: 
	> Created Time: Sat Oct 27 21:04:47 2018
 ************************************************************************/

#include <stdio.h>

void addvec(int *x, int *y, int *z, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        z[i] = x[i] + y[i];
    }
}

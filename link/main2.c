/*************************************************************************
	> File Name: main2.c
	> Author: 
	> Mail: 
	> Created Time: Sat Oct 27 21:25:16 2018
 ************************************************************************/

#include <stdio.h>
#include "vector.h"

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main(int argc, char *argv[])
{
    addvec(x, y, z, 2);
    printf("z = [%d %d]\n", z[0], z[1]);

    return 0;
}

/* mountain.c - Generate the memory mountain */

#include <stdlib.h>
#include <stdio.h>
#include "fcyc2.h"  /* measurement routines */
#include "clock.h"  /* routines to access the cycle counter */

#define MINBYTES (1 << 14)  /* First working set size */
#define MAXBYTES (1 << 27)  /* Last working set size */
#define MAXSTRIDE 15        /* Stride x8 bytes */
#define MAXELEMS MAXBYTES/sizeof(long)

/* $begin mountainfuns */
long data[MAXELEMS];  /* The global array we'll be traversing */
/* $end mountainfuns */

void init_data(long *data, int n);
int test(int elems, int stride);
double run(int size, int stride, double Mhz);

/* $begin mountainmain */
int main()
{
	int size;    /* Working set size (in bytes) */
	int stride;  /* Stride (in array elements) */
	double Mhz;  /* Clock frequency */

	init_data(data, MAXELEMS);  /* Initialize each element in data */
}


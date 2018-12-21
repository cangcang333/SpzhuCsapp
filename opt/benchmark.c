#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cpe.h"
#include "combine.h"

#define SHORT 0
#if SHORT
#define ASIZE 31
#else
#define ASIZE 973
#endif

/* Keep track of a number of different combining programs */
#define MAX_BENCHMARKS 100

static struct
{
	conbiner cfunct;
	combiner checkfunct;
	char *description;
	double cpe;
} benchmarks[MAX_BENCHMARKS];





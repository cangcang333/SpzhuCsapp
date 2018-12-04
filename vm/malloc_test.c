#include "csapp.h"

int main()
{
	int *array;
	int i;
	int n;

	scanf("%d", &n);
	array = (int *)Malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	exit(0);
}

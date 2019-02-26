#include <stdio.h>
#include <string.h>

void func1();

int main()
{
	printf("test for gprof\n");
	int i = 23;

	func1();

	printf("++i = %d\n", ++i);

	return 0;
}

void func1()
{
	int i = 0;
	int n = 100;
	int sum = 0;
	char *s = "abcde";

	for (i = 0; i < 100; i++)
	{
		strlen(s);
		sum += i * i;
	}
}

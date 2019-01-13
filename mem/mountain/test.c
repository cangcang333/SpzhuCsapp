#include <stdio.h>
#include <string.h>

#define MAXBUF 512

int main()
{
	static char buf[MAXBUF];
	FILE *fp = fopen("/proc/cpuinfo", "r");
	double cpu_mhz = 0.0;
	
	if (!fp)
	{
		fprintf(stderr, "Can't open /proc/cpuinfo to get clock information\n");
		return -1;
	}
	while (fgets(buf, MAXBUF, fp))
	{
		if (strstr(buf, "cpu MHz"))
		{
			sscanf(buf, "cpu MHz\t: %lf", &cpu_mhz);
			break;
		}	
	}
	fclose(fp);
	printf("Processor Clock Rate = %f MHz\n", cpu_mhz);


	sscanf("123456", "%s", buf);
	printf("%s\n", buf);
	sscanf("123456", "%4s", buf);
	printf("%s\n", buf);
	sscanf("123456abcdefBCDEF", "%[1-9a-z]", buf);
	printf("%s\n", buf);
	sscanf("8888123456abcdefBCDEF", "%[^A-Z]", buf);
	printf("%s\n", buf);
	sscanf("iios/12dDDD@122", "%*[^/]/%[^@]", buf);
	printf("%s\n", buf);
	sscanf("hello, world", "%*s%s", buf);
	printf("%s\n", buf);
	
	int a, b, c;
	sscanf("2006:03:18", "%d:%d:%d", &a, &b, &c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	
	char sztime1[16] = "";
	char sztime2[16] = "";
//	sscanf("2006:03:18 - 2006:04:18", "%s - %s", sztime1, sztime2);
	sscanf("2006:03:18 - 2006:04:18", "%[0-9,:] - %[0-9,:]", sztime1, sztime2);
	printf("sztime1 = %s\n", sztime1);
	printf("sztime2 = %s\n", sztime2);
		

	return 0;
}

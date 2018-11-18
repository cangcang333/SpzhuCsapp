#include "csapp.h"

void handler(int ret)
{
	return;
}

unsigned int snooze(unsigned int secs)
{
	int ret;
	ret = sleep(secs);
	printf("\nSlept for %d of %d secs.\n", (secs - ret), secs);

	return ret;
}

int main()
{
	static int secs = 10;
	if (Signal(SIGINT, handler) == SIG_ERR)
	{
		unix_error("Signal error");
	}
	snooze(secs);


	return 0;
}

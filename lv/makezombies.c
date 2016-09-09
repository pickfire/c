#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		if (fork() == 0)
			exit(0); /* Child */
	sleep(1000);
}

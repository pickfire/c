/* rewrite the temperature conversation program of Section 1.2 to use the function for conversation */
#include <stdio.h>

#define LOWER   0
#define UPPER 300
#define STEP   20

float fahr2celsius(int fahr)
{
	return 5 * (fahr-32) / 9;
}

int main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d°F %6.1f°C\n", fahr, fahr2celsius(fahr));

	return 0;
}

/* Write a program to print the corresponding Celsius to Fahrenheit table */
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;     /* lower limit of temperature table */
	upper = 200;   /* upper limit */
	step = 10;     /* step size */

	printf(" °C     °F\n");
	celsius = lower;
	while(celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}

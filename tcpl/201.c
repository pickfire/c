/* Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types. */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Standard headers\n");
	printf("signed char\t%d:%d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char\t0:%d\n", UCHAR_MAX);
	printf("signed short\t%d:%d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short\t0:%d\n", USHRT_MAX);
	printf("signed int\t%d:%d\n", INT_MIN, INT_MAX);
	printf("unsigned int\t0:%u\n", UINT_MAX);
	printf("signed long\t%ld:%ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long\t0:%lu\n", ULONG_MAX);

	char d = 1;
	for (d = 1; (d << 1) > 0; d |= d << 1)
		printf("%d\n", d);
	/* do { d |= d << 1; } while ((d << 1) + 1 > 0); */
	printf("%d\n", d);
	return 0;
}

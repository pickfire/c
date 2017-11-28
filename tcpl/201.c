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

	printf("Direct computation\n");
	char d;
	for (d = 1; (char) (d << 1) > 0; d |= d << 1);
	printf("signed char\t%d:%d\n", ~d, d);

	unsigned char e;
	for (e = 1; (unsigned char) (e << 1 | 1) != e; e |= e << 1);
	printf("unsigned char\t0:%d\n", e);

	return 0;
}

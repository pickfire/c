/* write a program to copy its input to its output, replacing each string of
 * one or more blanks by a single blank */
#include <stdio.h>

int main()
{
	int b, c;

	while ((c = getchar()) != EOF) {
		if (feof(stdin)) break;
		if (c != ' ' || b == 0)
			putchar(c);
		/*
		if (c == ' ')
			b = 1;
		else
			b = 0;
			*/
		b = (c == ' ') ? 1 : 0;
	}

	return 0;
}

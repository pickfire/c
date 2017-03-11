/* write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every n columns. */
#include <stdio.h>
#define  TS 8	/* tab stop */

int main()
{
	int c, i, n;	/* c: char, i: n. blanks, p: pos */

	for (n = 0; (c = getchar()) != EOF; n++) {
		if (c == '\n')
			n = 0;
		if (c != '\t')
			putchar(c);
		else
			for (i = TS - --n % TS; i > 0; i--, n++)
				putchar(' ');
	}
	return 0;
}

/* Write a program that replaces strings of blanks by the minimum number of
 * tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. */
#include <stdio.h>
#define  TS 8	/* tab stop */

int main()
{
	int c, i, p, b;	/* c: char, i: n. blanks, p: pos, b: block */

	for (p = 0, i = 0; (c = getchar()) != EOF;) {
		if (c == '\n')
			p = 0;
		b = (c == '\t') ? TS - (p-1) % TS : 1; /* block/char */
		if (c != '\t' && c != ' ') {
			for (b = TS - p % TS + 1; i >= b; i -= b, b = TS)
				putchar('\t');
			for (; i > 0; i--)
				putchar(' ');
			putchar(c);
		} else
			i += b;
		p += b;
	}
	return 0;
}

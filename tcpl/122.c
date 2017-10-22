/* Write a program "to" fold long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are blanks or tabs before the specified column. */
#include <stdio.h>
#define TS   8	/* tab stop */
#define LB  80	/* line break */

int isblank(int c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

int main()
{
	int i, w, xx, x; /* i: count, w: width, x: x pos, XX: old X */
	char s[1000];

	for (w = xx = x = 0; (s[x] = getchar()) != EOF; x++) {
		w += (s[x] == '\t') ? TS - (x-1) % TS : 1;
		if (!isblank(s[x-1]) && isblank(s[x])) {
			if (w >= LB) {
				for (i = x; isblank(s[xx]); xx++);
				for (s[xx-1] = '\n', xx = x - xx + 1, w = x = 0; xx > 0;)
					s[x++] = s[i - xx--], w++;
			}
			while (xx < x)
				putchar(s[xx++]);
			if (s[xx] == '\n')
				putchar('\n'), w = xx = x = -1;
		}
	}

	return 0;
}

/* Write a program "to" fold long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are blanks or tabs before the specified column. */
#include <stdio.h>
#define TS   8	/* tab stop */
#define LB  80	/* line break */

int isblank(int c)
{
	return c == ' ' || c == '\t';
}

int main()
{
	int i, ww, w, xx, x; /* i: count, ww: width, xx: x pos, XX: old X */
	char s[1000];

	for (ww = w = xx = x = 0; (s[x] = getchar()) != EOF; x++) {
		w += (s[x] == '\t') ? TS - (x-1) % TS : 1;
		if (!isblank(s[x-1]) && isblank(s[x])) {
			if (w >= LB) { /* TODO: can be refractored */
				for (s[xx++] = '\n', i = 0; i < xx; i++)
					putchar(s[i]);
				for (; isblank(s[xx]); xx++);
				for (i = x, w = x = 0; xx + x < i; x++, w++)
					s[x] = s[xx+x];
			}
			xx = x, ww = w;
		} else if (s[x] == '\n')
			for (i = x, xx = w = ww = 0; x >= 0; x--)
				putchar(s[i-x]);
	}

	return 0;
}

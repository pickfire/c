/* Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not
 * nest. */
#include <stdio.h>

int main()
{
	int c, q, s; /* c: char, q: quote, s: skip comment */

	for (q = s = 0; (c = getchar()) != EOF; )
		if (s)
			s ^= (c == '*' && getchar() == '/');
		else if (c == '\\' || c == '\'')
			putchar(c), putchar(getchar());
		else if (q || c == '"')
			q ^= putchar(c) == '"';
		else if (c != '/')
			putchar(c);
		else
			if ((c = getchar()) == '/')
				for (putchar('\n'); getchar() != '\n'; );
			else if (c == '*')
				s = 1;
			else
				putchar('/'), putchar(c);

	return 0;
}

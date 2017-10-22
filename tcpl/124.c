/* Write a program to check a C program fro rudimentary syntax errors like
 * unbalanced parenthesis, brakets and braces. Don't forget about quotes, both
 * single and double, escape sequences and comments. */
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <stdio.h>

int main()
{
	/* c: char, cc: previous char, i: pos, q: quote, r: comment */
	int c, i, cc, q, r;
	char s[1000];

	for (q = r = i = 0; (c = getchar()) != EOF; cc = c)
		if (r)
			r ^= (cc == '*' && c == '/');
		else if (c == '\\')
			cc = getchar(), c = '\0';
		else if (q)
			q ^= (c == s[i-1] && cc != '\\' && i--);
		else
			switch (c) {
				case '*':
					r = (cc == '/' && c == '*');
					break;
				case ')':
					if (c == ')' && s[--i] == '(')
						break;
				case ']':
					if (c == ']' && s[--i] == '[')
						break;
				case '}':
					if (c == '}' && s[--i] == '{')
						break;
					i++;  /* fix decrement if unmatch */
				case '\'':
				case '"':
					q = (c == '"' || c == '\'');
				case '(':
				case '[':
				case '{':
					s[i++] = c;
					break;
			}
	s[i+1] = '\0';
	if (i)
		printf("Error %s\n", s);
	else
		printf("No error\n");
	return 0;
}

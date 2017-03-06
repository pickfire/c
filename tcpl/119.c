/* Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time. */
#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

char *reverse(char s[])
{
	int i, len;
	for (len = 0; s[len] != '\n'; len++);

	char rev[len];
	for (i = 0; i < len; i++)
		rev[i] = s[len-1-i];

	for (i = 0; i < len; i++)
		s[i] = rev[i];

	return s;
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
		printf("%s", reverse(line));
	return 0;
}

/* Write a program to remove trailing blanks and tabs from each line of input
 * and to delete entirely blank lines */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; i++)
		s[i] = c;
	while (s[i-1] == ' ' || s[i-1] == '\t')
		i--;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > 1)
			printf("%s", line);
	return 0;
}

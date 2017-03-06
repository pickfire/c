/* write a program to print the value of EOF */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

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

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 1)
		if (len > 80)
			printf("%s", line);

	return 0;
}

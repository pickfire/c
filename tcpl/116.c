/* revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines and as mush as possible of the text */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

int main()
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%d %s\n", max, longest);

	return 0;
}

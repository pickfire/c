/* write a program to print a horizontal histogram of the lengths of words in
 * its output */
#include <stdio.h>

int main()
{
	int c, i, l, len[12];

	for (i = 0; i < 12; i++) /* 1 - 12 */
		len[i] = 0;
	i = 0;

	while ((c = getchar()) != EOF)
		if ('a' <= c && c <= 'z')
			i += 1;
		else if (i != 0) {
			len[i-1]++;
			i = 0;
		}

	for (i = 0; i < 12; ++i) {
		printf("%2d ", i+1);
		for (l = 0; l < len[i]; l++)
			putchar('-');
		printf("\n");
	}

	return 0;
}

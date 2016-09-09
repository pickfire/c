/* write a program to print a vertical histogram of the frequencies of
 * different characters in its input */
#include <stdio.h>

#define HEIGHT 20  /* not including scale */

int main()
{
	int c, x, y, f[26], max; /* c: char, x/y: count, f: freq */

	for (x = 0; x < 26; x++) /* fill f[x] with 0 */
		f[x] = 0;

	while ((c = getchar()) != EOF)
		if ('a' <= c && c <= 'z') /* don't care about capitals */
			if ((++f[c-'a']) > max)
				max = f[c-'a'];

	putchar('\n');
	for (y = HEIGHT; y > 0; y--) { /* counting forwards stole my time */
		printf("%3d |", (y - 1) * max / HEIGHT + 1);
		for (x = 0; x < 26; x++)
			if (f[x] > (y - 1) * max / HEIGHT)
				printf(" x");
			else
				printf("  ");
		printf("\n");
	}
	printf(" ---+----------------------------------------------------->\n");
	printf("  0 | a b c d e f g h i j k l m n o p q r s t u v w x y z\n\n");

	return 0;
}

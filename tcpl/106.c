/* verify that the expression `getchar() != EOF` is 0 or 1 */
#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF)
		if (!feof(stdin))
			printf("%c: %d\n", c, c);

	return 0;
}

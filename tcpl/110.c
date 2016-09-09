/* write a program to copy its input to its output, replacing each lab by \t,
 * each backspace by \b and each backslash by \\ */
#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF && !feof(stdin)) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b') /* TODO: '\b' doesn't work */
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}

	return 0;
}

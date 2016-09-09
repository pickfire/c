/* write a program to count blanks, tabs and newlines */
#include <stdio.h>

int main()
{
	int c, b, t, nl;

	while ((c = getchar()) != EOF) {
		if (!feof(stdin)) {
			if (c == ' ')
				++b;
			if (c == '\t')
				++t;
			if (c == '\n')
				++nl;
		}
	}

	printf("blanks: %d, tabs: %d, newlines: %d\n", b, t, nl);

	return 0;
}

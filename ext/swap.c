/* XOR swap */
#include <stdio.h>

int main()
{
	int x, y;

	printf("X: ");
	scanf("%d", &x);
	printf("Y: ");
	scanf("%d", &y);

	x ^= y ^= x ^= y; /* xor swap */
	printf("X: %d, Y: %d\n", x, y);

	return 0;
}

/* http://adventofcode.com/day/15 - see matrix.c for prototype*/
#include <stdio.h>

#define ABCD(x) ((x) == 0 ? a : (x) == 1 ? b : (x) == 2 ? c : d)
#define LEN(a)  (sizeof(a) / sizeof(a)[0])
#define LOOP_MAX(n)	int a = 0, b = 0, c = 0, d = 0;\
			for (a = 0; a <= (n); a++)\
				for (b = 0; b <= (n); b++)\
					for (c = 0; c <= (n); c++)\
						for (d = 0; d <= (n); d++)\
							if (a+b+c+d == (n))

static int t[4][5] = {
	{ 5, -1, 0, 0, 5 },
	{ -1, 3, 0, 0, 1 },
	{ 0, -1, 4, 0, 6 },
	{ -1, 0, 0, 2, 8 },
};

int main() {
	int max = 0;

	LOOP_MAX(100) {
		int w, x, y, z, total = 1;

		for (w = 0, x = 0; x < LEN(t); x++) /* 500 cal */
			w += t[x][4] * ABCD(x);
		if (w != 500) /* Don't run the for loop, ... */
			break;
		for (y = 0; y < LEN(t[0])-1; y++) {
			for (x = 0, z = 0; x < LEN(t); x++) {
				z += t[x][y] * ABCD(x);
			}
			total *= (z > 0) ? z : 0;
		}
		max = total > max ? total : max;
	}
	printf("%d\n", max);
	return 0;
}

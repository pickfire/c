/*                  Matrix/t
 *                  --------
 *          y                               z
 *          ^                               ^
 *  x <- [ -1  2 ]                       [   68 ]
 *       [ -2  3 ]   [ 44 ] -> a   ---   [   80 ]
 *       [  6 -2 ]   [ 56 ] -> b   ---   [  152 ]
 *       [  3 -1 ]                       [ * 76 ]
 *                                       --------
 *                              total <- 62842880
 *                                       --------
 */

#include <stdio.h>

#define LEN(a)  (sizeof(a) / sizeof(a)[0])
#define LOOP_MAX(n)	int a = 0, b = 0;\
			for (a = 0; a <= (n); a++)\
				for (b = 0; b <= (n); b++)\
					if (a+b == (n))


static int t[2][4] = {
	{ -1,-2, 6, 3 },
	{  2, 3,-2,-1 },
};

int main() {
	int max = 0;

	LOOP_MAX(100) {
		int x, y, z, total = 1;

		for (y = 0; y < LEN(t[0]); y++) {
			for (x = 0, z = 0; x < LEN(t); x++)
				z += t[x][y] * (x == 0 ? a : b);
			total *= (z > 0) ? z : 0;
		}
		max = total > max ? total : max;
	}
	printf("%d\n", max);
	return 0;
}

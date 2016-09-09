#include <stdio.h>

#define LEN(a)  (sizeof(a) / sizeof(a)[0])

typedef struct {
	const char *name;
	const int s;    /* speed */
	const int p1;   /* flying */
	const int p2;   /* resting */
	unsigned int d; /* distance */
	unsigned int points;
} Reindeer;

static Reindeer reindeer[] = {
	{ "Vixen",    8,  8,  53, 0, 0, },
	{ "Blitzen", 13,  4,  49, 0, 0, },
	{ "Rudolph", 20,  7, 132, 0, 0, },
	{ "Cupid",   12,  4,  43, 0, 0, },
	{ "Donner",   9,  5,  38, 0, 0, },
	{ "Dasher",  10,  4,  37, 0, 0, },
	{ "Comet",    3, 37,  76, 0, 0, },
	{ "Prancer",  9, 12,  97, 0, 0, },
	{ "Dancer",  37,  1,  36, 0, 0, },
};

int main() {
	unsigned int t, i, lead = 0;

	for (t = 1; t <= 2503; t++) {
		/* Reindeer travels for a second */
		for (i = 0; LEN(reindeer) > i; i++) {
			/* 0 counts too so it is required for time to -1 */
			if ((t-1) % (reindeer[i].p1+reindeer[i].p2) < reindeer[i].p1)
				reindeer[i].d += reindeer[i].s;
			if (reindeer[i].d > lead)
				lead = reindeer[i].d;
		}
		/* Add a point to the furthest reindeer */
		for (i = 0; LEN(reindeer) > i; i++)
			if (reindeer[i].d >= lead)
				reindeer[i].points++;
	}
	/* Measure results */
	for (i = 0; LEN(reindeer) > i; i++)
		printf("Reindeer %s travelled a distance of %d with points %d\n",
			reindeer[i].name, reindeer[i].d, reindeer[i].points);
	return 0;
}


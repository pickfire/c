/* Imports */
#include <stdio.h>
#include <string.h>

/* Define the structe Person */
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

/* Print a person */
void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}

/* Main program */
int main(int argc, char *argv[])
{
	/* make two people structures */
	struct Person joe;
	struct Person frank;

	joe.name   = "Joe Alex";
	joe.age    = 32;
	joe.height = 64;
	joe.weight = 140;

	frank.name   = "Joe Alex";
	frank.age    = 32;
	frank.height = 64;
	frank.weight = 140;

	/* print them out and where they are in memory */
	Person_print(joe);
	Person_print(frank);

	/* make everyone age 20 years and print them again */
	joe.age      += 20;
	joe.height   -= 2;
	joe.weight   += 40;
	Person_print(joe);

	frank.age    += 20;
	frank.weight += 20;
	Person_print(frank);

	return 0;
}

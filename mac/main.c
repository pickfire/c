/* http://blog.felixangell.com/blog/virtual-machine-in-c */
#include <stdio.h>
#include <stdbool.h>

typedef enum {
	PSH,
	ADD,
	POP,
	SET,
	MOV,
	HLT
} InstructionSet;

typedef enum {
	A, B, C, D, E, F,
	NUM_OF_REGISTERS /* tips: easily add more registers */
} Registers;


static const int program[] = {
	PSH, 5,
	PSH, 6,
	ADD,
	POP,
	SET, A, 10,
	MOV, B, A,
	HLT
};

static bool running = true;
static int ip = 0, sp = -1, stack[256]; /* ip: instruction pointer, sp: stack pointer */
static int registers[NUM_OF_REGISTERS];

void eval(int instr)
{
	switch (instr) {
		case HLT: { /* What is this skope thing for? */
			running = false;
			break;
		}
		case PSH: {
			stack[++sp] = program[++ip];
			printf("pushed %d\n", stack[sp]);
			break;
		}
		case POP: {
			int val_popped = stack[sp--];
			printf("popped %d\n", val_popped);
			break;
		}
		case ADD: {
			int a = stack[sp--];
			int b = stack[sp--];
			stack[++sp] = a + b;
			printf("added  %d, %d\n", a, b);
			break;
		}
		case SET: {
			Registers reg = program[++ip];
			registers[reg] = program[++ip];
			printf("set r%c %d\n", 'A'+reg, program[ip]);
			break;
	  	}
		case MOV: {
			Registers reg = program[++ip];
			registers[reg] = registers[program[++ip]];
			printf("moved  r%c -> r%c\n", 'A'+program[ip], 'A'+reg);
			break;
		}
	}
}

int fetch()
{
	return program[ip];
}

int main()
{
	while (running) {
		eval(fetch());
		ip++;
	}
}

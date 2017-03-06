CFLAGS += -Wall -g -O0 -ansi
CC = gcc

SRC = $(wildcard *.c */*.c */*/*.c)

all: $(SRC:.c=)

clean:
	@find . -type f -a \( -name '*.o' -o -perm /111 \) -delete

%: %.c
	$(CC) $< -o $@ $(CFLAGS)

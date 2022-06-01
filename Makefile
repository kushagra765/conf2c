CC = gcc
CFLAGS = -o
CFILES = conf2c.c
EXEC = conf2c

.PHONY: all

all:
	$(CC) $(CFLAGS) $(EXEC) $(CFILES)

clean:
	rm $(EXEC)

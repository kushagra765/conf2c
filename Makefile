CC = gcc
CFLAGS = -o
CFILES = conf2c.c
EXEC = conf2c

.PHONY: all

all:
	$(CC) $(CFLAGS) $(EXEC) $(CFILES)

install:
	sudo cp $(EXEC) /usr/bin/$(EXEC)

clean:
	rm $(EXEC)

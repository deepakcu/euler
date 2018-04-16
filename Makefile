CC=gcc

CFLAGS=-Werror -std=c99

all: $(EXECUTABLE)

SRC=$(wildcard *.c)
EXECUTABLE = $(patsubst %.c, bin/%.exe, $(SRC))

all: $(EXECUTABLE)

#echo $(EXECUTABLE)

bin/%.exe: %.o
	$(CC) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(EXECUTABLE)
	rm -rf bin/*

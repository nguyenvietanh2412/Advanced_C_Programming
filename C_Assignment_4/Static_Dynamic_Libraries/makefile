CC = gcc
CFLAGS = -I./inc -fPIC
LDFLAGS = -shared

all: main

main: main.o libgemtek_mathlib.so
	$(CC) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

libgemtek_mathlib.so: src/gemtek_mathlib.o
	$(CC) $(LDFLAGS) -o $@ $<

src/gemtek_mathlib.o: src/gemtek_mathlib.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main *.o src/*.o *.so

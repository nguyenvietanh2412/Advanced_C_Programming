CC = gcc
CFLAGS = -I./morse_code/inc -I./file_handling/inc
OBJ = main.o morse_code/src/morse_code.o file_handling/src/file_handling.o

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(OBJ) main

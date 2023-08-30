CC = gcc
CFLAGS = -I./caesar_cipher/inc -I./file_handling/inc
OBJ = main.o caesar_cipher/src/caesar_cipher.o file_handling/src/file_handling.o

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(OBJ) main

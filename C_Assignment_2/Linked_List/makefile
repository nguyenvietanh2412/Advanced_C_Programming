CC = gcc

CFLAGS = -I./inc

SOURCES = main.c ./src/*.c

TARGET = run



$(TARGET): $(SOURCES)

	$(CC) -g -o $(TARGET) $(SOURCES) $(CFLAGS)



clean:

	rm -rf $(TARGET)
CC = gcc
HEADERS = -I./inc
SOURCES = main.c ./src/*.c
TARGET = run

$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(HEADERS) $(CFLAGS)

clean:
	rm -rf $(TARGET)

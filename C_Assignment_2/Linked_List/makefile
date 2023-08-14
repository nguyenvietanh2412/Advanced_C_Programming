CC = gcc

CFLAGS = -I./inc

SOURCES = main.c ./src/*.c

TARGET = run



$(TARGET): $(SOURCES)

	$(CC) -o $(TARGET) $(SOURCES) $(CFLAGS)



clean:

	del /f /q $(TARGET)
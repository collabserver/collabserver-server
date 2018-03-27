CC=gcc
FLAGS=-g -Wall
TARGET=test_CRDT


all: $(TARGET)

$(TARGET) : main.c
	$(CC) $(FLAGS) -I../include/ -o $@ $^


.PHONY: clean
clean:
	-rm -f $(TARGET)
run:
	./$(TARGET)

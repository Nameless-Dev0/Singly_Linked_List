CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g -fsanitize=address
LDFLAGS = -fsanitize=address

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
HEADER = $(wildcard include/*.h)

TARGET = build/sll

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: src/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf build/*

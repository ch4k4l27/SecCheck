CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/help.c src/permissions.c src/ports.c src/environment.c
OBJ = $(SRC:.c=.o)
TARGET = seccheck

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean


CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = ./main.c ./help.h ./permissions.h ./scan_open_ports.h ./check_environment.h
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


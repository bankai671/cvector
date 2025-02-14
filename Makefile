# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c11

# Source files
SRCS = main.c vector.c

# Header files
HDRS = vector.h

# Object files
OBJS = main.o vector.o

# Executable name
TARGET = main

# Default rule
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	rm $(OBJS)

# Rule to compile main.c
main.o: main.c $(HDRS)
	$(CC) $(CFLAGS) -c main.c

# Rule to compile vector.c
vector.o: vector.c $(HDRS)
	$(CC) $(CFLAGS) -c vector.c

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to prevent conflicts with files of the same name
.PHONY: all clean

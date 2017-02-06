# Compiler Version
CC=gcc

# Debugging flag -g
DEBUG=-g

# Target
TARGET=main

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o
	$(CC) main.o -o $(TARGET)

main.o: main.c 
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o *~ $(TARGET)

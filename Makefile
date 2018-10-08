c = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = array.o read_file.o
TARGET = hw6_josephschwalb

all: $(TARGET)

$(TARGET): $(OBJFILES)
	    $(c) hw6_josephschwalb.c -o $(TARGET) $(OBJFILES)

clean:
	    rm -f $(TARGET) $(OBJFILES)

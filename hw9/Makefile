c = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = array.o read_file.o
TARGET = hw9_josephschwalb

all: $(TARGET)

$(TARGET): $(OBJFILES)
	    $(c) hw9_josephschwalb.c -o $(TARGET) $(OBJFILES)

clean:
	    rm -f $(TARGET) $(OBJFILES)

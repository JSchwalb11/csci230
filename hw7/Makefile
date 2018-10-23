c = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = array.o read_file.o
TARGET = hw7_8_josephschwalb

all: $(TARGET)

$(TARGET): $(OBJFILES)
	    $(c) hw7_8_josephschwalb.c -o $(TARGET) $(OBJFILES)

clean:
	    rm -f $(TARGET) $(OBJFILES)

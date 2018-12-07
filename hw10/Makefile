c = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = hw10-A-josephschwalb.o hw10-B-josephschwalb.o hw10-C-josephschwalb.o read_file.o
TARGET = hw10-josephschwalb

all: hw10-josephschwalb

hw10-josephschwalb: hw10-josephschwalb.o hw10-lib-josephschwalb.so
	    $(c) -lm -o hw10-josephschwalb-4 hw10-josephschwalb.o -L. -ldl

hw10-josephschwalb.o: hw10-josephschwalb-4.c
	    $(c) -O -c -fPIC hw10-josephschwalb.c hw10-josephschwalb.h

hw10-A-josephschwalb.o: hw10-A-josephschwalb.c hw10-A-josephschwalb.h
	    $(c) -O -c -fPIC hw10-A-josephschwalb.c

hw10-B-josephschwalb.o: hw10-B-josephschwalb.c hw10-B-josephschwalb.h
	    $(c) -O -c -fPIC hw10-B-josephschwalb.c

hw10-C-josephschwalb.o: hw10-C-josephschwalb.c hw10-C-josephschwalb.h
	    $(c) -O -c -fPIC hw10-C-josephschwalb.c

read_file.o: read_file.c read_file.h
	    $(c) -O -c -fPIC read_file.c

hw10-lib-josephschwalb.so: hw10-A-josephschwalb.o hw10-B-josephschwalb.o hw10-C-josephschwalb.o read_file.o
			$(c) -fPIC -shared hw10-A-josephschwalb.o hw10-B-josephschwalb.o hw10-C-josephschwalb.o read_file.o -o hw10-lib-josephschwalb.so

clean:
	    rm -f hw10-josephschwalb-4 *.o *.so *.gch

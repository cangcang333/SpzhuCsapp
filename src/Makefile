CC = gcc
CFLAGS = -O1 -Wall
INC = ../include
LIB = ../lib

F64 = -m64

OBJ64 = csapp64.o

OBJS = $(OBJ64)

all: $(LIB)/libcsapp64.a

### 64 Bit Code
csapp64.o: $(INC)/csapp.h csapp.c
	$(CC) $(CFLAGS) -c -o csapp64.o csapp.c -I$(INC)

$(LIB)/libcsapp64.a: $(OBJ64)
	ar rcs $(LIB)/libcsapp64.a $(OBJ64)

clean:
	rm -f sparc_tick_driver *.o *~

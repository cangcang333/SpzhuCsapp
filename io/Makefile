CC = gcc
CSAPP_INC = ../include
CSAPP_SRC = ../src

CFLAGS = -g -Wall  -I $(CSAPP_INC) -I .
#CFLAGS = -g -Wall -Og -I $(CSAPP_INC) -I .

LDLIBS = -lpthread

PROGS = cpstdin \
		cpfile  \
		statcheck

all: $(CSAPP_SRC)/csapp.o $(PROGS)

$(PROGS): $(CSAPP_SRC)/csapp.o

$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

clean:
	rm -f $(PROGS) *.o *~


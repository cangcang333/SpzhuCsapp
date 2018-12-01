CC = gcc
CSAPP_INC = ../include
CSAPP_SRC = ../src
CFLAGS = -Wall -Og -I $(CSAPP_INC) -I .
LDLIBS = -lpthread

PROGS = waitpid1 \
		waitpid2 \
		waitprob1 \
		kill  \
		sigint1  \
		alarm  \
		snooze  \
		signal1 \
		signal2 \
		signal3 \
		signalprob0 \
		signal4  \
		procmask1 \
		shellex  \
		procmask2  \
		rand_test  \
		rfork  \
		setjmp  \
		restart

all: $(CSAPP_SRC)/csapp.o $(PROGS)

$(PROGS): $(CSAPP_SRC)/csapp.o

$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

clean:
	rm -f $(PROGS) *.o *~


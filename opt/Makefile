# Choose your word size
WSIZE = 64
OPTLEVEL = 1
# WSIZE = 32 
CC = gcc
CFLAGS = -pg
INC = ../include
MCFLAGS = -g -Wall -I. -I$(INC) -mavx2 -mfma

CFLAGS = $(MCFLAGS) -m$(WSIZE)
F386 = -march=i386
F686 = -march=i686
LIB = ../lib
LIBCSAPP = $(LIB)/libcsapp$(WSIZE).a -lrt
GETASM = ../getasmfun.pl
RUNPOS = 0.8
RUNCNT = 50
MULTIRUN = ./multirun.pl -n $(RUNCNT) -p $(RUNPOS)
BXTR = ./bxtr.pl
VXTR = ./vxtr.pl
TABULATE = ./tabulate.pl
#Choose your machine
# MACHINIE = p4
# MACHINE = athlon
# MACHINE = haswell
MACHINE=machine
RESULTS=results


PROGS = isbench \

all: $(PROGS)

bench: isbench fpb-01.64s fpb-02.64s

fragments.o: fragments.c
	$(CC) -c -DSUM -DLONG fragments.c

isbench: vec.h combine.h combine.c benchmark.c vec.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -O$(OPTLEVEL) -DSUM -DINT -o isbench benchmark.c combine.c vec.c $(LIBCSAPP)
	$(MULTIRUN) -c ./isbench > $(RESULTS)/isb-$(MACHINE)-O(OPTLEVEL)-$(WSIZE).txt
	$(BXTR) < $(RESULTS)/isb-$(MACHINE)-O$(OPTLEVEL)-$(WSIZE).txt > $(RESULTS).isb-$(MACHINE)-O$(OPTLEVEL)-$(WSIZE).tab
	$(VXTR) < $(RESULTS)/isb-$(MACHINE)-O$(OPTLEVEL)-$(WSIZE).txt > $(RESULTS).isb-$(MACHINE)-O$(OPTLEVEL)-$(WSIZE).vtab

clean:
	rm -f $(PROGS) *.o *~


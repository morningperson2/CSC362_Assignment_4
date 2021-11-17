# Macros ========================================

CC=gcc
CFLAGS=-c -g -Wall -Wextra -ansi -pedantic -O -Wconversion
OUTDIR=gnu/
ERASE=rm
OBJECTS=$(OUTDIR)main.o $(OUTDIR)work.o
EXE=main

# Targets ========================================

$(EXE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

$(OUTDIR)main.o : main.c work.c
	$(CC) $(CFLAGS) main.c -o $(OUTDIR)main.o
	
$(OUTDIR)work.o : work.c work.h
	$(CC) $(CFLAGS) work.c -o $(OUTDIR)work.o
	
clean :
	$(ERASE) $(EXE) $(OBJECTS)

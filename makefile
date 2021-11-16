# Macros ========================================

CC=gcc
CFLAGS=-c -g -Wall -Wextra -ansi -pedantic -O -Wconversion
OUTDIR=gnu/
ERASE=rm
OBJECTS=$(OUTDIR)main.o $(OUTDIR)sort.o
EXE=main

# Targets ========================================

$(EXE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

$(OUTDIR)main.o : main.c sort.c
	$(CC) $(CFLAGS) main.c -o $(OUTDIR)main.o
	
$(OUTDIR)sort.o : sort.c sort.h 
	$(CC) $(CFLAGS) sort.c -o $(OUTDIR)sort.o
	
clean :
	$(ERASE) $(EXE) $(OBJECTS)

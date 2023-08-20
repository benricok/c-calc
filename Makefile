CC = gcc
CFLAGS = -Wall -Wextra -pedantic -I include/
LIB = 
TARG = calc
BINRDIR = /usr/local/bin 
OBJ = $(wildcard src/*.o) $(wildcard include/*.c)# src/main.o

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

install: $(TARG)
	install $(TARG) $(BINDDIR)/$(TARG)

run: $(TARG)
	./$(TARG)

clean:
	rm -f $(OBJ) $(TARG)

uninstall:
	rm -f $(BINRDIR)/$(TARG) 

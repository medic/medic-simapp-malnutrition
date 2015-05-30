# Makefile

TARGETS := simple

CFLAGS += -I../..
LIBRARY_SRC := ../../polynomial.c ../../who-tables.c

all: $(TARGETS) run

simple: simple.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

run:
	@for target in $(TARGETS); do \
	  "./$$target" || exit 1; \
	done

clean:
	rm -rf *.dSYM
	rm -f $(TARGETS) *.o *~


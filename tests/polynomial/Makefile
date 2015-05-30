# Makefile

TARGETS := simple table

CFLAGS += -I../..
LIBRARY_SRC := ../../polynomial.c

all: $(TARGETS) run

simple: simple.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

table: table.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

run:
	@for target in $(TARGETS); do \
	  "./$$target" || exit 1; \
	done

clean:
	rm -f $(TARGETS) *.o *~


# Makefile

TARGETS := simple day-number subtract

CFLAGS += -I../..
LIBRARY_SRC := ../../datetime.c

all: $(TARGETS) run

simple: simple.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

day-number: day-number.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

subtract: subtract.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

run:
	@for target in $(TARGETS); do \
	  "./$$target" || exit 1; \
	done

clean:
	rm -f $(TARGETS) *.o *~


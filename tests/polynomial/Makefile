# Makefile

TARGETS := simple table table-fixed

CFLAGS += -I../..
LIBRARY_SRC := ../../polynomial.c

all: $(TARGETS) run

simple: simple.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $< \
      -DPOLYNOMIAL_FN_MAX_DEGREE=16

table: table.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $<

table-fixed: table-fixed.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $< \
	  -DPOLYNOMIAL_FIXED_FN_DEGREE=6 \
	  -DPOLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS=4

run:
	@for target in $(TARGETS); do \
	  "./$$target" || exit 1; \
	done

clean:
	rm -rf *.dSYM
	rm -f $(TARGETS) *.o *~


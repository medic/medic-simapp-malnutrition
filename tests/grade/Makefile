# Makefile

TARGETS := simple

CFLAGS += -I../..
LIBRARY_SRC := ../../polynomial.c ../../who-tables.c ../../grade.c

all: $(TARGETS) run

simple: simple.c
	$(CC) -o $@ $(CFLAGS) $(LIBRARY_SRC) $< \
	  -DPOLYNOMIAL_FIXED_FN_DEGREE=6 \
	  -DPOLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS=3

run:
	@for target in $(TARGETS); do \
	  "./$$target" || exit 1; \
	done

clean:
	rm -rf *.dSYM
	rm -f $(TARGETS) *.o *~


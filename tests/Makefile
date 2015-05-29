# Makefile

CFLAGS += -g -Wall

all:
	@for dir in *; do \
	  if [ -d "$$dir" ]; then \
	    (cd "$$dir" && ${MAKE}) || exit 1; \
	  fi; \
	done

clean:
	@for dir in *; do \
	  if [ -d "$$dir" ]; then \
	    (cd "$$dir" && ${MAKE} clean) || exit 1; \
	  fi; \
	done


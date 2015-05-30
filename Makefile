# Makefile

ifndef TURBO_DIR
TURBO_DIR := turbo-devel
endif

TURBO_TAG = --turbo-manifest "Vendor: Medic Mobile"
INCDIR  = -I$(TURBO_DIR)/include -I.
LIBDIR = $(TURBO_DIR)/lib

CC = avr-gcc
LD = avr-ld
RM = rm -f

LIB = 
TRG = sim-test
SRC = sim-test.c datetime.c polynomial.c who-tables.c

DEFINES = -DPOLYNOMIAL_FIXED_FN_DEGREE=6 \
  -DPOLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS=3

CFLAGS = $(DEFINES) -Os -Wall -fno-strict-aliasing \
    -std=gnu99 -fomit-frame-pointer -mmcu=atmega128 \
    -Wimplicit-function-declaration -fno-builtin

LDFLAGS = -L$(LIBDIR) -T $(TURBO_DIR)/lib/turbo.lds -d -r \
    --emit-relocs -R $(TURBO_DIR)/lib/public_calls $(LIB) -lc \
    `avr-gcc -print-libgcc-file-name`

OBJ = $(SRC:.c=.o)
  
all: $(TRG).trb

%.o : %.c 
	$(CC) -c $(CFLAGS) $(INCDIR) $< -o $@

$(TRG).elf: $(OBJ)
	$(LD) -o $@ $(OBJ) $(LDFLAGS)

$(TRG).trb: $(TRG).elf
	avr-objdump-turbo $(TURBO_TAG) --turbo $(TRG).elf

dis: $(TRG).elf
	avr-objdump-turbo -D --architecture=avr:5  $(TRG).elf >$(TRG).dis

clean:
	cd tests && ${MAKE} clean
	$(RM) *.o *~
	$(RM) $(TRG).dis
	$(RM) $(TRG).elf
	$(RM) $(TRG).trb
	$(RM) *.stackdump
	$(RM) -r .cyg*

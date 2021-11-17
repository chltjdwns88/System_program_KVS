SRCS1 = static_main.c
SRCS2 = dynamic_main.c
LIBSRCS = open.c close.c put.c get.c 
TARG1 = kvs_static
TARG2 = kvs_dynamic

CC = gcc
OPTS = -Wall -O
LIBS = -L. -lkvs

LOBJS = $(LIBSRCS:.c=.o)
LSRCS1 = $(SRCS1:.c=.o)
LSRCS2 = $(SRCS2:.c=.o)
LARS = libkvs.a
LARSHARED = libkvs.so

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

static : $(LOBJS) $(LSRCS1)
	ar rcs $(LARS) $(LOBJS)
	$(CC) -o $(TARG1) $(LSRCS1) -L. -lkvs

dynamic : $(LOBJS) $(LSRCS2)
	$(CC) -shared -o $(LARSHARED) $(LOBJS)
	$(CC) -o $(TARG2) $(LSRCS2) -ldl

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG1) $(TARG2) $(LARS) $(LARSHARED) $(LSRCS1) $(LSRCS2)

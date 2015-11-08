CC ?= cc
CFLAGS ?= -O

dummywm:	dummywm.c
	$(CC) $(CFLAGS) -o dummywm dummywm.c -lX11

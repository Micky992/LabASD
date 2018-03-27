VPATH = ../headers
srcdir = ../sources

a.out: queuelib.h stacklib.h $(srcdir)/queuelib.c $(srcdir)/stacklib.c main.c
	gcc -Wall -I $(VPATH) -g main.c $(srcdir)/queuelib.c $(srcdir)/stacklib.c

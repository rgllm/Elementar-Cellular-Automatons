#
#	Makefile Code
#

CFLAGS=-Wall -O2

OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

clean:
	rm bm *.o
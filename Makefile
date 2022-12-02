CC = gcc
INCLUDES = -I/work1/gthouvenin/opt/lua-5.4.4/include
LIBS = -L/work1/gthouvenin/opt/lua-5.4.4/lib -llua -lm -ldl
CFLAGS = -Wall -g

PROGS = main

main: main.c
	$(CC) -o main main.c $(INCLUDES) $(CFLAGS) $(LIBS)

clean:
	rm -f $(PROGS)

CC = gcc
CFLAGS = -O3 -std=c11
#DEPS =
SRCS = main.c ghosts.c kernel.c density.c output.c setup.c application.c
OBJS = $(SRCS:.c=.o)
MAIN = SPH

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(MAIN)
cleanruns:
	rm -f output.txt

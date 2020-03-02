CC = gcc
CFLAGS = -O3
#DEPS =
SRCS = main.c
OBJS = $(SRCS:.c=.o)
MAIN = SPH

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o $(MAIN)

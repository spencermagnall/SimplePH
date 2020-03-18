CC = gcc
CFLAGS = -O3 -std=c18 -Wall
#DEPS =
SRCS = main.c kinetic.c step_leapfrog.c force.c eos_isothermal.c derivs.c ghosts.c kernel.c density.c output.c setup.c application.c
OBJS = $(SRCS:.c=.o)
MAIN = SPH

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(MAIN)
cleanruns:
	rm -f snap_*

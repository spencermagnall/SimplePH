CC = gcc
CFLAGS = -O3 -std=c18 -Wall -g -Wextra
#DEPS =
SETUP = setup_sod.c
#SETUP = setup.c
SRCS = main.c viscosity.c kinetic.c smoothing.c step_leapfrog.c force.c eos_isothermal.c derivs.c ghosts.c kernel.c density.c output.c ${SETUP} application.c
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
	rm -f *.ev

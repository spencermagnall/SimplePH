CC = gcc
CFLAGS = -O3 -std=c18 -Wall -g -Wextra 
#DEPS =
EOS = eos_isothermal.c
#EOS = eos_adiabatic.c
SETUPFILE = setup.c
#SETUP = setup_sodiso.c
OPT = -D isSod=0

ifeq ($(SETUP), sodiso)
SETUPFILE = setup_sodiso.c
EOS = eos_isothermal.c
OPT = -D isSod=1
endif

ifeq ($(SETUP), sod)
SETUPFILE = setup_sod.c
EOS = eos_adiabatic.c
OPT = -D isSod=1
endif 

CFLAGS += $(OPT)

SRCS = main.c allocate.c viscosity.c kinetic.c smoothing.c step_leapfrog.c force.c ${EOS} derivs.c ghosts.c kernel.c density.c output.c ${SETUPFILE} application.c
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

CC = gcc
CFLAGS = -O3 -Wall -g -Wextra 
#DEPS =
EOS = eos_isothermal.c
#EOS = eos_adiabatic.c
SETUPFILE = setup.c
#SETUP = setup_sodiso.c
OPT = -D isSod=0
ARTVIS = -D artVis=1
ADTSMH = -D adapSmooth=1

ifeq ($(SETUP), sodiso)
SETUPFILE = setup_sodiso.c
EOS = eos_isothermal.c
OPT = -D isSod=1 -D spcleft=0.001 -D spcright=0.01
endif

ifeq ($(SETUP), sod)
SETUPFILE = setup_sod.c
EOS = eos_adiabatic.c
OPT = -D isSod=1 -D spcleft=0.001 -D spcright=0.008
endif 

OPT += $(ARTVIS) 
OPT += $(ADTSMH)
CFLAGS += $(OPT)

SRCS = main.c allocate.c viscosity.c kinetic.c smoothing.c step_leapfrog.c force.c ${EOS} derivs.c ghosts.c kernel.c density.c output.c ${SETUPFILE} application.c
OBJS = $(SRCS:.c=.o)
MAIN = SPH

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) -lm

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(MAIN)
cleanruns:
	rm -f snap_*
	rm -f *.ev
	rm -f splash.defaults
	rm -f splash.limits
plotstanding:
plotiso:
	cp iso.splash.defaults splash.defaults
	cp iso.splash.limits splash.limits
plotadb:
	cp adb.splash.defaults splash.defaults
	cp adb.splash.limits splash.limits

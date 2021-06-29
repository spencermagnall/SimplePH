# SimplePH
A simple Smoothed Particle Hydrodynamics Code written in C
## Description
SimplePH is a lightweight code for solving the Euler Equations using the Smoothed Particle Hydrodynamics Method.
It is not intended to be a highly optimized production code, as excellent codes such as GASOLINE, GADGET2 and PHANTOM already furfill this requirement.
This code is largely based of a course given by Daniel Price on SPH and the accompanying paper (https://doi.org/10.1016/j.jcp.2010.12.011). 
## Getting Started

### Compiling and Running a Simulation 
After Cloning the Repository, the inital conditions are selected at compile time via a SETUP compile flag. Currently, a Standing Wave and isothermal and adibatic versions of the shock tube of Sod (https://doi.org/10.1016%2F0021-9991%2878%2990023-2) are included as sample initial conditions in SimplePH.

#### Standing Wave
Typing "make" with no SETUP options will compile the code for running a simulation of a standing wave. The code can then be executed with "./SPH
", and will dump particle information (position, velocity, etc.) every dtout units. The code will also output an .ev file which contains the evolution of the total energy as a function of time. 

#### Isothermal Shocktube
Providing "SETUP=sodiso" at compile time will compile the code for an isothermal shocktube

#### Adibatic Shocktube
Providing "SETUP=sod" at compile time will compile the code for an adibatic shock tube with adibatic index of . 

### Altering parameters
Parameters for the code such as number of particles, output, artificial viscosity parameters, etc. are defined in the const.h header. These parameters may be freely changed (e.g changing the number of particles to increase the resolution of the simulation), but also may produce unphysicial results, or break the code entirely. 



## Visulisation of Results
Dump files for a completed simulation are in a ascii format with the prefix "snap_" and can be visuallised using the plotting software of your choice. However, I recommend using SPLASH, which can be downloaded from https://users.monash.edu.au/~dprice/splash/. SPLASH has many useful features 

## Acknowledgments

#ifndef CONST_H
#define CONST_H

// the maximum number of particles 
#define nopart 1000
// the maximum number of ghost particles
// set to 200 so that both edges can have ghost part
#define noghost 2000
// xmin and xmax
#define xmin 0.0
#define xmax 1.0
// timestep interval
#define dt  0.0001
// output interval
#define dtout 0.1
// artifical viscosity parms
#define alpha 1.0
#define beta 2.0

// Special values for Sod Shock Tube
#define sod1 -0.5
#define sod2  0.5

#endif //CONST_H

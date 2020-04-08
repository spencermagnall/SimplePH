#ifndef CONST_H
#define CONST_H

// flag for sod options 
//#define isSod 0 

// fixed timestepping
#define fixedstep 1
// Special values for Sod Shock Tube
#define sod1 -0.5
#define sod2  0.5

// artifical viscosity parms
#define alpha 1.0
#define beta 2.0

#if isSod == 0
    // the maximum number of particles 
    #define nopart 100
    // the maximum number of ghost particles
    // set to 200 so that both edges can have ghost part
    #define noghost 200
    // xmin and xmax
    #define xmin 0.0
    #define xmax 1.0
    // timestep interval
    //#define dt  0.0001
    //double dt = 0.0001;
    // output interval
    #define dtout 0.01
    #define tmax 5.0

#elif isSod == 1 
    #define nopart 2000
    // the maximum number of ghost particles
    // set to 200 so that both edges can have ghost part
    #define noghost 4000
    // xmin and xmax
    #define xmin -1.5
    #define xmax 0.5
    // timestep interval
    //#define dt  0.0001
    //double dt = 0.0001;
    // output interval
    #define dtout 0.1
    // adiabatic index 
    //#define gamma 1.4
    #define tmax 0.2
#endif


#endif //CONST_H

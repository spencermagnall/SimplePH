#include <stdio.h>
#include "allocate.h"
#include "arrays.h"
#include "application.h"
#include "setup.h"
#include "output.h"
#include "ghosts.h"
#include "density.h"
#include "derivs.h"
#include "kinetic.h"
#include "step.h"
#include "particledata.h"
#include <stdlib.h>

void application(){
    printf("Entered Application \n");
    double t = 0.0;
    //double tmax = 5.0;
    double dt = 0.0001;
    printf("Working Correctly\n");
    printf("xmin: %f \n",xmin);
    printf("xmax: %f \n",xmax);
    printf("IsSod: %d \n", isSod);
    int ifile = 1;
    double tprint = (double)ifile*dtout;
    
    allocate();
    // This would be easy in c++ 
    for (int i=0; i < nopart+noghost; i++){
        printf("i = %d \n",i);
        P[i].exists = false;
    }
    printf("Particles exist! \n");
    int particles = setup(P);
    printf("Particles Setup: %d \n",particles);
    printf("xmin %f \n",xmin);
    printf("xmax %f \n", xmax);
    writeOutput(particles,P,0,t);
    exit(0);
    //dt = derivs(particles,&particleData);
    printf("dt %f \n",dt);
    //exit(0);
    printf("Derivs passed. \n");
    //writeOutput(particles, &particleData,0,t);
    //outputEnergy(particles, &particleData,0,t);
    printf("Write output passed \n");
    //exit(0);
    while (t < tmax){
        t += dt;
        for (int i=nopart; i<nopart+noghost; i++){
            P[i].exists = false;

        }
        //dt = step(particles, &particleData,dt);
        printf("Time is: %f \n", t);
        //outputEnergy(particles,&particleData,ifile,t);
        if (t > tprint){
            //writeOutput(particles, &particleData,ifile,t);
            ifile += 1;
            tprint = (double) ifile*dtout;
            //exit(0);
            if (ifile == 10){
                //exit(0);
            }
        }
    }


}

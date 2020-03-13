#include <stdio.h>
#include "arrays.h"
#include "application.h"
#include "setup.h"
#include "output.h"
#include "ghosts.h"
#include "density.h"
#include "derivs.h"
#include "step.h"
#include <stdlib.h>
void application(){
    float t = 0.0;
    float tmax = 5.0;
    printf("Working Correctly\n");
    struct arrays particleData;
    int ifile = 1;
    float tprint = (float)ifile*dtout;

    // This would be easy in c++ 
    for (int i=0; i < nopart+noghost; i++){
        particleData.exists[i] = false;
    }

    int particles = setup(&particleData);
    printf("Particles Setup: %d",particles);
    printf("\n");
    //exit(0);
    // passes particles-1 since arrays start at 0
    //setGhosts(particles,&particleData);
    //printf("SetGhost passed. \n");
    //getDensity(particles,&particleData);
    //printf("Density calc passed. \n");
    derivs(particles,&particleData);
    printf("Derivs passed. \n");
    writeOutput(particles, &particleData,0);
    printf("Write output passed \n");
    //exit(0);
    while (t < tmax){
        t += dt;
        for (int i=nopart; i<nopart+noghost; i++){
            particleData.exists[i] = false;

        }
        step(particles, &particleData);
        printf("Time is: %f \n", t); 
        if (t > tprint){
            writeOutput(particles, &particleData,ifile);
            ifile += 1;
            tprint = (float) ifile*dtout;
            //exit(0);
            if (ifile == 10){
                //exit(0);
            }
        }
    }


}

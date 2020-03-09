#include <stdio.h>
#include "arrays.h"
#include "application.h"
#include "setup.h"
#include "output.h"
#include "ghosts.h"
#include "density.h"
#include <stdlib.h>
void application(){
    printf("Working Correctly\n");
    struct arrays particleData;

    // This would be easy in c++ 
    for (int i=0; i < nopart+noghost; i++){
        particleData.exists[i] = false;
    }

    int particles = setup(&particleData);
    printf("Particles Setup: %d",particles);
    printf("\n");
    //exit(0);
    // passes particles-1 since arrays start at 0
    setGhosts(particles,&particleData);
    getDensity(particles,&particleData);
    writeOutput(particles, &particleData,0);

}

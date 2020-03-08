#include <stdio.h>
#include "arrays.h"
#include "application.h"
#include "setup.h"
#include "output.h"
#include "ghosts.h"
#include "density.h"
void application(){
    printf("Working Correctly\n");
    struct arrays particleData;
    int particles = setup(&particleData);
    //printf("%d",particlesSetup);
    printf("\n");
    setGhosts(particles,&particleData);
    getDensity(particles,&particleData);
    writeOutput(&particleData,0);

}

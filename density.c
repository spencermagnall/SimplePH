#include "arrays.h"
#include "density.h"
#include "const.h"
#include "kernel.h"
#include <math.h>
#include <stdio.h>

void getDensity(int particles,struct arrays *particleData){
    double rho = 0.0;
    double wkern = 0.0;
    double grkern =0.0;
    double h = 0;
    double ra = 0;
    double rb = 0.0;
    double dx =0.0;
    double Cnorm = 0.0;
    double q = 0.0;
    double Wab = 0.0;
    double partMass = 0.0;

    for (int i=0; i < nopart; i++){
        rho = 0.0;
        h = particleData->h[i];
        ra = particleData->x[i];
        //printf("i is: %d \n",i);
        for (int j=0; j < particles + noghost; j++){
            //if (particleData->exists[j] == true) {
                //printf("j is: %d \n",j);
                partMass = particleData->m[j];
                rb = particleData->x[j];
                dx = fabs(ra-rb);
                Cnorm = 2.0/3.0;
                q = dx/h;
                getKernel(q,&wkern,&grkern);
                
                // store grkern for later
                particleData->grkerns[i][j] = grkern;
                
                /*
                printf("h: ");
                printf("%f \n",h);
                printf("q: ");
                printf("%f \n",q);
                printf("wkern: ");
                printf("%f \n", wkern);
                double cnormh = Cnorm/(h);
                printf("cnormh: ");
                printf("%f \n",cnormh);
                */
                Wab = (Cnorm/h)*wkern;
                //printf("Wab: ");
                //printf("%f \n", Wab);
                rho += partMass*Wab;
                //printf("rho: ");
                //printf("%f \n", rho);
            //}
            
        }
        particleData->rho[i] = rho;

    }        
}

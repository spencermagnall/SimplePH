#include "arrays.h"
#include "density.h"
#include "const.h"
#include "kernel.h"
#include <math.h>
#include <stdio.h>

void getDensity(int particles,int ghosts,struct arrays *particleData){
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
    int n;
    n = particles + ghosts;
    
    for (int i=0; i < particles; i++){
        rho = 0.0;
        h = particleData->h[i];
        ra = particleData->x[i];
        for (int j=0; j < n; j++){
                partMass = particleData->m[j];
                rb = particleData->x[j];
                dx = fabs(ra-rb);
                Cnorm = 2.0/3.0;
                q = dx/h;
                getKernel(q,&wkern,&grkern);
                
                // store grkern for later
                //particleData->grkerns[i][j] = grkern;
                
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
                rho += partMass*Wab;
            
        }
        particleData->rho[i] = rho;

    }        
}

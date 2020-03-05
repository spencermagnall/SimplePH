#include "arrays.h"
#include "density.h"
#include "const.h"
#include "kernel.h"
#include <math.h>
#include <stdio.h>

void getDensity(struct arrays *particleData){
    float rho = 0.0;
    float wkern = 0.0;
    float grkern =0.0;
    float h = 0;
    float ra = 0;
    float rb = 0.0;
    float dx =0.0;
    float Cnorm = 0.0;
    float q = 0.0;
    float Wab = 0.0;
    float partMass = 0.0;

    for (int i=0; i < nopart; i++){
        rho = 0.0;
        h = particleData->h[i];
        ra = particleData->x[i];
        for (int j=0; j < nopart; j++){
            partMass = particleData->m[j];
            rb = particleData->x[j];
            dx = fabs(ra-rb);
            Cnorm = 1/M_PI;
            q = dx/h;
            getKernel(q,&wkern,&grkern);
            printf("q: ");
            printf("%f \n",q);
            Wab = Cnorm/(pow(h,3))*wkern;
            rho += partMass*Wab; 

        }
        particleData->rho[i] = rho;

    }        
}

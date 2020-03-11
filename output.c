#include "output.h"
#include "arrays.h"
#include <stdio.h>

void writeOutput(int particles, struct arrays *particleData,int outputno){
    FILE *fp;

    fp = fopen("output.txt","w+");
    fprintf(fp,"x   v   a   rho \n");
    for (int i=0; i < particles; i++){
        float x = particleData->x[i];
        float v = particleData->v[i];
        float a = particleData->a[i];
        float rho = particleData->rho[i];

        fprintf(fp,"%e  %e  %e  %e  \n", x, v,a,rho);
    }
}

#include "output.h"
#include "arrays.h"
#include <stdio.h>

void writeOutput(struct arrays *particleData,int outputno){
    FILE *fp;

    fp = fopen("output.txt","w+");

    for (int i=0; i < nopart; i++){
        float x = particleData->x[i];
        float v = particleData->v[i];
        fprintf(fp,"%e  %e  \n", x, v);
    }
}

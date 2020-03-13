#include "output.h"
#include "arrays.h"
#include <stdio.h>
#include <string.h>
#define STRINGSIZE 40
void writeOutput(int particles, struct arrays *particleData,int outputno){
    FILE *fp;

    // Good old sloppy c string concat
    char output[6];
    sprintf(output,"%05d",outputno);
    char snap[STRINGSIZE] = "snap_";
    strcat(snap,output);

    fp = fopen(snap,"w+");
    fprintf(fp,"x   v   a   rho P \n");
    for (int i=0; i < particles+noghost; i++){
        printf("%d \n",i);
        float x = particleData->x[i];
        float v = particleData->v[i];
        float a = particleData->a[i];
        float rho = particleData->rho[i];
        float P = particleData->P[i];

        fprintf(fp,"%e  %e  %e  %e  %e  \n", x, v,a,rho,P);
    }
    fclose(fp);
}

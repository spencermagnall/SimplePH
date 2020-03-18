#include "output.h"
#include "arrays.h"
#include "kinetic.h"
#include <stdio.h>
#include <string.h>
#define STRINGSIZE 40
void writeOutput(int particles, struct arrays *particleData,int outputno,double time){
    FILE *fp;
    FILE *fpev;

    // Get the total Kinetic Energy
    double ke = getKinetic(particles,particleData);
    
    // Good old sloppy c string concat
    char output[6];
    sprintf(output,"%05d",outputno);
    char snap[STRINGSIZE] = "snap_";
    strcat(snap,output);
    fpev = fopen("energy.ev","a");
    fp = fopen(snap,"w+");
    if (outputno == 0){
        fprintf(fpev, "t   ke \n");
    }
    fprintf(fpev,"%e  %e \n",time,ke);
    fprintf(fp,"x   v   a   rho   P \n");
    for (int i=0; i < particles+noghost; i++){
        printf("%d \n",i);
        double x = particleData->x[i];
        double v = particleData->v[i];
        double a = particleData->a[i];
        double rho = particleData->rho[i];
        double P = particleData->P[i];

        fprintf(fp,"%e  %e  %e  %e  %e  \n", x, v,a,rho,P);
    }
    fclose(fp);
}

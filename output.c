#include "output.h"
#include "arrays.h"
#include "kinetic.h"
#include <stdio.h>
#include <string.h>
#define STRINGSIZE 40

void writeOutput(int particles, struct arrays *particleData,int outputno,double time){
    FILE *fp;
    
    
    // Good old sloppy c string concat
    char output[6];
    sprintf(output,"%05d",outputno);
    char snap[STRINGSIZE] = "snap_";
    strcat(snap,output);
    
    fp = fopen(snap,"w+");
    
    
    fprintf(fp,"x, vx, ax, density, pressure, u, dudt \n");
    fprintf(fp,"%f \n",time);
    for (int i=0; i < particles+noghost; i++){
        printf("%d \n",i);
        double x = particleData->x[i];
        double v = particleData->v[i];
        double a = particleData->a[i];
        double rho = particleData->rho[i];
        double P = particleData->P[i];
        double u = particleData->u[i];
        double dudt = particleData->du[i];

        fprintf(fp,"%e  %e  %e  %e  %e  %e  %e  \n", x, v,a,rho,P,u,dudt);
    }
    fclose(fp);
}

void outputEnergy(int particles,struct arrays *particleData,int outputno,double time){
    FILE *fpev;

    // Get the total Kinetic Energy
    double ke = getKinetic(particles,particleData);
    fpev = fopen("energy.ev","a");
    if (outputno == 0){
        fprintf(fpev, "t   ke \n");
    }
    fprintf(fpev,"%e  %e \n",time,ke);
    fclose(fpev);
}

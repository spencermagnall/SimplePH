#include "output.h"
#include "arrays.h"
#include "kinetic.h"
#include <stdio.h>
#include <string.h>
#include "particledata.h"
#define STRINGSIZE 40

void writeOutput(int particles, struct particledata *particleData,int outputno,double time){
    FILE *fp;
    
    
    // Good old sloppy c string concat
    char output[6];
    sprintf(output,"%05d",outputno);
    char snap[STRINGSIZE] = "snap_";
    strcat(snap,output);
    
    fp = fopen(snap,"w+");
    
    
    fprintf(fp,"x, vx, ax, density, pressure, u, dudt, m \n");
    fprintf(fp,"%f \n",time);
    for (int i=0; i < particles; i++){
        
        if (particleData[i].exists){
            double x = particleData[i].x[0];
            double v = particleData[i].v[0];
            double a = particleData[i].a[0];
            double rho = particleData[i].rho;
            double P = particleData[i].Pressure;
            double u = particleData[i].u;
            double m = particleData[i].m;

            fprintf(fp,"%e  %e  %e  %e  %e  %e  %e  \n", x, v,a,rho,P,u,m);
    
        }
    }
    fclose(fp);
}

void outputEnergy(int particles,struct particledata *particleData,int outputno,double time){
    FILE *fpev;

    // Get the total Kinetic Energy
    // TODO FIX THIS 
    //double ke = getKinetic(particles,particleData);
    fpev = fopen("energy.ev","a");
    if (outputno == 0){
        fprintf(fpev, "t   ke \n");
    }
    //fprintf(fpev,"%e  %e \n",time,ke);
    fclose(fpev);
}

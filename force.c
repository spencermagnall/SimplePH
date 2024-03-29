#include "force.h"
#include "const.h"
#include "arrays.h"
#include "kernel.h"
#include "viscosity.h"
#include <stdio.h>
#include <math.h>

double getVsig(double cs, double vab, double rab){
    double vsig = alpha*cs - beta*(vab*rab);
    return vsig;
}

double getAccel(int particles,int ghosts, struct arrays *particleData){
    double dtnew;
    double rhoa;
    double rhob;
    double pressurea;
    double pressureb;
    double grkerna = 0.0;
    double grkernb= 0.0;
    double massb;
    double a;
    double ha;
    double hb;
    double wkern =0.0;
    double xa;
    double xb;
    double dx;
    double q;
    double grada;
    double gradb;
    double da;
    double da2;
    double danorm;
    double db;
    double db2;
    double dbnorm;
    double sigma = 2./3.;
    double va;
    double vb;
    double vab;
    double rab;
    double qab = 0.0;
    double qabb = 0.0;
    double du;
    int n;
    double cs;
    //if (isSod == 1){
    //    n = particles;
    //} else {
        n = particles + ghosts;
    //}


    for (int i=0; i<particles; i++){
        rhoa = particleData->rho[i];
        pressurea = particleData->P[i];
        a = 0.0;
        ha = particleData->h[i];
        xa = particleData->x[i];
        va = particleData->v[i];
        du = 0.0; 
        // Should I store grkern or recalculate
        // Stored currently can be accesed in particleData
        for (int j=0; j<n; j++){
             if (i != j && particleData->exists[j] == true){ 
                xb = particleData->x[j];
                vb = particleData->v[j];
                da = xa-xb;
                da2 = da*da;
                danorm = sqrt(da2);
                db = xb-xa;
                db2 = db*db;
                dbnorm = sqrt(db2);
                hb = particleData->h[j];
                rhob = particleData->rho[j];
                pressureb = particleData->P[j];
                dx = fabs(xa-xb);

                // for particle a
                rab = da/danorm;
                vab = va-vb;
                cs = particleData->cs[i];
               
                // Shock capture if enabled 
                if (artVis == 1){
                    double vsig  = getVsig(cs,vab,rab);
                    qab = getViscosity(rhoa,vsig,vab,rab);
                } else {
                    qab = 0.0;
                }
                
                
                // for particle b
                rab = db/dbnorm;
                vab = vb-va;
                cs = particleData->cs[j];
                // shock capture if enabled
                if (artVis == 1){
                    double vsig = getVsig(cs,vab,rab);
                    qabb = getViscosity(rhob,vsig,vab,rab);
                } else {
                    qabb = 0.0;
                }
                

                //grkerna = particleData->grkerns[i][j];
                //grkernb = particleData->grkerns[j][i];
                q = dx/ha;
                getKernel(q,&wkern,&grkerna);
                //dx = fabs(xb-xa);
                q = dx/hb;
                getKernel(q,&wkern,&grkernb);

                grada = sigma*grkerna*(1.0/(ha*ha))*(da/danorm);
                gradb = sigma*grkernb*(1.0/(hb*hb))*(da/danorm);
                massb = particleData->m[j];
                a += -massb*(((pressurea+qab)/(rhoa*rhoa))*grada + ((pressureb+qabb)/(rhob*rhob))*gradb);
                du +=  massb*(((pressurea+qab)/(rhoa*rhoa))*(va-vb)*grada);  
                //printf("j is: %d \n", j);
               
                /*
                printf("acell: ");
                printf("%f \n",a);
                printf("pressure a: %f \n",pressurea);
                printf("pressure b: %f \n", pressureb);
                printf("grkern a: %f \n",grkerna);
                printf("grkern b: %f \n",grkernb);
                */
            }
        }

        // store new accel
        particleData->a[i] = a;
        particleData->du[i] = du;
    }
    
    // CFL
    double min = 1.e10;
    double current;
    for (int i=0; i<particles; i++){
        ha = particleData->h[i];
        cs = particleData->cs[i];
        current = 0.2*(ha/cs);
        current < min ? (min=current) : (min);
    }
    // SLOPPY 
    // IF ANYTHING BREAKS THIS IS WHY
    // SHOULD JUST BE A REGULAR VARIABLE AT THIS POINT 
    //#undef dt
    dtnew = min;
     
    return dtnew;
}

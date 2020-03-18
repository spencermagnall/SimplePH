#include "force.h"
#include "const.h"
#include "arrays.h"
#include "kernel.h"
#include <stdio.h>
#include <math.h>
void getAccel(int particles, struct arrays *particleData){
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
    


    for (int i=0; i<particles; i++){
        rhoa = particleData->rho[i];
        pressurea = particleData->P[i];
        a = 0.0;
        ha = particleData->h[i];
        xa = particleData->x[i];
        // Should I store grkern or recalculate
        // Stored currently can be accesed in particleData
        for (int j=0; j<particles+noghost; j++){
             if (i != j){
                xb = particleData->x[j];
                da = xa-xb;
                da2 = da*da;
                danorm = sqrt(da2);
                db = xb-xa;
                db2 = db*db;
                dbnorm = sqrt(da2);
                hb = particleData->h[j];
                rhob = particleData->rho[j];
                pressureb = particleData->P[j];
                dx = fabs(xa-xb);
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
                a += -massb*((pressurea/(rhoa*rhoa))*grada + (pressureb/(rhob*rhob))*gradb);
                
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
    }

}
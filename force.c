#include "force.h"
#include "const.h"
#include "arrays.h"
#include "kernel.h"
#include <stdio.h>
#include <math.h>
void getAccel(int particles, struct arrays *particleData){
    float rhoa;
    float rhob;
    float pressurea;
    float pressureb;
    float grkerna = 0.0;
    float grkernb= 0.0;
    float massb;
    float a;
    float ha;
    float hb;
    float wkern =0.0;
    float xa;
    float xb;
    float dx;
    float q;
    float grada;
    float gradb;
    float da;
    float da2;
    float danorm;
    float db;
    float db2;
    float dbnorm;
    


    for (int i=0; i<particles; i++){
        rhoa = particleData->rho[i];
        pressurea = particleData->P[i];
        a = 0.0;
        ha = particleData->h[i];
        xa = particleData->x[i];
        // Should I store grkern or recalculate
        // Stored currently can be accesed in particleData
        for (int j=0; j<particles; j++){
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
                grkerna = particleData->grkerns[i][j];
                grkernb = particleData->grkerns[j][i];
                //q = dx/ha;
                //getKernel(q,&wkern,&grkerna);
                dx = fabs(xb-xa);
                //q = dx/hb;
                //getKernel(q,&wkern,&grkernb);
                grada = grkerna*(1.0/ha)*(da/danorm);
                gradb = grkernb*(1.0/hb)*(db/dbnorm);
                massb = particleData->m[j];
                a += -massb*(pressurea/(rhoa*rhoa)*(2./(3.0*ha))*grada + pressureb/(rhob*rhob)*(2./(3.0*hb))*gradb);
                printf("acell: ");
                printf("%f \n",a);
                printf("pressure a: %f \n",pressurea);
                printf("pressure b: %f \n", pressureb);
                printf("grkern a: %f \n",grkerna);
                printf("grkern b: %f \n",grkernb);
            }
        }

        // store new accel
        particleData->a[i] = a;
    }

}

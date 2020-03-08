#include "kernel.h"
#include <math.h>

void getKernel(float q, float *wkern, float *grkern){
    float q2 = pow(q,2.0);

    if (q < 1.){
        *wkern = 0.75*q2*q - 1.5*q2 + 1.;
        *grkern = q*(2.25*q-3.);
    } else if (q < 2.){
        *wkern = 0.25*pow((2.-q),3);
        *grkern = -0.75*pow((q - 2.),2);
    } else {
        *wkern = 0.0;
        *grkern = 0.0;
    }
}

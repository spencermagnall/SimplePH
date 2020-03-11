#ifndef ARRAYS_H
#define ARRAYS_H

#include "const.h"
#include <stdbool.h>
struct arrays
{
    float x[nopart+noghost];
    float v[nopart+noghost];
    float a[nopart+noghost];
    float m[nopart+noghost];
    float h[nopart+noghost];
    float rho[nopart+noghost];
    float u[nopart+noghost];
    float P[nopart+noghost];
    float cs[nopart+noghost];

    // This is an additional flag to prevent
    // garbage values being used in calculations
    // since N<= NMax several values may not be initilized
    bool exists[nopart+noghost];

    // Store the gradient of the kernel function
    // Since this is calculated for density but 
    // not used until the accel calc
    // Grad Wab = grkerns[a][b]
    float grkerns[nopart+noghost][nopart+noghost];

};

#endif 

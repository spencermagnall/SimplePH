#ifndef ARRAYS_H
#define ARRAYS_H

#include "const.h"
#include <stdbool.h>
struct arrays
{
    double x[nopart+noghost];
    double v[nopart+noghost];
    double a[nopart+noghost];
    double m[nopart+noghost];
    double h[nopart+noghost];
    double rho[nopart+noghost];
    double u[nopart+noghost];
    double P[nopart+noghost];
    double cs[nopart+noghost];

    // This is an additional flag to prevent
    // garbage values being used in calculations
    // since N<= NMax several values may not be initilized
    bool exists[nopart+noghost];

    // Store the gradient of the kernel function
    // Since this is calculated for density but 
    // not used until the accel calc
    // Grad Wab = grkerns[a][b]
    double grkerns[nopart+noghost][nopart+noghost];

};

#endif 

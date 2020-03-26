#ifndef ARRAYS_H
#define ARRAYS_H

#include "const.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//int arraysize = nopart+noghost;

struct arrays
{
    double *x, *v, *a, *m, *h, *rho, *u,*du,*P, *cs;
    //
    bool *exists;

    // Store the gradient of the kernel function
    // Since this is calculated for density but 
    // not used until the accel calc
    // Grad Wab = grkerns[a][b]
    double *grkerns;

};

#endif 

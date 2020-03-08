#ifndef ARRAYS_H
#define ARRAYS_H

#include "const.h"

struct arrays
{
    float x[nopart+noghost];
    float v[nopart+noghost];
    float m[nopart+noghost];
    float h[nopart+noghost];
    float rho[nopart+noghost];
    float u[nopart+noghost];
    float P[nopart+noghost];
    float cs[nopart+noghost];

};

#endif 

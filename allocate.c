#include "allocate.h"
#include "arrays.h"
#include "const.h"

int arraysize = nopart + noghost;

void allocate(struct arrays *particleData){
    particleData->x = malloc(arraysize * sizeof(double));
    particleData->v = malloc(arraysize * sizeof(double));
    particleData->a = malloc(arraysize * sizeof(double));
    particleData->m = malloc(arraysize * sizeof(double));
    particleData->h = malloc(arraysize * sizeof(double));
    particleData->rho = malloc(arraysize * sizeof(double));
    particleData->u = malloc(arraysize * sizeof(double));
    particleData->P = malloc(arraysize * sizeof(double));
    particleData->cs = malloc(arraysize * sizeof(double));
    particleData->exists = malloc(arraysize * sizeof(bool));
    particleData->grkerns = malloc(arraysize * sizeof(double)); 
    particleData->du = malloc(arraysize*sizeof(double));
}

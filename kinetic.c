#include "kinetic.h"
#include "arrays.h"

double getKinetic(int particles, struct arrays *particleData){
    double ke = 0.0;
    double mass;
    double velocity;
    for (int i=0; i<particles; i++){
        mass = particleData->m[i];
        velocity = particleData->v[i];
        ke += 0.5*mass*velocity*velocity;
    }
    return ke;
}

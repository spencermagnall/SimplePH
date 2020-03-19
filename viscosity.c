#include "viscosity.h"

double getViscosity(double rho, double vsig, double vab, double rab){
     double qab;
     // Dot Product in 1d
     double dot = vab*rab;
     qab = dot < 0 ? -0.5*rho*vsig*dot : 0;
     return qab;
 }

#ifndef STEP_H
#define STEP_H

struct arrays;
//returns new dt
double step(int particles, struct arrays *particleData,double dt);

#endif // STEP_H

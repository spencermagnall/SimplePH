#include <stdio.h>
#include "arrays.h"
#include "application.h"
#include "setup.h"
#include "output.h"
void application(){
    printf("Working Correctly\n");
    struct arrays particleData;
    int particlesSetup = setup(&particleData);
    printf("%d",particlesSetup);
    printf("\n");
    writeOutput(&particleData,0);

}

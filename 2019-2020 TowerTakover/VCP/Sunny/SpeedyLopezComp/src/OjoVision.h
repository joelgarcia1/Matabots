/*vex-vision-config:begin*/
#include "v5.h"
#include "v5_vcs.h"
vex::vision::signature ORG = vex::vision::signature (1, 4761, 5851, 5306, -4921, -4397, -4660, 3, 0);
vex::vision::signature PURP = vex::vision::signature (2, -1599, -399, -998, 3039, 6241, 4640, 1.9, 0);
vex::vision::signature GRN = vex::vision::signature (3, -8089, -6825, -7458, -7749, -6449, -7100, 3, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision Vision1 = vex::vision (vex::PORT12, 50, ORG, PURP, GRN, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/
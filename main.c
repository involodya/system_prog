//-------------------------------------------------
//! The squire equations solver programme
//!     @version Vers 1.0
//!     @date 17. 09. 2021
//!     @brief Solving task #1 for the course "Professional Programming"
//-------------------------------------------------

#include <stdio.h>

#include "defines.h"
#include "solve.h"


int main() {

    printf("# Square equation solver\n"
           "# @involodya, 2021\n\n");
    printf("# Enter a, b, c: ");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    switch (nRoots) {
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("x = %lg\n", x1);
            break;
        case 2:
            printf("x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case SS_INF_ROOTS:
            printf("Any number");
            break;
        default:
            printf("main(): ERROR: nRoots = %d\n",
                   nRoots);
            return 1;
    }

}

//!
//! The squire equations solver programme
//!     @version Vers 2.1
//!     @date 02. 12. 2021
//!     @brief Solving task #1 for the course "Professional Programming"
//!

#include <stdio.h>

#include "defines.h"
#include "solve.h"

#ifdef _TEST

#include "unittest.h"

#endif


int main() {

    printf("# Square equation solver\n"
           "# @involodya, 2021\n\n");

    double a = 0, b = 0, c = 0, n = 1;

#ifdef _TEST // if test mode on generate tests
    n = NUMBER_OF_TESTS;
    TestLaunch();
#endif

    for (int i = 0; i < n; ++i) {
#ifdef _TEST // if test mode get test a, b and c
        TestGet(&a, &b, &c, i);
#else
        printf("# Enter a, b, c: ");
        if (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
            printf("\nIncorrect input\n");
            return 0;
        }
#endif
        double x1 = 0, x2 = 0;
        int nRoots = SolveSquare(a, b, c, &x1, &x2);
#ifdef _TEST // if test mode check the answer
        TestCheck(nRoots, x1, x2, i);
#endif
        switch (nRoots) {
            case 0:
                printf("No roots");
                break;
            case 1:
                printf("x = %lg", x1);
                break;
            case 2:
                printf("x1 = %lg, x2 = %lg", x1, x2);
                break;
            case SS_INF_ROOTS:
                printf("Any number");
                break;
            default:
                printf("main(): ERROR: nRoots = %d",
                       nRoots);
                return 1;
        }
        printf("\n\n");
    }

}

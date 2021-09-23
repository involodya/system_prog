#include "unittest.h"


struct SquarePolynomial tests[NUMBER_OF_TESTS];


bool isEqual(double a, double b) {
    return (-ACCURACY < a - b && a - b < ACCURACY ||
            -ACCURACY < b - a && b - a < ACCURACY);
}

void TestLaunch() {
    {
        tests[0].A = 1;
        tests[0].B = 2;
        tests[0].C = 1;
        tests[0].nRoots = 1;
        tests[0].x1 = -1;
        tests[0].x2 = -1;
    }
    {
        tests[1].A = 0;
        tests[1].B = 5;
        tests[1].C = 0;
        tests[1].nRoots = 1;
        tests[1].x1 = 0;
        tests[1].x2 = 0;
    }
    {
        tests[2].A = 1;
        tests[2].B = -8;
        tests[2].C = 12;
        tests[2].nRoots = 2;
        tests[2].x1 = 2;
        tests[2].x2 = 6;
    }
    {
        tests[3].A = 3;
        tests[3].B = 7;
        tests[3].C = -6;
        tests[3].nRoots = 2;
        tests[3].x1 = -3;
        tests[3].x2 = 2.0 / 3;
    }
    {
        tests[4].A = -4;
        tests[4].B = 3;
        tests[4].C = 2;
        tests[4].nRoots = 2;
        tests[4].x1 = (3 - sqrt(41)) / 8;
        tests[4].x2 = (3 + sqrt(41)) / 8;
    }
    {
        tests[5].A = 1;
        tests[5].B = 1;
        tests[5].C = 1;
        tests[5].nRoots = 0;
        tests[5].x1 = 0;
        tests[5].x2 = 0;
    }
    {
        tests[6].A = 0;
        tests[6].B = 0;
        tests[6].C = 0;
        tests[6].nRoots = SS_INF_ROOTS;
        tests[6].x1 = 0;
        tests[6].x2 = 0;
    }
}


void TestGet(double *a, double *b, double *c, int n) {
    assert(n < NUMBER_OF_TESTS);

    *a = tests[n].A;
    *b = tests[n].B;
    *c = tests[n].C;
}

void raisePassed(int n) {
    printf("Test #%d passed\n", n);
}

void raiseFailed(int n) {
    printf("Test #%d failed\n", n);
}

void TestCheck(int nRoots, double x1, double x2, int n) {
    assert(n < NUMBER_OF_TESTS);

    if (nRoots != tests[n].nRoots) {
        raiseFailed(n);
        return;
    }

    if (nRoots == 0 || nRoots == SS_INF_ROOTS) {
        raisePassed(n);
        return;
    }

    if (tests[n].nRoots == 1) {
        if (tests[n].x1 == x1) {
            raisePassed(n);
        } else { // answer not matched
            raiseFailed(n);
        }
    } else if (tests[n].nRoots == 2) {
        if ((isEqual(tests[n].x1, x1) && isEqual(tests[n].x2, x2)) ||
            (isEqual(tests[n].x1, x2) && isEqual(tests[n].x2, x1))) {
            raisePassed(n);
        } else { // answers not matched
            raiseFailed(n);
        }
    }
}

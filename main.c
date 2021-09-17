//-------------------------------------------------
//! The squire equations solver programme
//!     @version Vers 1.0
//!     @date 17. 09. 2021
//!     @brief Solving task #1 for the course "Professional Programming"
//-------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>


#define SS_INF_ROOTS -1 // code for an infinite number of solutions

//------------------------------------------------
//! Check is number a zero
//!
//! @param [in] n double number
//!
//! @return is n at a distance of 1e-9 about zero
//!
//------------------------------------------------
bool isZero(double n);

//------------------------------------------------
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns SS_INF_ROOTS.
//------------------------------------------------
int SolveSquare(double a, double b, double c, double *x1, double *x2);

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

bool isZero(double n) {
    if (-1e-9 < n && n < 1e-9)
        return true;
    return false;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isZero(a)) {
        if (isZero(b)) {

            return (isZero(c)) ? SS_INF_ROOTS : 0;

        } else { /* if (b != 0) */

            *x1 = -c / b;
            return 1;

        }
    } else { /* if (a != 0) */

        double d = b * b - 4 * a * c;
        if (isZero(d)) {
            *x1 = *x2 = -b / (2 * a);
            return 1;

        } else if (d > 0) {

            double sqrt_d = sqrt(d);
            *x1 = (-b - sqrt_d) / (2 * a);
            *x2 = (-b + sqrt_d) / (2 * a);
            return 2;

        } else { /* if d < 0 */

            return 0;

        }
    }
}
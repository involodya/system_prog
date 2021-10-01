#include "solve.h"


bool isZero(double n) {
    if (-ACCURACY < n && n < ACCURACY)
        return true;
    return false;
}

int lineFunction(double b, double c, double *x1) {
    if (isZero(b)) {

        return (isZero(c)) ? SS_INF_ROOTS : 0;

    } else { /* if (b != 0) */

        *x1 = -c / b;
        return 1;

    }
}

int SolveSquare(double a, double b, double c, double *x1, double *x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isZero(a)) {

        return lineFunction(b, c, x1);

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

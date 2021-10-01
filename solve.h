#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "defines.h"

//!
//! Check is number a zero
//!
//! @param [in] n double number
//!
//! @return is n at a distance of 1e-9 about zero
//!
bool isZero(double n);

//!
//! Solves line equation bx + c = 0
//!
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the root
//!
int lineFunction(double b, double c, double *x1);

//!
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
//!
int SolveSquare(double a, double b, double c, double *x1, double *x2);

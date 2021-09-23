#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

#include "defines.h"

//!
//! Structure of a square equation ax2 + bx + c = 0 with roots x1 and x2
//!
//! @param A a-coefficient
//! @param B b-coefficient
//! @param C c-coefficient
//! @param nRoots number of solutions
//! @param x1 the 1st root
//! @param x2 the 2nd root
//!
struct SquarePolynomial {
    double A;
    double B;
    double C;
    size_t nRoots;
    double x1;
    double x2;
};

//!
//! Check is a equal b
//!
//! @param [in] a 1st number
//! @param [in] b 2nd number
//!
bool isEqual(double a, double b);

//!
//! Function add SquarePolynomial tests to global array tests
//!
void TestLaunch();


//!
//! Changes the values of variables to test the response
//!
//! @param [out] a Pointer to the a-coefficient
//! @param [out] b Pointer to the b-coefficient
//! @param [out] c Pointer to the c-coefficient
//! @param [in] n Number of test
//!
void TestGet(double *a, double *b, double *c, int n);

//!
//! Check the answer
//!
//! @param [in] nRoots Number of roots
//! @param [in] x1 1st answer
//! @param [in] x2 2nd answer
//! @param [in] n Number of test
//!
void TestCheck(int nRoots, double x1, double x2, int n);

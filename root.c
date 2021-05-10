#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "flist.h"
extern int iters;

double root(double(*f)(double), double(*g)(double), double a, double b, double eps) {
    double t = b, f0 = f(a) - g(a), f1;
    iters = 0;
    do {
        iters++;
        f1 = f(t) - g(t);
        t = t - f1 / (f1 - f0) * (t - a);
    } while (fabs(f1) >= eps / 2);
    return t;
}

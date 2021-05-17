#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "flist.h"
extern int iters;

double F(double(*f)(double), double (*g)(double), double x) {
    return f(x) - g(x);
}

double root(double(*f)(double), double(*g)(double), double a, double b, double eps) {

    if (((F(f, g, a) > 0) && (F(f, g, (a+b)/2) > (F(f, g, a) + F(f, g, b))/2)) ||
        ((F(f, g, a) < 0) && (F(f, g, (a+b)/2) < (F(f, g, a) + F(f, g, b))/2))) {
        double t = a, f0 = f(b) - g(b), f1;
        iters = 0;
        do {
            iters++;
            f1 = F(f, g, t);
            t = t - f1 / (f1 - f0) * (t - b);
        } while (fabs(f1) >= eps / 2);
        return t;
    }
    else {
        double t = b, f0 = f(a) - g(a), f1;
        iters = 0;
        do {
            iters++;
            f1 = F(f, g, t);
            t = t - f1 / (f1 - f0) * (t - a);
        } while (fabs(f1) >= eps / 2);
        return t;
    }
}

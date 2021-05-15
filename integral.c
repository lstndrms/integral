#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "flist.h"

double integral(double(*f)(double), double a, double b, double eps) {
    double h = sqrt(sqrt(eps));
    double n = (b - a) / h;
    double I_h, I_2h;
    I_h = I_2h = 0;
    n = ceil(n);

    while (((int)n) % 4 != 0) {
        n++;
    }
    do {
        h = (b - a) / n;
        I_h = I_2h;
        I_2h = f(a) + f(b);
        for (int i = 1;i < (int)n;i++) {
            if (i & 1)
                I_2h += 4.0 * f(a + h * i);
            else
                I_2h += 2.0 * f(a + h * i);
        }

        I_2h = I_2h * h / 3;
        n *= 2;
    } while (fabs(I_h - I_2h) / 15 >= eps);
    return I_h;
}

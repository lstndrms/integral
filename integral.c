#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "flist.h"

double integral(double(*f)(double), double a, double b, double eps) {
    int n = 10;
    double I_h, I_2h;
    I_h = I_2h = 0;
    double sum_o = 0.0, sum_e = 0.0, sum_old = 0.0;
    double h = (b - a) / n;
    for (int i = 1;i < n;i++) {
        if (i & 1)
            sum_o += f(a + h * i);
        else
            sum_e += f(a + h * i);
    }
    sum_old = sum_o + sum_e;
    I_h = (f(a) + 4 * sum_o + 2 * sum_e + f(b)) * h / 3;
    I_2h = I_h;
    n *= 2;
    do {
        h = (b - a) / n;
        I_h = I_2h;
        sum_e = sum_old;
        sum_o = 0.0;
        for (int i = 1;i < n;i+=2) {
            sum_o += f(a + h * i);
        }

        I_2h = (f(a) + 4 * sum_o + 2 * sum_e + f(b)) * h / 3;
        sum_old = sum_o + sum_e;
        n *= 2;
    } while (fabs(I_h - I_2h) / 15 >= eps);
    return I_2h;
}

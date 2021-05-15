#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "flist.h"


double at1(double x) {
    return x * x / 10 - x + 1;
}

double at2(double x) {
    return cos(x);
}

double at3(double x) {
    return x * x;
}

double at4(double x) {
    return 1/(x * x * x);
}

double at5(double x) {
    return sin(3 * x);
}

double at6(double x) {
    return log(x) / 3;
}



double it1(double x) {
    return x * x * sin(x) * sin(x) * sin(x);
}


double it2(double x) {
    return x * sqrt(x * x + 1);
}

double it3(double x) {
    return log(x)/(x*x);
}

double t1(double x) {
    return x * x + 3 * x + 1;
}
double t2(double x) {
    return 1/x;
}
double t3(double x) {
    return cos(x);
}

void atest(void) {
    printf("Root test 1\n");
    double x = root(at1, at2, 6.068, 10.0, 1e-5);
    printf("function: x^2/10-x+1-cosx=0, EPS: 0.00001\nroot: %.5lf; real root: 8.28697\n", x);
    printf("Root test 1: ");
    if (fabs(x - 8.28697) < 1e-5)
        printf("OK\n\n");
    else
        printf("WA\n\n");

    printf("Root test 2\n");
    x = root(at3, at4, 0.5, 1.5, 1e-4);
    printf("function: x^2-1/x^3=0, EPS: 0.0001\nroot: %.4lf; real root: 1.0000\n", x);
    printf("Root test 2: ");
    if (fabs(x - 1.0000) < 1e-4)
        printf("OK\n\n");
    else
        printf("WA\n\n");

    printf("Root test 3\n");
    x = root(at5, at6, 2, 2.5, 1e-3);
    printf("function: sin(3x)-lnx/3=0, EPS: 0.001\nroot: %.3lf; real root: 2.182\n", x);
    printf("Root test 3: ");
    if (fabs(x - 2.1821) < 1e-3)
        printf("OK\n\n");
    else
        printf("WA\n\n");


    printf("Integral test\n");
    x = integral(it1, 0.0, 1.0, 1e-5);
    printf("function: x^2sin^3x, EPS = 0.00001\n\tintegral[0, 1]: %.5lf; real integral: 0.11395\n", x);
    if (fabs(x - 0.11395) < 1e-5)
        printf("OK\n\n");
    else
        printf("WA\n\n");

    printf("Integral test\n");
    x = integral(it2, 0.5, 1.5, 1e-4);
    printf("function: xsqrt(x^2+1), EPS = 0.0001\n\tintegral[0.5, 1.5]: %.4lf; real integral: 1.4871\n", x);
    if (fabs(x - 1.4871) < 1e-4)
        printf("OK\n\n");
    else
        printf("WA\n\n");

    printf("Integral test\n");
    x = integral(it3, 1.0, 2.7, 1e-3);
    printf("function: log(x)/(x^2), EPS = 0.001\n\tintegral[0, 1]: %.3lf; real integral: 0.262\n", x);
    if (fabs(x - 0.262) < 1e-3)
        printf("OK\n\n");
    else
        printf("WA\n\n");
    return ;
};


void test(char* type, int n, double a, double b, double eps) {
    printf("Test type: \n\t1: root\n\t2: integral\n%s\n", type);
    if (strcmp(type, "1") == 0) {
        printf("Options are: \n\t1: x^2+3x+1=1/x\n\t2: 1/x=cosx\n\t3: cosx=x^2+3x+1\n%d\n", n);
        printf("Interval [%lf, %lf]\n", a, b);
        printf("EPS: %lf\n", eps);
        switch(n) {
            case 1:
                printf("Root: %lf\n", root(t1, t2, a, b, eps));
                break;
            case 2:
                printf("Root: %lf\n", root(t2, t3, a, b, eps));
                break;
            case 3:
                printf("Root: %lf\n", root(t1, t3, a, b, eps));
                break;
            default:
                printf("Error\n");
        }
    }
    else if (strcmp(type, "2") == 0) {
        printf("Options are: \n\t1: x^2+3x+1=1/x\n\t2: 1/x=cosx\n\t3: cosx=x^2+3x+1\n%d\n", n);
        printf("Interval [%lf, %lf]\n", a, b);
        printf("EPS: %lf\n", eps);
        switch(n) {
            case 1:
                printf("Inregral: %lf\n", integral(t1, a, b, eps));
                break;
            case 2:
                printf("Integral: %lf\n", integral(t2, a, b, eps));
                break;
            case 3:
                printf("Integral: %lf\n", integral(t3, a, b, eps));
                break;
            default:
                printf("Error\n");
        }
    }
}

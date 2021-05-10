#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "flist.h"

double t1(double x) {
    return x * x + 3 * x + 1;
}

double t2(double x) {
    return 1/x;
}
double t3(double x) {
    return cos(x);
}

void test(void) {
    int type;
    printf("Test type: \n\t1: root\n\t2: integral\n");
    scanf("%d", &type);
    if (type == 1) {
        int n;
        printf("Options are: \n\t1: x^2+3x+1=1/x\n\t2: 1/x=cosx\n\t3: cosx=x^2+3x+1\n");
        scanf("%d", &n);
        double a, b, eps;
        printf("Interval [a, b]: ");
        scanf("%lf%lf", &a, &b);
        printf("EPS: ");
        scanf("%lf", &eps);
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
    else if (type == 2) {
        int n;
        printf("Options are: \n\t1: f(x)=x^2+3x+1\n\t2: f(x)=1/x\n\t3: f(x)=cosx\n");
        scanf("%d", &n);
        double a, b, eps;
        printf("Interval [a, b]: ");
        scanf("%lf%lf", &a, &b);
        printf("EPS: ");
        scanf("%lf", &eps);
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

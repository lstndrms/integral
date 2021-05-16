#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EPS 1e-5
#include "flist.h"


int iters;


void test(char* type, int n, double a, double b, double eps);
void atest(void);


void help(void) {
    printf("-iters: show number of iterations\n");
    printf("-roots: show all roots\n");
    printf("-test [type{1, 2}, number of func{1, 2, 3}, a, b ,eps]: call test\n");
    printf("Test type: \n\t1: root\n\t2: integral\n");
    printf("Options are: \n\t1: x^2+3x+1=1/x\n\t2: 1/x=cosx\n\t3: cosx=x^2+3x+1\n");
    printf("-allfuncs: show all funcs\n");
    printf("-v: show task\n");
    printf("-at: start automatic test\n");
};


void v(void) {
    printf("Task:\n\tfind curvelinear area\n\tfuncs: f1(x) = 3/((x-1)^2+1); f2(x) = sqrt(x+0.5); f3(x) = exp(-x)\nMethods:\n\tSimpson's rule\n\tSecant method\n");
}

int main(int argc, char** argv) {
    int showroots = 0, showiters = 0, showall = 0;
    if (argc) {
        int d[] = {0, 0, 0};
        for (int i = 0; i < argc;i++) {
            if (strcmp("-iters", argv[i]) == 0) {
                showiters = 1;
                d[0] = 1;
            }
            if (strcmp("-roots", argv[i]) == 0) {
                showroots = 1;
                d[1] = 1;
            }
            if (strcmp("-help", argv[i]) == 0) {
                help();
                return 0;
            }
            if (strcmp("-test", argv[i]) == 0) {
                if (i + 5 < argc) {
                    int n = 0;
                    for (int j = 0;j < (int)strlen(argv[i+2]);j++) {
                        if (argv[i+2][j] > '9' || argv[i+2][j] < '0') {
                            printf("Error: n is NaN\n");
                            return 0;
                        }
                        n = 10 * n + argv[i+2][j] - '0';
                    }
                    for (int j = 0;j < (int)strlen(argv[i+3]);j++) {
                        if ((argv[i+3][j] > '9' || argv[i+3][j] < '0') & (argv[i+3][j] != '.')) {
                            printf("Error: a is NaN\n");
                            return 0;
                        }
                    }
                    for (int j = 0;j < (int)strlen(argv[i+4]);j++) {
                        if ((argv[i+4][j] > '9' || argv[i+4][j] < '0') & (argv[i+4][j] != '.')) {
                            printf("Error: b is NaN\n");
                            return 0;
                        }
                    }
                    for (int j = 0;j < (int)strlen(argv[i+5]);j++) {
                        if ((argv[i+5][j] > '9' || argv[i+5][j] < '0') & (argv[i+5][j] != '.')) {
                            printf("Error: eps is NaN\n");
                            return 0;
                        }
                    }
                    if (n < 1 || n > 3) {
                        printf("Error: wrong n value\n");
                        return 0;
                    }
                    char *end;
                    double a = strtod(argv[i+3], &end);
                    double b = strtod(argv[i+4], &end);
                    double eps = strtod(argv[i+5], &end);
                    if (eps <= 0) {
                        printf("Error: eps is NaN\n");
                        return 0;
                    }
                    test(argv[i+1], n, a, b, eps);
                    return 0;
                }
                else
                    printf("Error: not enough arguments\n");
                return 0;
            }
            if (strcmp("-allfuncs", argv[i]) == 0) {
                showall = 1;
            }
            if (strcmp("-v", argv[i]) == 0) {
                if (!d[2]) {
                    v();
                    d[2] = 1;
                }
            }
            if (strcmp("-at", argv[i]) == 0) {
                atest();
                return 0;
            }
        }
    }

    if (showall) {
        printf("Funcs:\n\tf1(x) = 3/((x-1)^2+1)\n\tf2(x) = sqrt(x+0.5)\n\tf3(x) = exp(-x)\n");
    }

    double x1 = root(f1, f2, 1.6, 4, EPS);
    if (showiters) printf("Iterations f1 = f2:   %d\n", iters);

    double x2 = root(f2, f3, 0, 1, EPS);
    if (showiters) printf("Iterations f2 = f3:   %d\n", iters);

    double x3 = root(f1, f3, -1, 1, EPS);
    if (showiters) printf("Iterations f1 = f3:   %d\n", iters);

    if (showroots) printf("Roots: f1=f2: %lf; f2=f3: %lf; f1=f3: %lf\n", x1, x2, x3);

    double ans = integral(f1, x3, x1, EPS) - integral(f3, x3, x2, EPS) - integral(f2, x2, x1, EPS);
    printf("Square: %lf\n", ans);

    return 0;
}

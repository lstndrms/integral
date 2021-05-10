#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EPS 1e-5
#include "flist.h"


int iters;


void test(void);

void help(void) {
    printf("-iters: show number of iterations\n");
    printf("-roots: show all roots\n");
    printf("-test: call test\n");
    printf("-allfuncs: show all funcs\n");
};


int main(int argc, char** argv) {
    int showroots = 0, showiters = 0, showall = 0;
    if (argc) {
        for (int i = 0; i < argc;i++) {
            if (strcmp("-iters", argv[i]) == 0) {
                showiters = 1;
            }
            if (strcmp("-roots", argv[i]) == 0) {
                showroots = 1;
            }
            if (strcmp("-help", argv[i]) == 0) {
                help();
                return 0;
            }
            if (strcmp("-test", argv[i]) == 0) {
                test();
                return 0;
            }
            if (strcmp("-allfuncs", argv[i]) == 0) {
                showall = 1;
            }
        }
    }

    if (showall) {
        printf("Funcs:\n\tf1(x) = 3/((x-1)^2+1)\n\tf2(x) = sqrt(x+0.5)\n\tf3(x) = exp(-x)\n");
    }

    double x1 = root(f1, f2, 1, 4, EPS);
    if (showiters) printf("Iterations f1 = f2:   %d\n", iters);

    double x2 = root(f2, f3, 0, 1, EPS);
    if (showiters) printf("Iterations f2 = f3:   %d\n", iters);

    double x3 = root(f1, f3, -1, 4, EPS);
    if (showiters) printf("Iterations f1 = f3:   %d\n", iters);

    if (showroots) printf("Roots: f1=f2: %lf; f2=f3: %lf; f1=f3: %lf\n", x1, x2, x3);

    double ans = integral(f1, x3, x1, EPS) - integral(f3, x3, x2, EPS) - integral(f2, x2, x1, EPS);
    printf("Square: %lf\n", ans);

    return 0;
}

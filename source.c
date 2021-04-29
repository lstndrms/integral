#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.001


double test_f(double x) {
    return x;
}

double test_f1(double x) {
    return -x + 10;
}

double f1(double x) {
    return 3.0/((x-1)*(x-1) + 1);
}

double f2(double x) {
    return sqrt(x + 0.5);
}

double f3(double x) {
    return exp(-x);
}

double F(double x, double (*f)(double), double(*g)(double)) {
    return f(x) - g(x);
}

double root(double(*f)(double), double(*g)(double), double a, double b, double eps) {
    double t = b, f0 = F(a, f, g), f1;
    int i = 0;
    do {
        i++;
        f1 = F(t, f, g);
        t = t - f1 / (f1 - f0) * (t - a);
    } while (fabs(f1) > eps && i < 10000);
    return t;
}

double integral(double(*f)(double), double a, double b, double eps) {
    double h = sqrt(sqrt(eps));
    double n = (b - a) / h;
    double I_h, I_2h;
    n = ceil(n);

    while (((int)n) % 4 != 0) {//округлим до ближайшего кратного 4 т.к. считаем I с шагом 2h
        n++;
    }
    while (1) {
        h = (b - a) / n;

        double* d = (double*)calloc(n + 1, sizeof(double));//значения f(x) с шагом h на [a, b]
        d[0] = f(a);
        d[(int)n] = f(b);
        for (int i = 1;i < (int)n;i++) {
            d[i] = f(a + h * i);
        }

        I_h = f(a) + f(b);
        I_2h = I_h;
        for (int i = 1;i < (int)n;i++) {
            if (i & 1)
                I_h += 4.0 * d[i];
            else
                I_h += 2.0 * d[i];
        }
        for (int i = 1; i < (int)n / 2;i++) {
            if (i & 1)
                I_2h += 4.0 * d[2 * i];
            else
                I_2h += 2.0 * d[2 * i];
        }
        free(d);
        if (fabs(I_h * h / 3 - 2 * I_2h * h / 3) / 15 < eps || n > 1e6) {//оценка погрешности с помощью правила Рунге
            break;
        }
        n *= 2;//если точность не достигнута уменьшим шаг h в 2 раза
    }
    return I_h * h / 3;
}

signed main(void) {
    //EXAMPLE
    printf("f(x)=x\ng(x)=-x+10\na=0;b=10\nroot: ");
    double a, b;
    a = 0, b = 10;
    printf("%lf\n", root(test_f, test_f1, a, b, EPS));
    printf("integral f(x): %lf\n", integral(test_f, a, b, EPS));
    //EOF EXAMPLE

    ///*
    //scanf("%lf%lf", &a, &b);
    a = 1, b = 4;
    double x1 = root(f1, f2, a, b, EPS);

    //scanf("%lf%lf", &a, &b);
    a = 0, b = 1;
    double x2 = root(f2, f3, a, b, EPS);

    //scanf("%lf%lf", &a, &b);
    a = -1, b = 4;
    double x3 = root(f1, f3, a, b, EPS);



    printf("%lf %lf %lf\n", x1, x2, x3);
    double ans = integral(f1, x3, x1, EPS) - integral(f3, x3, x2, EPS) - integral(f2, x2, x1, EPS);
    printf("%lf", ans);
    //123 213 312 132 231 321
    //*/

    return 0;
}


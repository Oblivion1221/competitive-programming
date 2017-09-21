#include <stdio.h>
#include <math.h>
#define MIN 1e-4
#define PI (acos(-1.0))

double fgcd(double m, double n)
{
    double t;
    while (n > MIN)
    {
        t = fmod(m, n);
        m = n;
        n = t;
    }

    return m;
}

double dist(double a[], double b[])
{
    double dx, dy, d;
    dx = pow(a[0] - b[0], 2);
    dy = pow(a[1] - b[1], 2);
    d = sqrt(dy + dx);

    return d;
}

int main()
{
    double a, b, c, s, r, area, ans, A, B, C;
    double Ap[2], Bp[2], Cp[2];
    double n;   // Cannot AC if 'int n' !!!!!!!
    scanf("%lf %lf", &Ap[0], &Ap[1]);
    scanf("%lf %lf", &Bp[0], &Bp[1]);
    scanf("%lf %lf", &Cp[0], &Cp[1]);
    a = dist(Bp, Cp);
    b = dist(Ap, Cp);
    c = dist(Ap, Bp);
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    r = (a * b * c) / (4 * area);
    A = acos(1 - (a * a) / (r * r * 2));
    B = acos(1 - (b * b) / (r * r * 2));
    C = 2 * PI - A - B;
    n = (2 * PI) / fgcd(A, fgcd(B, C));
    ans = n / 2 * r * r * sin(fgcd(A, fgcd(B, C)));
    printf("%.8lf\n", ans);

    return 0;
}

#include <stdio.h>
#include <math.h>
#define f(x) exp(cos(x)) - sin(x)

int main()
{
    int n, i = 1;
    float f0, f1, x1, x2, e, x0, f2;
INPUT:
    printf("Enter two initial guesses x0 and x1: ");
    scanf("%f%f", &x0, &x1);
    f1 = f(x1);
    f0 = f(x0);
    if (f1 == f0)
    {
        printf("Invalid Guesses!!\n");
        goto INPUT;
    }
    printf("Enter max no of tolorence error: ");
    scanf("%f", &e);
    printf("Enter max no of iterations: ");
    scanf("%d", &n);
    printf("\n_________________________________________________________________________________\n");
    printf("|Iteration\t|\tx0\t|\tx1\t|\tx2\t|\tf(x2)\t|\n");
    printf("_________________________________________________________________________________\n");
    do
    {
        if (f0 == f1)
        {
            printf("Mathematical error!!");
            return -1;
        }
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);
        printf("|%d\t\t|%f\t|%f\t|%f\t|%f\t|\n", i, x0, x1, x2, f2);
        i++;
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        if (i > n)
        {
            printf("Solution doesn't diverge\n");
            return -1;
        }
    } while (fabs(f2) > e);
    printf("_________________________________________________________________________________\n");
    printf("The root is: %.8f", x2);
    return 0;
}
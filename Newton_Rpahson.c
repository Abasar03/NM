#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (x*exp(-x)) - cos(x)
#define df(x) -x*exp(-x) + exp(-x) + sin(x)

int main(void)
{
    float xo, e, dfo, fo, x1, f1;

    int N, i = 1;

    printf("\nEnter value of initial guess: \n");
    scanf("%f", &xo);
    printf("\nEnter value of predefined error: \n");
    scanf("%f", &e);
    printf("\nEnter maximum number of iterations: \n");
    scanf("%d", &N);

    printf("\n___________________________________________________________________________\n");
    printf("\n Iterations \t xo \t\t f(xo) \t\t x1 \t\t f(x1) \n");
    printf("\n___________________________________________________________________________\n");

    do
    {
        fo = f(xo);
        dfo = df(xo);
        if(dfo == 0)
        {
            printf("\nMathematical error\n");
            exit(0);
        }
        x1 = xo - fo/dfo;
        f1 = f(x1);
        printf("\n %10d \t %0.8f \t %0.8f \t %0.8f \t %0.8f \n", i, xo, fo, x1, f1);

        xo = x1;
        i=i+1;
        if(i>N)
        {
            printf("\nThe solution does not converge\n");
            exit(0);
        }
    }while(fabs(f1)>e);

    printf("\n___________________________________________________________________________\n");
    printf("\nRequired root is: %0.8f\n", x1);
    return 0;

}
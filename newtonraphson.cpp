#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

#define f(x)  3*x + sin(x) - exp(x)
#define df(x) 3 + cos(x) - exp(x)


int main(void)
{
    float xo, e, fo, dfo, x1, f1;
    int N, i = 1;

    cout << setprecision(7) << fixed;

    // Ask for input 
    cout << "Enter intial guess: ";
    cin >> xo;
    cout << "Enter error: ";
    cin >> e;
    cout << "Enter maximum iterations: ";
    cin >> N;

    // Print the table
    cout << "____________________________________________________________________" << endl;
    cout << "Iterations" << setw(15) << "xo" << setw(15) << "x1" << setw(15) << "f(x)" << endl;
    cout << "____________________________________________________________________" << endl;


    do{
        fo = f(xo);
        dfo = df(xo);
        if(dfo == 0)
        {
            cout << "Mathematical error";
            exit(0);
        }
        x1 = xo - fo / dfo;
        f1 = f(x1);
        cout << i << setw(28) << xo << setw(15) << x1 << setw(15) << f1 << endl;
        xo = x1;
        i++;

        if(i > N)
        {
            cout << "Solution does not converge" << endl;
        }


    }while(fabs(f1) > e);

    cout << "____________________________________________________________________" << endl;

    cout << "Required root is: " <<  x1;

    return 0;
}
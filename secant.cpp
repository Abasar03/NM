#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

#define f(x) 3 * x + sin(x) - exp(x)

using namespace std;

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int count = 1, N;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(6) << fixed;

    /* Inputs */
    cout << "Enter first guess: ";
    cin >> x0;
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum iteration: ";
    cin >> N;

    /* Implementing Secant Method */
    cout << "\n--------------------------------------------------------------------------------------------------\n";
    cout << "Iterations\tx0\t\t\tx1\t\t\tx2\t\t\tf(x2)" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            cout << "Mathematical Error.";
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        cout << count << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << f2 << endl;

        x0 = x1;
        x1 = x2;

        count = count + 1;

        if (count > N)
        {
            cout << "Not Convergent.";
            exit(0);
        }
    } while (fabs(f2) > e);

    cout << "\nRequired root is: " << x2;

    return 0;
}
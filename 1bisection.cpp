#include <iostream>
#include <cmath>
using namespace std;

inline double funcVal(double val)
{
    return (val * sin(val) + cos(val));
    //return exp(val) - 3 * val;
    //return log10(val) - cos(val);
    //return 2 * val * val * val + 4 * val * val - 4 * val - 6;
}

int main()
{
    double a, b, error, c, fa, fb, fc, count = 1;
    cout << "For val * sin(val) + cos(val)" << endl;
    cin >> a >> b >> error;
    //Determining positive and negative value in the given interval
    fa = funcVal(a);
    fb = funcVal(b);

    if (fa > fb)
    {
        swap(a, b);
        swap(fa, fb);
    }
    try
    {
        if (fa * fb > 0)
            throw 0;
        else
        {
            cout << "Iteration\ta\t\tb\t\tc\t\tf(c)" << endl;

            do
            {
                c = (a + b) / 2; //Bisection
                fc = funcVal(c);
                printf("%.0f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", count, a, b, c, fc);

                //Deciding which interval to replace
                if (fc * fa > 0)
                    a = c;
                else
                    b = c;
                count++;
            } while (abs(fc) > error);
            printf("\nThe root is %.4f", c);
        }
    }
    catch (int num)
    {
        std::cerr << "Exception: Product of f(a) and f(b) greater than zero" << '\n';
    }
}

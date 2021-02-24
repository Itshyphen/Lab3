#include <iostream>
#include <cmath>

using namespace std;

//Obtaining value from a differentiated function
float diffFunctionValue(float x)
{
    return 3 + sin(x);
    //return 3 * x * x + 2 * x + 1;
    //return cos(x) - sin(x) + exp(x);
}

//Obtaining value from a function
float functionValue(float x)
{
    return 3 * x - cos(x) - 1;
    //return x * x * x + x * x + x + 7;
    //return sin(x) + cos(x) + exp(x) - 8;
}

//Main Function
int main()
{
    float x0, error, g, f, g1, f1, x1, count = 1, n;
    cout << "For 3x - cos(x) - 1" << endl;
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerable error: ";
    cin >> error;
    cout << "Enter maximum iteration: ";
    cin >> n;
    try
    {
        printf("\ni\tXi\t\tf(Xi)\t\tf'(Xi)\t\tXi+1\t\tError\n");
        do
        {
            g = diffFunctionValue(x0);
            f = functionValue(x0);
            if (g == 0)
            {
                throw 0;
            }

            x1 = x0 - f / g;
            printf("%.f\t%f\t%f\t%f\t%f\t%f\n", count, x0, functionValue(x0), diffFunctionValue(x0), x1, x1 - x0);
            x0 = x1;

            count++;

            if (count > n)
            {
                throw 1;
            }

            f1 = functionValue(x1);
        } while (abs(f1) > error);
        printf("%.f\t%f\t%f\t%f\t%f\t%f\n", count, x0, functionValue(x0), diffFunctionValue(x0), x1, x1 - x0);
        cout << endl
             << "Root is: " << x1;
    }
    catch (int num)
    {
        if (num == 0)
            std::cerr << "Exception: Derivative is zero." << '\n';
        else
            std::cerr << "Exception: Not Convergent." << '\n';
    }
}

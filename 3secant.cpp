#include <iostream>
#include <cmath>
using namespace std;

//Function specified by the question
float findValue(float x)
{
    return x * log10(x) - 1.2;
    //return x * x * x - 3 * x * x + 2 * x - 2;
    //return x * x + tan(x) + exp(x);
}

//Finds root of our function
void findRoot(float a, float b, float error)
{

    try
    {
        float c, fa, fb, fc;
        int count = 1;
        printf("i\ta\t\tb\t\tc\t\tf(c)\n");

        //Main Algorithm
        do
        {
            fa = findValue(a);
            fb = findValue(b);
            if (fa * fb > 0)
                throw 0;
            if (fa == fb)
            {
                c = 0;
                break;
            }
            c = (a * fb - b * fa) / (fb - fa);
            fc = findValue(c);
            printf("%d\t%f\t%f\t%f\t%f\n", count, a, b, c, fc);
            a = b;
            b = c;
            count++;
        } while (abs(fc) > error);
        cout << "Root : " << c << endl;
    }
    catch (int n)
    {
        cout << "Exception: Real root doesn't exist" << endl;
    }
}

//Main Function
int main()
{
    cout << "For  xlog10(x) - 1.2" << endl;
    float a, b, error;
    cin >> a >> b >> error;
    findRoot(a, b, error);
}

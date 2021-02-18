
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    float data[2][100], a = 0, b = 0, sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;
    int i, j, n;
    cout << "Enter number of data: ";
    cin >> n;
    cout << "Enter data:" << endl
         << "x , y" << endl;
    //Reading the data
    for (i = 0; i < n; i++)
    {
        scanf("%f, %f", &data[0][i], &data[1][i]);
    }

    // Implementing curve fitting for linear form
    for (j = 0; j < n; j++)
    {

        sumX += data[0][j];
        sumX2 += data[0][j] * data[0][j];
        sumY += data[1][j];
        sumXY += data[0][j] * data[1][j];
    }
    //Calculate the value of a and b
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
    //Hence display the result
    cout << "Hence, a = " << a << "and b = " << b << endl;
    if (b < 0)
        cout << "Equation of best fit is: y = " << a << " - " << -b << "x" << endl;
    else
        cout << "Equation of best fit is: y = " << a << " + " << b << "x" << endl;

    return 0;
}


#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float data[10][100], mat[100][100], a = 0, b = 0, sumX = 0, sumX2 = 0, sumY[100], sumXY[100], res[10];
    int i, j, k, n, d, D;

    // cout << setprecision(3) << fixed;

    cout << "Enter number of data: ";
    cin >> n;
    cout << "Enter data:" << endl
         << "x , y" << endl;

    //Reading the data
    for (i = 0; i < n; i++)
    {
        scanf("%f, %f", &data[1][i], &data[0][i]);
    }

    //degree of the required equation
    cout << "Enter degree of equation to be fitted on: (less than n)";
    cin >> d;
    D = d + 1;

    for (i = 0; i <= 2 * d; i++)
    {
        for (j = 0; j <= n; j++)
        {
            data[i][n] = 0;
            sumXY[i] = 0;
            sumY[i] = 0;
        }
    }

    // Implementing curve fitting for polynomial form
    for (i = 0; i <= 2 * d; i++)
    {
        for (j = 0; j < n; j++)
        {
            data[i][n] += pow(data[1][j], i); //i=1 for x, 2 for x*x and so on
            // cout<<data[i][n];
            sumXY[i] += pow(data[1][j], i) * data[0][j];
        }
    }

    for (i = 0; i <= d; i++)
    {
        for (j = 0; j <= d; j++)
        {
            mat[i][j] = data[i + j][n];
            mat[i][d + 1] = sumXY[i];
        }
    }

    for (i = 0; i < D; i++)
    {
        for (j = i + 1; j < D; j++)
        {
            if (abs(mat[i][i]) < abs(mat[j][i]))
            {
                for (k = 0; k < D + 1; k++)
                {
                    /* swapping mat[i][k] and mat[j][k] */
                    mat[i][k] = mat[i][k] + mat[j][k];
                    mat[j][k] = mat[i][k] - mat[j][k];
                    mat[i][k] = mat[i][k] - mat[j][k];
                }
            }
        }
    }

    /* performing Gaussian elimination */
    for (i = 0; i < D - 1; i++)
    {
        for (j = i + 1; j < D; j++)
        {
            float f = mat[j][i] / mat[i][i];
            for (k = 0; k < D + 1; k++)
            {
                mat[j][k] = mat[j][k] - f * mat[i][k];
            }
        }
    }

    // Backward substitution for discovering values of unknowns 
    for (i = D - 1; i >= 0; i--)
    {
        res[i] = mat[i][D];

        for (j = i + 1; j < D; j++)
        {
            if (i != j)
            {
                res[i] = res[i] - mat[i][j] * res[j];
            }
        }
        res[i] = res[i] / mat[i][i];
    }

    cout << "The equation of bestfit is: y=";
    for (i = 0; i < D; i++)
    {
        cout << res[i] << "x^(" << i << ")+";
    }
    cout << "\b";

    return 0;
}

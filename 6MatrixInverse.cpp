//Write a program to find the inverse of a given square matrix of any order using the Gauss-Jordan Method.  Verify your program with second, third, fourth, and fifth order matrices.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    float elements;
    cout << "\nEnter order of matrix: ";
    cin >> n;
    vector<float> column;
    vector<vector<float>> rows;

    //Entering coefficients of matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> elements;
            while (i == j && elements == 0)
            {
                cout << "You cannot enter 0 for A" << i + 1 << j + 1 << ". Enter another value: ";
                cin >> elements;
            }
            column.push_back(elements);
        }

        for (int j = 0; j < n; j++)
        {
            (i == j ? column.push_back(1) : column.push_back(0));
        }
        rows.push_back(column);
        column.clear();
    }

    //Augmented Matrix
    cout << "\nIn Augmented form: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j == n)
                cout << ":\t";
            cout << rows[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Row Operations " << endl;
    try
    {
        //Row Operations on the Matrix
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (rows[j][j] == 0)
                    throw 0;

                float ratio = (rows[i][j] / rows[j][j]);
                for (int k = 0; k < 2 * n; k++)
                {
                    if (i != j)
                    {
                        rows[i][k] -= (ratio)*rows[j][k];
                    }
                    if (k == n)
                        cout << ":\t";
                    printf("%.2f\t", rows[i][k]);
                }
                cout << endl;
            }
            cout << endl;
        }

        //Obtaining Unknown values
        cout << "The inverse of given matrix is" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                rows[i][j] /= rows[i][i];
                printf("%.3f\t", rows[i][j]);
            }
            cout << endl;
        }
        rows.clear();
        cout << endl;
    }
    catch (int n)
    {
        cout << "Exception: Inverse doesn't exist" << endl;
        rows.clear();
    }
}

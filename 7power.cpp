#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

const int THRES = 100;

int main()
{
    int n, count=0;
    float error, Dmax = 0, lamda = 0;
    cout << "Enter the order of matrix: ";
    cin >> n;

    cout<<setprecision(4)<<fixed;

    cout << "Enter tolerable error: ";
    cin >> error;

    float A[n][n], X[n], Z[n], D[n];

    cout << "Enter the matrix element: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                 cout<< "A[" << i << "][" << j << "]=";
            cin >> A[i][j];
        }
    }

    cout << "Let's now guess the eigen vectors: " << endl;
    for (int j = 0; j < n; j++)
    {
       
             cout<< "X[" << j << "]=";
        cin >> X[j];
    }

    cout<<"POWER METHOD:"<<endl;
    cout<<setw(20)<<"Step"<<setw(20)<<"Eigen value"<<setw(40)<<"Eigen vector"<<setw(20)<<"error"<<endl;

bool state=1;
    while (count <= THRES && state==1)
    {
        for (int i = 0; i < n; i++)
        {
            Z[i] = 0;
            for (int j = 0; j < n; j++)
            {
                Z[i] = Z[i] + (A[i][j] * X[j]);
            }
        }
    

    //find the largest value in Z
    lamda=Z[0];
    for (int i = 0; i < n; i++)
    {
        if (Z[i] > lamda)
            lamda = Z[i];
    }

    //find the corresponding eigen vector
    for (int i = 0; i < n; i++)
    {
        Z[i] = Z[i] / lamda;
    }

    //Compute the error between Z and X
    for (int i = 0; i < n; i++)
    {
        D[i] = fabs(Z[i] - X[i]);
    }

    //Replace X by Z
    for (int i = 0; i < n; i++)
    {
        X[i] = Z[i];
    }

    //Compute the largest error in D
    Dmax=D[0];
    for (int i = 0; i < n; i++)
    {
        if (D[i] > Dmax)
            Dmax = D[i];
    }
    cout<<setw(20)<<count<<setw(20)<<lamda<<setw(40)<< "[" ;
    for (int i = 0; i < n; i++)
    {
        cout<<Z[i]<<"  ";
    }
    cout<<"]"<<setw(20)<<Dmax<<endl;
    count++;
    if(Dmax<=error) state=0;
    }

    cout<<"The dominant eigen value is "<<lamda<<" and corresponding eigen vector is [";
     for (int i = 0; i < n; i++)
    {
        cout<<X[i]<<"   ";
    }
    cout<<"]"<<endl;

    return 0;
}
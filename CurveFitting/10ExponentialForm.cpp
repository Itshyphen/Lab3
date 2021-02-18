
#include <iostream>
#include <cstdio>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    float data[2][100], a = 0, b = 0,A,B, sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0,x,y,X,Y;
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

    cout<<setw(20)<<"X=x"<<setw(20)<<"y"<<setw(20)<<"Y=logy"<<setw(20)<<"XY"<<setw(20)<<"X*X"<<endl;

 for (i = 0; i < n; i++)
    {
        X=data[0][i];
        y=data[1][i];
        Y=log(y);
        cout<<setw(20)<<X<<setw(20)<<y<<setw(20)<<Y<<setw(20)<<X*Y<<setw(20)<<X*X<<endl; 
        sumX += X;
        sumX2 += X * X;
        sumY += Y;
        sumXY += X * Y;  
    }
    cout<<"__________________________________________________________________________________________________"<<endl;
    cout<<setw(20)<<sumX<<setw(20)<<"---"<<setw(20)<<sumY<<setw(20)<<sumXY<<setw(20)<<sumX2<<endl; 

    //Calculate the value of a and b
    B = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    A = (sumY - B * sumX) / n;

    //now thge value of a and b
    a=exp(A);
    b=B;

    //Hence display the result
    cout << "Hence, a = " << a << "and b = " << b << endl;
    cout << "Equation of best fit is: y = " << a << " e^( " << b << "x)"<<endl;

    return 0;
}
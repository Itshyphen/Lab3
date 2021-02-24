// #include<iostream>
// #include<cmath>

// //given function
// inline float f(float x) {return (x*x*x)+9*x-6;}

// using namespace std;
// int main()
// {
//  float a, b, sum=0, h;
//  int i, n;

//  cout<<"Enter lower limit of sum: ";
//  cin>>a;
//  cout<<"Enter upper limit of sum: ";
//  cin>>b;
//  cout<<"Enter number of strips: ";
//  cin>>n;

// //finding stepsize
//  h = (b - a)/n;

//  sum = f(a) + f(b);

//  for(i=1; i<= n-1; i++)
//  {
//   sum = sum + 2 * (f(a + i*h));
//  }

//  sum = sum * h/2;

//  cout<< endl<<"Required value of sum is: "<< sum;

//  return 0;
// }

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    float x[100], y[100], sum = 0, h;
    int i, j, n;
    cout << "Enter number of discrete data for function y=f(x): ";
    cin >> n;
    cout << "Enter data:" << endl
         << "x , y" << endl;
    for (i = 1; i <= n; i++)
    {
        scanf("%f, %f", &x[i], &y[i]);
    }

    //Calculate Stepsize
    h = x[2] - x[1];

    sum = y[1] + y[n];

    for (i = 2; i <= n - 1; i++)
    {
        sum = sum + 2 * y[i];
    }

    sum = sum * h / 2;

    cout << endl
         << "Required value of area under the curve y=f(x) is: " << sum;

    return 0;
}

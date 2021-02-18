#include<iostream>
#include<cmath>

//given function
inline float f(float x) {return (x*x*x)+9*x-6;}

using namespace std;
int main()
{
 float a, b, sum=0, h;
 int i, n;

 cout<<"Enter lower limit of sum: ";
 cin>>a;
 cout<<"Enter upper limit of sum: ";
 cin>>b;
 cout<<"Enter number of strips: ";
 cin>>n;

//finding stepsize
 h = (b - a)/n;

 sum = f(a) + f(b);

 for(i=1; i<= n-1; i++)
 {
  sum = sum + 2 * (f(a + i*h));
 }

 sum = sum * h/2;

 cout<< endl<<"Required value of sum is: "<< sum;

 return 0;
}